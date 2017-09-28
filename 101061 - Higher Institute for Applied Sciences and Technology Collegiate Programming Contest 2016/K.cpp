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
const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, 1, 0, -1 };
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const double EPS = 1e-11;
#define mp make_pair
#define all(x) x.begin(),x.end()

typedef long long LL;

struct Edge {
	int u, v;
	LL cap, flow;
	Edge() {}
	Edge(int u, int v, LL cap) : u(u), v(v), cap(cap), flow(0) {}
};

struct Dinic {
	int N;
	vector<Edge> E;
	vector<vector<int>> g;
	vector<int> d, pt;

	Dinic(int N) : N(N), E(0), g(N), d(N), pt(N) {}

	void AddEdge(int u, int v, LL cap) {
		if (u != v) {
			E.emplace_back(Edge(u, v, cap));
			g[u].emplace_back(E.size() - 1);
			E.emplace_back(Edge(v, u, 0));
			g[v].emplace_back(E.size() - 1);
		}
	}

	bool BFS(int S, int T) {
		queue<int> q({ S });
		fill(d.begin(), d.end(), N + 1);
		d[S] = 0;
		while (!q.empty()) {
			int u = q.front(); q.pop();
			if (u == T) break;
			for (int k : g[u]) {
				Edge &e = E[k];
				if (e.flow < e.cap && d[e.v] > d[e.u] + 1) {
					d[e.v] = d[e.u] + 1;
					q.emplace(e.v);
				}
			}
		}
		return d[T] != N + 1;
	}

	LL DFS(int u, int T, LL flow = -1) {
		if (u == T || flow == 0) return flow;
		for (int &i = pt[u]; i < g[u].size(); ++i) {
			Edge &e = E[g[u][i]];
			Edge &oe = E[g[u][i] ^ 1];
			if (d[e.v] == d[e.u] + 1) {
				LL amt = e.cap - e.flow;
				if (flow != -1 && amt > flow) amt = flow;
				if (LL pushed = DFS(e.v, T, amt)) {
					e.flow += pushed;
					oe.flow -= pushed;
					return pushed;
				}
			}
		}
		return 0;
	}

	LL MaxFlow(int S, int T) {
		LL total = 0;
		while (BFS(S, T)) {
			fill(pt.begin(), pt.end(), 0);
			while (LL flow = DFS(S, T))
				total += flow;
		}
		return total;
	}
};

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, m, w; cin >> n >> m >> w;

		int sz = 2 + n + m;
		Dinic dinic(sz);

		vvi plc(n), wep(n), plcwep(m);
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			plc[i].resize(x);
			for (int j = 0; j < x; j++)
				cin >> plc[i][j], plc[i][j]--;
			dinic.AddEdge(0, 1 + i, 1);
		}
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			wep[i].resize(x);
			for (int j = 0; j < x; j++)
				cin >> wep[i][j], wep[i][j]--;
		}
		for (int i = 0; i < m; i++) {
			int x; cin >> x;
			plcwep[i].resize(x);
			for (int j = 0; j < x; j++)
				cin >> plcwep[i][j], plcwep[i][j]--;
			dinic.AddEdge(1 + n + i, sz - 1, 1);
		}

		vi vis(101); int vf = 0;
		for (int i = 0; i < n; i++) {
			vf++;
			for (int j = 0; j < wep[i].size(); j++)
				vis[wep[i][j]] = vf;
			for (int j = 0; j < plc[i].size(); j++) {
				bool f = false;
				for (int k = 0; k < plcwep[plc[i][j]].size(); k++)
					if (vis[plcwep[plc[i][j]][k]] == vf) {
						f = true; break;
					}
				if (f) dinic.AddEdge(1 + i, 1 + n + plc[i][j], 1);
			}
		}
		cout << dinic.MaxFlow(0, sz - 1) << endl;
	}
	cin.ignore(), cin.get();
}
