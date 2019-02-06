// 2018 German Collegiate Programming Contest (GCPC 18)
// 102021D

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
int di[] = {0, 0, 1, -1};
int dj[] = {1, -1, 0, 0};
#define all(x) x.begin(),x.end()


int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int n; cin >> n;
	vi num(n);
	for (int i = 0; i < n; ++i) {
		cin >> num[i];
	}

	ll a = 0, b = num[0];
	ll s = 0;
	bool flip = true;
	for (int i = 0; i < n - 1; ++i) {
		s = num[i] - s;
		if (flip) {
			a = max(a, s - num[i + 1]);
			b = min(b, s);
		}
		else {
			b = min(b, num[i + 1] - s);
			a = max(a, -s);
		}

		flip = !flip;
	}

	cout << (a <= b ? b - a + 1 : 0) << endl;
}
