// 2003-2004 Summer Petrozavodsk Camp Andrew Stankevich Contest 3 (ASC 3)
// 100198E

#include <bits/stdc++.h>
#include <ext/hash_set>
#include <ext/numeric>

using namespace __gnu_cxx;

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
int di[] = {0, 0, 1, -1};
int dj[] = {1, -1, 0, 0};
#define all(x) x.begin(),x.end()

int n, m, s, t;
vector<vii> adj;

int BFSDist() {
	queue<int> q;
	vi dist(n, INF);
	q.push(s);
	dist[s] = 0;
	while (!q.empty()) {
		int u = q.front();
		q.pop();

		if (u == t) return dist[u];

		for (pii &v : adj[u]) {
			if (dist[v.first] == INF) {
				dist[v.first] = dist[u] + 1;
				q.push(v.first);
			}
		}
	}
	return -1;
}

vvi BFS(int ds) {
	queue<int> q;
	vi dist(n, INF);
	q.push(s);
	dist[s] = 0;

	vvi ret(ds);
	while (!q.empty()) {
		int u = q.front();
		q.pop();

		if (dist[u] == ds) continue;

		for (pii &v : adj[u]) {
			if (dist[v.first] > dist[u])
				ret[dist[u]].push_back(v.second);
			if (dist[v.first] == INF) {
				dist[v.first] = dist[u] + 1;
				q.push(v.first);
			}
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#else
	freopen("defence.in", "r", stdin);
	freopen("defence.out", "w", stdout);
#endif

	cin >> n >> m >> s >> t;
	s--, t--;
	adj.assign(n, vii());
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		adj[u].emplace_back(v, i);
		adj[v].emplace_back(u, i);
	}

	int dist = BFSDist();
	vvi ans = BFS(dist);
	cout << dist << endl;
	for (auto &an : ans) {
		cout << an.size();
		for (int j : an)
			cout << " " << j + 1;
		cout << endl;
	}
}
