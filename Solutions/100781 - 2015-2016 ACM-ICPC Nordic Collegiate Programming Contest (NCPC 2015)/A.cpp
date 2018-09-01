// 2015-2016 ACM-ICPC Nordic Collegiate Programming Contest (NCPC 2015)
// 100781A

#include <bits/stdc++.h>
#include <ext/hash_map>
#include <ext/hash_set>

#define fr first
#define sc second

using namespace __gnu_cxx;
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef pair<pii, pii> ppii;

const int MOD = 1e9 + 7;
const int N = 1e5 + 5;
vi adj[N];
int n, m;
int node, mx;
int vis[N];
int res = 2;

void dfs(int u, int par, int _lvl = 0) {
	if (_lvl > mx) {
		mx = _lvl;
		node = u;
	}
	vis[u] = 1;
	for (int nxt : adj[u]) {
		if (nxt == par)continue;
		dfs(nxt, u, _lvl + 1);
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
#endif
	int a, b;
	cin >> n >> m;
	if (n < 4) {
		cout << n - 1 << endl;
		return 0;
	}
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	vi ans;
	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			mx = -1;
			dfs(i, -1);
			mx = -1;
			dfs(node, -1);
			res = max(res, mx);
			ans.push_back((mx + 1) / 2);
		}
	}

	sort(ans.rbegin(), ans.rend());
	if (ans.size() == 1)
		res = max(res, ans[0]);
	else if (ans.size() == 2)
		res = max(res, ans[0] + ans[1] + 1);
	else
		res = max(res, max(ans[0] + ans[1] + 1, ans[1] + ans[2] + 2));
	cout << res << endl;

}