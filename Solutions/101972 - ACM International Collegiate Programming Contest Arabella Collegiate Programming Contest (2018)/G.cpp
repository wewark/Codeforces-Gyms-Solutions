// ACM International Collegiate Programming Contest Arabella Collegiate Programming Contest (2018)
// 101972G

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

const int MAXN = 503;
int g[MAXN][MAXN];
int ul[MAXN][MAXN];
int ur[MAXN][MAXN];
int dl[MAXN][MAXN];
int dr[MAXN][MAXN];

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cin >> g[i][j];
				ul[i][j] = g[i][j];
				ur[i][j] = g[i][j];
				dl[i][j] = g[i][j];
				dr[i][j] = g[i][j];
			}
		}

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j) {
				if (i && ul[i - 1][j])
					ul[i][j] = max(ul[i][j], ul[i - 1][j]);
				if (j && ul[i][j - 1])
					ul[i][j] = max(ul[i][j], ul[i][j - 1]);
				if (i && j && ul[i - 1][j - 1])
					ul[i][j] = max(ul[i][j], ul[i - 1][j - 1]);
			}

		for (int i = 0; i < n; ++i)
			for (int j = m - 1; j >= 0; --j) {
				if (i && ur[i - 1][j])
					ur[i][j] = max(ur[i][j], ur[i - 1][j]);
				if (j < m - 1 && ur[i][j + 1])
					ur[i][j] = max(ur[i][j], ur[i][j + 1]);
				if (i && j < m - 1 && ur[i - 1][j + 1])
					ur[i][j] = max(ur[i][j], ur[i - 1][j + 1]);
			}

		for (int i = n - 1; i >= 0; --i)
			for (int j = 0; j < m; ++j) {
				if (i < n - 1 && dl[i + 1][j])
					dl[i][j] = max(dl[i][j], dl[i + 1][j]);
				if (j && dl[i][j - 1])
					dl[i][j] = max(dl[i][j], dl[i][j - 1]);
				if (i < n - 1 && j && dl[i + 1][j - 1])
					dl[i][j] = max(dl[i][j], dl[i + 1][j - 1]);
			}

		for (int i = n - 1; i >= 0; --i)
			for (int j = m - 1; j >= 0; --j) {
				if (i < n - 1 && dr[i + 1][j])
					dr[i][j] = max(dr[i][j], dr[i + 1][j]);
				if (j < m - 1 && dr[i][j + 1])
					dr[i][j] = max(dr[i][j], dr[i][j + 1]);
				if (i < n - 1 && j < m - 1 && dr[i + 1][j + 1])
					dr[i][j] = max(dr[i][j], dr[i + 1][j + 1]);
			}

		int r = INT_MAX;
		for (int i = 1; i < n - 1; ++i) {
			for (int j = 1; j < m - 1; ++j) {
				int mx = 0, mn = INT_MAX;

				mx = max(mx, ul[i - 1][j - 1]);
				mn = min(mn, ul[i - 1][j - 1]);

				mx = max(mx, ur[i - 1][j + 1]);
				mn = min(mn, ur[i - 1][j + 1]);

				mx = max(mx, dl[i + 1][j - 1]);
				mn = min(mn, dl[i + 1][j - 1]);

				mx = max(mx, dr[i + 1][j + 1]);
				mn = min(mn, dr[i + 1][j + 1]);

				r = min(r, mx - mn);
			}
		}
		cout << r << endl;
	}
}