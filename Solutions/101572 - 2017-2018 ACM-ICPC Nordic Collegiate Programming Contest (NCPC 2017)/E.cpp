// 101572 - 2017-2018 ACM-ICPC Nordic Collegiate Programming Contest (NCPC 2017)
// 101572E

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
const int di[] = { -1, 0, 1, 0, 1, -1, 1, -1 };
const int dj[] = { 0, 1, 0, -1, 1, -1, -1, 1 };
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const double EPS = 1e-5;
#define mp make_pair
#define all(x) x.begin(),x.end()
#define x first
#define y second

int h, w;
pii snk;
vvi g;
vector<vb> vis;
map<int, map<int, bool>> adj;

struct Edge {
	int i, j;
	int vi, vj;

	bool operator < (Edge other) const {
		return g[i][j] > g[other.i][other.j];
	}
};

inline bool valid(int i, int j) {
	return i >= 0 && i < h && j >= 0 && j < w;
}

void MST() {
	priority_queue<Edge> pq;
	for (int i = 0; i < 8; i++) {
		pii cur = { snk.x + di[i], snk.y + dj[i] };
		if (valid(cur.x, cur.y) && g[cur.x][cur.y] < 0)
			pq.push(Edge{ snk.x, snk.y, cur.x, cur.y });
	}
	vis[snk.x][snk.y] = true;

	while (!pq.empty()) {
		Edge u = pq.top(); pq.pop();
		if (vis[u.vi][u.vj]) continue;

		vis[u.vi][u.vj] = true;
		adj[u.i * w + u.j][u.vi * w + u.vj] = true;

		for (int i = 0; i < 8; i++) {
			pii cur = { u.vi + di[i], u.vj + dj[i] };
			if (valid(cur.x, cur.y) && g[cur.x][cur.y] < 0 && !vis[cur.x][cur.y])
				pq.push(Edge{ u.vi, u.vj, cur.x, cur.y });
		}
	}
}

ll r = 0;
void dfs(int cx, int cy, int mx) {
	mx = max(mx, g[cx][cy]);
	r -= mx;
	for (int i = 0; i < 8; i++) {
		pii cur = { cx + di[i], cy + dj[i] };
		if (valid(cur.x, cur.y) && adj[cx * w + cy][cur.x * w + cur.y])
			dfs(cur.x, cur.y, mx);
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> h >> w;
	g.assign(h, vi(w));
	vis.assign(h, vb(w));
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> g[i][j];
		}
	}
	cin >> snk.x >> snk.y;
	snk.x--, snk.y--;

	MST();
	dfs(snk.x, snk.y, -INF);

	cout << r << endl;
	cin.ignore(), cin.get();
}
