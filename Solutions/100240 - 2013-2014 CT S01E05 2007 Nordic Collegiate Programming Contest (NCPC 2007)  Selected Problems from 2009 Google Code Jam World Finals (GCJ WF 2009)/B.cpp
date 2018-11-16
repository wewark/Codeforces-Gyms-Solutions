// 2013-2014 CT S01E05 2007 Nordic Collegiate Programming Contest (NCPC 2007)  Selected Problems from 2009 Google Code Jam World Finals (GCJ WF 2009)
// 100240B

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
const ll INF = 1e9;
#define all(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define fr first
#define sc second

struct Edge {
	int u, v;
	ll cap, flow;
	Edge() {}
	Edge(int u, int v, ll cap): u(u), v(v), cap(cap), flow(0) {}
};

struct Dinic {
	int N;
	vector<Edge> E;
	vector<vector<int>> g;
	vector<int> d, pt;

	Dinic(int N): N(N), E(0), g(N), d(N), pt(N) {}

	void AddEdge(int u, int v, ll cap) {
		if (u != v) {
			E.emplace_back(Edge(u, v, cap));
			g[u].emplace_back(E.size() - 1);
			E.emplace_back(Edge(v, u, 0));
			g[v].emplace_back(E.size() - 1);
		}
	}

	bool BFS(int S, int T) {
		queue<int> q({S});
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

	ll DFS(int u, int T, ll flow = -1) {
		if (u == T || flow == 0) return flow;
		for (int &i = pt[u]; i < g[u].size(); ++i) {
			Edge &e = E[g[u][i]];
			Edge &oe = E[g[u][i] ^ 1];
			if (d[e.v] == d[e.u] + 1) {
				ll amt = e.cap - e.flow;
				if (flow != -1 && amt > flow) amt = flow;
				if (ll pushed = DFS(e.v, T, amt)) {
					e.flow += pushed;
					oe.flow -= pushed;
					return pushed;
				}
			}
		}
		return 0;
	}

	ll MaxFlow(int S, int T) {
		ll total = 0;
		while (BFS(S, T)) {
			fill(pt.begin(), pt.end(), 0);
			while (ll flow = DFS(S, T))
				total += flow;
		}
		return total;
	}
};

int n, m;


int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;
	while (t--) {
		cin >> m >> n;
		Dinic dn(n + m + 5);
		for (int i = 0; i < m; ++i) {
			int a, b;
			cin >> a >> b;
			dn.AddEdge(n + i, a, 1);
			dn.AddEdge(n + i, b, 1);
			dn.AddEdge(n + m + 1, n + i, 1);
		}

		for (int i = 0; i < n; ++i) {
			dn.AddEdge(i, n + m + 2, 1);
		}

		if (dn.MaxFlow(n + m + 1, n + m + 2) == m)
			cout << "successful hashing" << endl;
		else
			cout << "rehash necessary" << endl;
	}
	return 0;
}