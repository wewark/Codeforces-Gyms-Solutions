// 2018 German Collegiate Programming Contest (GCPC 18)
// 102021E

#include <bits/stdc++.h>
#include <ext/hash_set>
#include <ext/numeric>

using namespace __gnu_cxx;
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;
using vb = vector<bool>;
using vs = vector<string>;
const int MOD = int(1e9 + 7);
const long double EPS = 1e-4;
const double PI = 3.1415926535897932384626433;
const ll INF = ll(1e9);
int di[] = {0, 0, 0, 1, -1, 1, -1, 1, -1};
int dj[] = {0, 1, -1, 0, 0, 1, -1, -1, 1};
#define all(x) x.begin(),x.end()

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

bool isprime(int n) {
	if (n == 1) return false;
	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0)
			return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int t; cin >> t;
	while (t--) {
		string sa, sb; cin >> sa >> sb;

		if (sa == sb) {
			cout << "2 2" << endl;
			continue;
		}

		int m1 = 0, m2 = 0;
		if (sa.find('.') != string::npos)
			m1 = sa.length() - sa.find('.') - 1;
		if (sb.find('.') != string::npos)
			m2 = sb.length() - sb.find('.') - 1;

		while (m1 < m2)
			sa.push_back('0'), m1++;
		while (m2 < m1)
			sb.push_back('0'), m2++;

		if (sa.find('.') != string::npos)
			sa.erase(sa.begin() + sa.find('.'));
		if (sb.find('.') != string::npos)
			sb.erase(sb.begin() + sb.find('.'));

		int a = stoi(sa);
		int b = stoi(sb);
		int g = gcd(a, b);
		a /= g, b /= g;

		if (isprime(a) && isprime(b))
			cout << a << " " << b << endl;
		else
			cout << "impossible" << endl;
	}
}
