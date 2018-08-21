// 101801 - Tishreen-CPC 2018
// 101801H

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
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const long double EPS = 1e-6;
#define all(x) x.begin(),x.end()

int n, a, b;
vvi adj;

vi subTreeSize, lvl;
int getSubtreeSize(int node, int prnt, int clvl) {
	lvl[node] = clvl;
	subTreeSize[node] = 1;
	for (auto& i : adj[node]) {
		if (i != prnt)
			subTreeSize[node] += getSubtreeSize(i, node, clvl + 1);
	}
	return subTreeSize[node];
}

ll DFS(int node, int prv, int mnlvlNode) {
	if (lvl[node] < lvl[mnlvlNode])
		mnlvlNode = node;
	ll ret = n - subTreeSize[mnlvlNode];
	for (auto& i : adj[node]) {
		if (i != prv && i != a)
			ret += DFS(i, node, mnlvlNode);
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> n >> a >> b; a--, b--;
		adj.assign(n, vi());
		subTreeSize.resize(n);
		lvl.resize(n);

		for (int i = 0; i < n - 1; i++) {
			int u, v; cin >> u >> v; u--, v--;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		getSubtreeSize(a, -1, 0);
		cout << DFS(b, -1, b) << endl;
	}
	cin.ignore(), cin.get();
}
