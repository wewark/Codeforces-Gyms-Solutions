// 2018 German Collegiate Programming Contest (GCPC 18)
// 102021C

#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1003;

int n, m;
vector<int> adj[N];
int val[N][N];
int vis[N];
int vid;
int dp[N];
bool in[N];

int dfs(int cur, int par = -1) {
	int &ret = dp[cur];
	if (ret != -1)
		return ret;
	ret = 0;
	for (int to : adj[cur]) {
		if (to == par)
			continue;
		ret = max(ret, dfs(to, cur) + val[cur][to]);
	}
	return ret;
}

int main() {
	std::ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		u--, v--;
		in[v] = 1;
		adj[u].push_back(v);
		val[u][v] = max(val[u][v], c);
	}
	memset(dp, -1, sizeof dp);
	int res = 0;
	for (int i = 0; i < n; i++) {
		if (!in[i]) {
			res = max(res, dfs(i));
		}
	}
	cout << res << endl;
	return 0;
}
