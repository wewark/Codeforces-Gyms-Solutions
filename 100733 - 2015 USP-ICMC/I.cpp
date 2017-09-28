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

int m, na, nb, t;
int solve(deque<int> ta, deque<int> tb) {
	int sz = 2 + ta.size() + tb.size();
	int a = ta.size() - 1, b = tb.size() - 1;
	Dinic dinic(sz);
	for (int i = 0, c = a; i < m && c >= 0; i++, c--)
		dinic.AddEdge(0, 1 + c, 1);
	for (int i = 0; i < m && i < tb.size(); i++)
		dinic.AddEdge(1 + ta.size() + i, sz - 1, 1);

	while (a >= 0 && b >= 0) {
		for (int i = 0; i < m && a >= 0; i++, a--) {
			for (int j = 0; j < tb.size(); j++)
				if (abs(ta[a] - tb[j]) < t)
					dinic.AddEdge(1 + a, 1 + ta.size() + j, 1);
			ta.pop_back();
		}
		for (int i = 0; i < m && b >= 0; i++, b--) {
			for (int j = 0; j < ta.size(); j++)
				if (abs(tb[b] - ta[j]) < t)
					dinic.AddEdge(1 + ta.size() + b, 1 + j, 1);
			tb.pop_back();
		}
	}
	return dinic.MaxFlow(0, sz - 1);
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> m >> na >> nb >> t;
	deque<int> ta(na), tb(nb);
	for (int i = 0; i < na; i++)
		cin >> ta[i];
	for (int i = 0; i < nb; i++)
		cin >> tb[i];
	sort(all(ta)), sort(all(tb));

	if (solve(ta, tb) == m || solve(tb, ta) == m)
		cout << "S\n";
	else
		cout << "N\n";
	cin.ignore(), cin.get();
}
