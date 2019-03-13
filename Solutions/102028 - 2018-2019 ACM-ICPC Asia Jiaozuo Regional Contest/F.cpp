// 2018-2019 ACM-ICPC Asia Jiaozuo Regional Contest
// 102028F

#include <bits/stdc++.h>
#include <ext/hash_set>
#include <ext/numeric>

using namespace __gnu_cxx;
using namespace std;

using ll = long long;
using vi = vector<ll>;
using vll = vector<ll>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;
using vb = vector<bool>;
using vs = vector<string>;
const int MOD = int(1e9 + 7);
const long double EPS = 1e-8;
const double PI = 3.1415926535897932384626433;
const ll INF = ll(1e18);
//int di[] = {0, 0, 1, -1, 1, -1, 1, -1};
//int dj[] = {1, -1, 0, 0, 1, -1, -1, 1};
#define all(x) x.begin(),x.end()
#define x first
#define y second

int r, c;
int n, m;
pii S, T;
vs g;

inline bool valid(int i, int j, int cm) {
	return i >= 0 && i < n && j >= 0 && j < cm &&
			(g[i][j] == ' ' ||
			g[i][j] == 'S' ||
			g[i][j] == 'T');
}

bool bfs() {
	queue<pii> q;
	q.emplace(S);
	vector<vb> vis(n, vb(m));
	vector<vii> prv(n, vii(m, pii(-1, -1)));
	vis[S.x][S.y] = true;

	int di[] = { 2, -2, 2, -2, 4, -4 };
	int dj[] = { 6, 6, -6, -6, 0, 0 };
	int ci[] = { 1, -1, 1, -1, 2, -2 };
	int cj[] = { 3, 3, -3, -3, 0, 0 };

	while (!q.empty()) {
		pii u = q.front(); q.pop();

		if (u == T) break;

		for (int i = 0; i < 6; ++i) {
			pii v(u.x + di[i], u.y + dj[i]);
			pii dr(u.x + ci[i], u.y + cj[i]);
			if (valid(v.x, v.y, g[v.x].length()) &&
				!vis[v.x][v.y] &&
				g[dr.x][dr.y] == ' ') {
				prv[v.x][v.y] = u;
				vis[v.x][v.y] = true;
				q.push(v);
			}
		}
	}

	pii cur = T;
	while (prv[cur.x][cur.y] != pii(-1, -1)) {
		g[cur.x][cur.y] = '.';
		cur = prv[cur.x][cur.y];
	}
	g[cur.x][cur.y] = '.';
	return cur == S;
}

inline bool inPath(int i, int j) {
	for (int k = i - 1; k <= i + 1; ++k)
		for (int l = j - 3; l <= j + 3; ++l)
			if (g[k][l] == '.')
				return true;
	return false;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int t; cin >> t;
	while (t--) {
		cin >> r >> c;
		n = 4 * r + 3;
		m = 6 * c + 3;
		g.resize(n);
		cin.ignore();
		for (int i = 0; i < 4 * r + 3; ++i) {
			getline(cin, g[i]);
			for (int j = 0; j < g[i].length(); ++j) {
				if (g[i][j] == 'S')
					S = {i, j};
				else if (g[i][j] == 'T')
					T = {i, j};
			}
		}

		int ans = -1;
		if (bfs()) {
			ans = 0;
			for (int i = 2; i < n - 1; i += 4)
				for (int j = 4; j < g[i].length(); j += 12)
					if (inPath(i, j))
						ans++;
			for (int i = 4; i < n - 1; i += 4)
				for (int j = 10; j < g[i].length(); j += 12)
					if (inPath(i, j))
						ans++;
		}
		cout << ans << endl;
	}
}
