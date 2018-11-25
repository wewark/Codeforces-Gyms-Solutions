// ACM International Collegiate Programming Contest Arabella Collegiate Programming Contest (2018)
// 101972E

#include <bits/stdc++.h>
#include <ext/hash_set>
#include <ext/numeric>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<bool> vb;
typedef vector<string> vs;
const ll MOD = 1e9 + 7;
const long double EPS = 1e-5;
#define all(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define fr first
#define sc second


int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int t = 1; cin >> t;
	while (t--) {
		int n, m, k; cin >> n >> m >> k;
		vector<char> sz(n);
		for (int i = 0; i < n; ++i) {
			cin >> sz[i];
		}

		int mx = k, r = 0;
		for (int i = 0; i < m; ++i) {
			char c; cin >> c;
			if (c == 'A') {
				mx = n;
				continue;
			}
			int x; cin >> x;
			if (x <= mx && sz[x - 1] == 'S')
				r++;
			mx = max(mx, x);
		}
		cout << r << endl;
	}
}