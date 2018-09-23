// 2013-2014 CT S01E09 2011 German Collegiate Programming Contest (GCPC 2011)  GCJ 2009 R3 C-D
// 100274C

#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<bool> vb;
typedef vector<string> vs;
const int di[] = {0, 0, 1, -1};
const int dj[] = {1, -1, 0, 0};
const ll MOD = 1e9 + 7;
const long double EPS = 1e-5;
#define all(x) x.begin(),x.end()

#include <ext/hash_set>
#include <ext/numeric>

const int N = 1e5 + 5;
int vis[N], deg[N];
vi adj[N];
int n, m;
bool cycle;

void dfs(int u) {
	vis[u] = 1;
	for (int nxt : adj[u]) {
		if (vis[nxt] == 1) {
			cycle = true;
		}
		else if (!vis[nxt]) {
			dfs(nxt);
		}
	}
	vis[u] = 2;
}

int main() {
//	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int t;
	scanf("%d", &t);
	while (t--) {
		int a, b;
		scanf("%d%d", &n, &m);
		vi v;
		for (int i = 0; i < n; i++) {
			adj[i].clear();
			vis[i] = deg[i] = 0;
		}
		cycle = false;

		for (int i = 0; i < m; i++) {
			scanf("%d%d", &a, &b);
			a--, b--;
			adj[a].push_back(b);
			deg[b]++;
		}

		for (int i = 0; i < n; i++) {
			if (!vis[i]) {
				dfs(i);
			}
		}


		if (cycle) {
			puts("recheck hints");
			continue;
		}

		queue<int> q;
		for (int i = 0; i < n; i++) {
			if (deg[i] == 0) {
				q.push(i);
			}
		}

		bool mul = false;
		while (!q.empty()) {
			mul |= (q.size() > 1);
			int u = q.front();
			v.push_back(u);
			q.pop();
			for (int nxt : adj[u]) {
				deg[nxt]--;
				if (deg[nxt] == 0)q.push(nxt);
			}
		}

		if (mul){
			puts("missing hints");
			continue;
		}

		for (int i = 0; i < n; ++i) {
			printf("%d%c", v[i]+1, " \n"[i == n - 1]);
		}


	}

	return 0;
}