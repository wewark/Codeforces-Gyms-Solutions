// CCPC 2016-2017 Finals
// 101206H
// Dynamic Programming, Bitmasks

#include <bits/stdc++.h>

using namespace __gnu_cxx;
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using pii = pair<int, ll>;
using vii = vector<pii>;
using vb = vector<bool>;
using vs = vector<string>;
const int MOD = int(1e9 + 7);
const long double EPS = 1e-8;
const double PI = acos(-1.0);
const ll INF = ll(1e18);
int di[] = {0, 1, 0, -1};
int dj[] = {1, 0, -1, 0};
#define all(x) x.begin(),x.end()

int n, m;
vvi prj, eng;

inline bool satisfy(int pi, vi engs) {
	for (auto &exndd : prj[pi]) {
		bool found = false;
		for (auto &e : engs) {
			for (auto &ex : eng[e]) {
				if (ex == exndd) {
					found = true;
					break;
				}
			}
			if (found) break;
		}

		if (!found)
			return false;
	}
	return true;
}

int mem[11][1 << 10];
int vis[11][1 << 10], vf = 0;
int solve(int idx, int msk) {
	if (idx == n) return 0;

	int& ret = mem[idx][msk];
	if (vis[idx][msk] == vf)
		return ret;
	vis[idx][msk] = vf;
	ret = solve(idx + 1, msk);

	for (int i = 0; i < m; ++i) {
		if (~msk & (1 << i)) {
			int nxtMsk = msk | (1 << i);
			if (satisfy(idx, {i})) {
				ret = max(ret, solve(idx + 1, nxtMsk) + 1);
			}
		}
	}

	for (int i = 0; i < m; ++i) {
		if (~msk & (1 << i))
			for (int j = i + 1; j < m; ++j) {
				if (~msk & (1 << j)) {
					int nxtMsk = msk | (1 << i);
					nxtMsk |= (1 << j);
					if (satisfy(idx, {i, j})) {
						ret = max(ret, solve(idx + 1, nxtMsk) + 1);
					}
				}
			}
	}

	for (int i = 0; i < m; ++i) {
		if (~msk & (1 << i))
			for (int j = i + 1; j < m; ++j) {
				if (~msk & (1 << j))
					for (int k = j + 1; k < m; ++k) {
						if (~msk & (1 << k)) {
							int nxtMsk = msk | (1 << i);
							nxtMsk |= (1 << j);
							nxtMsk |= (1 << k);
							if (satisfy(idx, {i, j, k})) {
								ret = max(ret, solve(idx + 1, nxtMsk) + 1);
							}
						}
					}
			}
	}

	return ret;
}


int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int t, tt = 0;
	cin >> t;
	while (t--) {
		vf++;
		cin >> n >> m;
		prj.assign(n, vi());
		eng.assign(m, vi());
		for (int i = 0; i < n; ++i) {
			int sz;
			cin >> sz;
			prj[i].resize(sz);
			for (int j = 0; j < sz; ++j) {
				cin >> prj[i][j];
			}
		}
		for (int i = 0; i < m; ++i) {
			int sz;
			cin >> sz;
			eng[i].resize(sz);
			for (int j = 0; j < sz; ++j) {
				cin >> eng[i][j];
			}
		}

		cout << "Case #" << ++tt << ": ";
		cout << solve(0, 0) << endl;
	}
}
