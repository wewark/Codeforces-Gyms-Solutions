// 101808 - ACM International Collegiate Programming Contest, Damascus University Collegiate Programming Contest(2018)
// 101808K

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
const int di[] = { 0, 0, 1, -1 };
const int dj[] = { 1, -1, 0, 0 };
const ll MOD = 7901;
const ll INF = 1e9;
const long double EPS = 1e-6;
#define all(x) x.begin(),x.end()

int n;
vi prnt, lvl;
vvi adj;
vector<vii> P;
map<pii, ll> edge;
vb vis;

void initLCA() {
	//we initialize every element in P with -1
	P.assign(n, vii(ceil(log2(n))));

	//the first ancestor of every node i is prnt[i]
	for (int i = 0; i < n; i++)
		P[i][0] = pii(prnt[i], edge[pii(i, prnt[i])]);

	//bottom up dynamic programing
	for (int j = 1; 1 << j < n; j++)
		for (int i = 0; i < n; i++)
			if (P[i][j - 1].first != -1) {
				P[i][j].first = P[P[i][j - 1].first][j - 1].first;
				P[i][j].second = P[i][j - 1].second + P[P[i][j - 1].first][j - 1].second;
			}
}

ll getDist(int p, int q) {
	//if p is situated on a higher level than q then we swap them
	if (lvl[p] < lvl[q])
		swap(p, q);

	//we compute the value of [log(lvl[p)]
	int log = 1;
	while (1 << log <= lvl[p]) log++;
	log--;

	ll ret = 0;
	//we find the ancestor of node p situated on the same level
	//with q using the values in P
	for (int i = log; i >= 0; i--)
		if (lvl[p] - (1 << i) >= lvl[q]) {
			ret += P[p][i].second;
			p = P[p][i].first;
		}

	if (p == q) return ret;

	//we compute LCA(p, q) using the values in P
	for (int i = log; i >= 0; i--)
		if (P[p][i].first != -1 && P[p][i].first != P[q][i].first) {
			ret += P[p][i].second + P[q][i].second;
			p = P[p][i].first, q = P[q][i].first;
		}
	//cout << p + 1 << " " << q + 1 << endl;
	return ret + edge[pii(p, prnt[p])] + edge[pii(q, prnt[q])];
}


void dfsP(int node, int cprnt, int clvl) {
	prnt[node] = cprnt;
	lvl[node] = clvl;
	for (int i = 0; i < adj[node].size(); i++)
		if (adj[node][i] != cprnt)
			dfsP(adj[node][i], node, clvl + 1);
}

ll eu, ev, ew;

ll query(int u, int v) {
	return min(getDist(u, v),
		min(getDist(u, eu) + getDist(ev, v),
			getDist(u, ev) + getDist(eu, v)) + ew);
}

bool done = false;
void dfs(int node, int prnt) {
	if (vis[node]) {
		eu = prnt, ev = node, ew = edge[pii(eu, ev)];
		edge.erase(pii(node, prnt));
		edge.erase(pii(prnt, node));
		adj[node].erase(find(all(adj[node]), prnt));
		adj[prnt].erase(find(all(adj[prnt]), node));
		done = true;
		return;
	}
	vis[node] = true;

	for (auto& i : adj[node]) {
		if (i != prnt)
			dfs(i, node);
		if (done) return;
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int q; cin >> n >> q;
		adj.assign(n, vi());
		edge.clear();

		for (int i = 0; i < n; i++) {
			int u, v, w; cin >> u >> v >> w;
			u--, v--;
			adj[u].emplace_back(v);
			adj[v].emplace_back(u);
			edge[pii(u, v)] = edge[pii(v, u)] = w;
		}

		vis.assign(n, false);
		done = false;
		dfs(0, -1);

		prnt.assign(n, -1);
		lvl.assign(n, 0);
		dfsP(0, -1, 0);
		initLCA();

		while (q--) {
			int u, v; cin >> u >> v; u--, v--;
			cout << query(u, v) << endl;
		}

	}
	cin.ignore(), cin.get();
}
