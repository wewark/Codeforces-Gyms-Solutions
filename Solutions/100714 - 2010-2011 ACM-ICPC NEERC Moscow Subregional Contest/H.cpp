// 2010-2011 ACM-ICPC NEERC Moscow Subregional Contest
// 100714H

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<bool> vb;
typedef vector<string> vs;
const int di[] = {0, 0, 1, -1};
const int dj[] = {1, -1, 0, 0};
const ll MOD = 1e9 + 7;
const long double EPS = 1e-6;
#define all(x) x.begin(),x.end()
#include <ext/hash_set>
#include <ext/numeric>

ll divLess(int n, int v) {
	ll ret = 0, cv = v;
	while (cv <= n) {
		ret += n / cv;
		cv *= v;
	}
	return ret;
}

map<int, int> primeFactorize(int n) {
	map<int, int> ret;
	while (n % 2 == 0) {
		ret[2]++;
		n /= 2;
	}
	for (int i = 3; i * i <= n; i += 2)
		while (n % i == 0)
			ret[i]++, n /= i;
	if (n > 2) ret[n]++;
	return ret;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

//	ll f = 1;
//	for (ll i = 1; i < 20; ++i) {
//		f *= i;
//		cout << i << " " << f << " ";
//		if (f % (i * i) == 0)
//			cout << "YES"<<endl;
//		else
//			cout << "NO" << endl;
//	}

	int n; cin >> n;
	map<int, int> fact = primeFactorize(n);
	for (auto& i : fact) {
		if (divLess(n - 1, i.first) < i.second) {
			cout << "NO" << endl;
			return 0;
		}
	}

	cout << "YES" << endl;
}