// 2018 German Collegiate Programming Contest (GCPC 18)
// 102021L

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


int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int n, m; cin >> n >> m;
	n += 2, m += 2;
	vvi g(n, vi(m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> g[i][j];
		}
	}

	vs ans(n, string(m, '.'));
	for (int i = 1; i < n - 1; ++i) {
		for (int j = 1; j < m - 1; ++j) {
			bool mine = true;
			for (int k = 0; k < 9; ++k) {
				if (g[i + di[k]][j + dj[k]] == 0) {
					mine = false;
					break;
				}
			}

			if (mine) {
				ans[i][j] = 'X';
				for (int k = 0; k < 9; ++k) {
					g[i + di[k]][j + dj[k]]--;
				}
			}
		}
	}

	bool good = true;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (g[i][j])
				good = false;
		}
	}
	if (good) {
		for (int i = 1; i < n - 1; ++i) {
			cout << ans[i].substr(1, m - 2) << endl;
		}
	}
	else {
		cout << "impossible" << endl;
	}
}
