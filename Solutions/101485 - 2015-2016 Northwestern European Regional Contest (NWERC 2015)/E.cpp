// 101485 - 2015-2016 Northwestern European Regional Contest (NWERC 2015)
// 101485E

#include<bits/stdc++.h>
using namespace std;
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

// BEGIN CUT

pair<long long, long long> p[3000];
map<long long, int>mp;
int main()
{
	int N;
	scanf("%d", &N);
	Dinic dinic(N * 4 + 2);

	int id = N + 1;
	for (int i = 1; i <= N; i++) {
		scanf("%lld %lld", &p[i].first, &p[i].second);

		if (!mp[p[i].first + p[i].second]) {
			dinic.AddEdge(id, N * 4 + 1, 1);
			mp[p[i].first + p[i].second] = id++;
		}
		dinic.AddEdge(i, mp[p[i].first + p[i].second], 1);

		if (!mp[p[i].first * p[i].second]) {
			dinic.AddEdge(id, N * 4 + 1, 1);
			mp[p[i].first * p[i].second] = id++;
		}
		dinic.AddEdge(i, mp[p[i].first * p[i].second], 1);

		if (!mp[p[i].first - p[i].second]) {
			dinic.AddEdge(id, N * 4 + 1, 1);
			mp[p[i].first - p[i].second] = id++;
		}
		dinic.AddEdge(i, mp[p[i].first - p[i].second], 1);
		dinic.AddEdge(0, i, 1);
	}
	long long flow = dinic.MaxFlow(0, N * 4 + 1);
	if (flow != N) {
		puts("impossible");
		return 0;
	}
	for (int i = 1; i <= N; i++) {
		if (dinic.E[dinic.g[i][0]].flow == 1) {
			cout << p[i].first << " + " << p[i].second << " = " << p[i].first + p[i].second << endl;
		}
		else if (dinic.E[dinic.g[i][1]].flow == 1) {
			cout << p[i].first << " * " << p[i].second << " = " << p[i].first * p[i].second << endl;
		}
		else {
			cout << p[i].first << " - " << p[i].second << " = " << p[i].first - p[i].second << endl;
		}
	}

	return 0;
}
