#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

struct Edge {
    int u, v;
    LL cap, flow;
    Edge() {}
    Edge(int u, int v, LL cap): u(u), v(v), cap(cap), flow(0) {}
};

struct Dinic {
    int N;
    vector<Edge> E;
    vector<vector<int>> g;
    vector<int> d, pt;

    Dinic(int N): N(N), E(0), g(N), d(N), pt(N) {}

    void AddEdge(int u, int v, LL cap) {
        if (u != v) {
            E.emplace_back(u, v, cap);
            g[u].emplace_back(E.size() - 1);
            E.emplace_back(v, u, 0);
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
                Edge& e = E[k];
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
        for (int& i = pt[u]; i < g[u].size(); ++i) {
            Edge& e = E[g[u][i]];
            Edge& oe = E[g[u][i] ^ 1];
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
    ios::sync_with_stdio(0), cin.tie(0);
//     freopen("in.txt", "rt", stdin);

    int n, m, p; cin >> n >> m >> p;
    int S = 0, sz = n + m + p + 2;
    int T = sz - 1;

    Dinic dinic(sz);

    for (int i = 0; i < n; ++i) {
        int k = 0; cin >> k;
        while (k--) {
            int toy; cin >> toy; toy--;
            dinic.AddEdge(toy + p + 1, i + p + m + 1, 1);
        }
    }

    vector<bool> vis(m);
    for (int i = 0; i < p; ++i) {
        int k; cin >> k;
        while (k--) {
            int toy; cin >> toy; toy--;
            dinic.AddEdge(i + 1, toy + p + 1, 1);
            vis[toy] = true;
        }

        int r; cin >> r;
        dinic.AddEdge(S, i + 1, r);
    }

    for (int i = 0; i < m; ++i) {
        if (!vis[i]) {
            dinic.AddEdge(S, i + p + 1, 1);
        }
    }

    for (int i = 0; i < n; ++i) {
        dinic.AddEdge(i + p + m + 1, T, 1);
    }

    cout << dinic.MaxFlow(S, T) << endl;

    return 0;
}
