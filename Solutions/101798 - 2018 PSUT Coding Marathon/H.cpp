// 101798 - 2018 PSUT Coding Marathon
// 101798H

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
const int di[] = { 0, 0, 1, -1 };
const int dj[] = { 1, -1, 0, 0 };
const ll MOD = 1e9 + 9;
const ll INF = 1e9;
const long double EPS = 1e-7;
#define all(n) n.begin(),n.end()

int n;
vvi adj;
vi col;

bool check(int, int);
void dfs(int, int, vi&);

bool bfs(int a, int b) {
	col.assign(n, 0);
	col[a] = 1, col[b] = 2;
	queue<int> q;
	q.push(a);
	q.push(b);
	while (!q.empty()) {
		int cur = q.front(); q.pop();

		for (int i = 0; i < adj[cur].size(); i++) {
			int v = adj[cur][i];
			if (!col[v]) {
				col[v] = col[cur];
				q.push(v);
			}
		}
	}

	return check(a, b);
}

vi sideA, sideB;
vb vis;

bool check(int a, int b) {
	sideA.clear();
	sideB.clear();
	vis.assign(n, false);
	dfs(a, -1, sideA);
	vis.assign(n, false);
	dfs(b, -1, sideB);

	if (sideA.size() != n / 2 || sideB.size() != n / 2)
		return false;

	bool w = false;
	for (int i = 0; i < n / 2; i++) {
		if (find(all(adj[sideA[i]]), sideB[i]) == adj[sideA[i]].end() ||
			find(all(adj[sideA[i]]), sideA[(i + 1) % (n / 2)]) == adj[sideA[i]].end() ||
			find(all(adj[sideB[i]]), sideB[(i + 1) % (n / 2)]) == adj[sideB[i]].end()) {
			w = true; break;
		}
	}

	if (!w) return true;
	w = false;

	reverse(sideB.begin() + 1, sideB.end());
	for (int i = 0; i < n / 2; i++) {
		if (find(all(adj[sideA[i]]), sideB[i]) == adj[sideA[i]].end() ||
			find(all(adj[sideA[i]]), sideA[(i + 1) % (n / 2)]) == adj[sideA[i]].end() ||
			find(all(adj[sideB[i]]), sideB[(i + 1) % (n / 2)]) == adj[sideB[i]].end()) {
			w = true; break;
		}
	}

	return !w;
}

void dfs(int node, int prnt, vi& side) {
	if (vis[node]) return;
	vis[node] = true;

	side.push_back(node);
	for (int i = 0; i < adj[node].size(); i++) {
		if (adj[node][i] != prnt && col[adj[node][i]] == col[node]) {
			dfs(adj[node][i], node, side);
			return;
		}
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n;
	adj.assign(n, vi());
	for (int i = 0; i < 3 * n / 2; i++) {
		int u, v; cin >> u >> v;
		u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 0; i < n; i++) {
		if (adj[i].size() != 3) {
			cout << "NO" << endl;
			return 0;
		}
	}

	if (bfs(0, adj[0][0]) ||
		bfs(0, adj[0][1]) ||
		bfs(0, adj[0][2])) {
		cout << "YES" << endl;
		for (int i = 0; i < n / 2; i++) {
			cout << sideA[i] + 1 << " \n"[i == n / 2 - 1];
		}
		for (int i = 0; i < n / 2; i++) {
			cout << sideB[i] + 1 << " \n"[i == n / 2 - 1];
		}
	}
	else cout << "NO" << endl;

	cin.ignore(), cin.get();
}
