#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<ll, ll> pii;
typedef vector<pii> vii;
typedef vector<bool> vb;
typedef vector<string> vs;
const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, 1, 0, -1 };
const ll MOD = 5e6;
const ll INF = 1e8;
const double EPS = 1e-12;
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
	ll n, q, s; cin >> n >> q >> s;
	vi sen(s);
	for (int i = 0; i < s; i++) {
		cin >> sen[i]; sen[i]--;
	}
	vi sz(q);
	for (int i = 0; i < q; i++) {
		cin >> sz[i];
	}

	vi d(n);
	vvi qinc(n, vi(q)); ll sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> d[i];
		for (int j = 0; j < s; j++) {
			ll x; cin >> x;
			sum += x;
			qinc[i][sen[j]] += x;
		}
	}

	Dinic dinic(q * n * 2 + n + 2);
	int t = q * n * 2 + n + 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < q; j++) {
			int a = q * i + j + 1;
			int b = a + n * q;
			dinic.AddEdge(0, a, qinc[i][j]);
			dinic.AddEdge(a, b, sz[j]);

			if (i < n - 1)
				dinic.AddEdge(b, q * (i + 1) + j + 1, INF);
			dinic.AddEdge(b, 2 * n * q + i + 1, INF);
		}
		dinic.AddEdge(2 * n * q + i + 1, t, d[i]);
	}

	cout << (dinic.MaxFlow(0, t) == sum ? "possible" : "impossible") << endl;
	cin.ignore(), cin.get();
}