// 101243 - 2016-2017 ACM-ICPC, NEERC, Central Subregional Contest
// 101243J

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<bool> vb;
typedef vector<string> vs;
const int di[] = { -1, 0, 1, 0, -1, 1, 1, -1 };
const int dj[] = { 0, 1, 0, -1, -1, 1, -1, 1 };
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const long double EPS = 1e-10;
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

int n, m;

inline bool match(string a, string b) {
	int x = 0;
	for (int i = 0; i < 3; i++) {
		x += a[i] - '0';
	}
	for (int i = 3; i < 6; i++) {
		x -= b[i] - '0';
	}
	return x == 0;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	cin >> n >> m;
	vs A(n), T(m);
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> T[i];
	}

	Dinic dnc(n + m + 2);
	for (int i = 0; i < n; i++) {
		dnc.AddEdge(0, i + 1, 1);
		for (int j = 0; j < m; j++) {
			if (match(A[i], T[j]) || match(T[j], A[i]))
				dnc.AddEdge(i + 1, j + n + 1, 1);
		}
	}
	for (int i = 0; i < m; i++) {
		dnc.AddEdge(i + n + 1, n + m + 1, 1);
	}

	cout << dnc.MaxFlow(0, n + m + 1) << endl;
	for (auto& i : dnc.E) {
		if (i.u != 0 && i.u != n + m + 1 && i.v != 0 && i.v != n + m + 1 &&
			i.u < i.v && i.flow == 1) {
			if (match(A[i.u - 1], T[i.v - n - 1]))
				cout << "AT" << " " << A[i.u - 1] << " " << T[i.v - n - 1] << endl;
			else
				cout << "TA" << " " << T[i.v - n - 1] << " " << A[i.u - 1] << endl;
		}
	}

	//cin.ignore(), cin.get();
}
