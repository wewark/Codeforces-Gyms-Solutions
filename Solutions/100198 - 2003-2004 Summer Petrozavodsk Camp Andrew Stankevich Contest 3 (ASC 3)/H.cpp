// 2003-2004 Summer Petrozavodsk Camp Andrew Stankevich Contest 3 (ASC 3)
// 100198H

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
const ll MOD = 998244353;
const long double EPS = 1e-4;
const ll INF = 1e9;
int di[] = {0, 0, 1, -1};
int dj[] = {1, -1, 0, 0};
#define all(x) x.begin(),x.end()

struct DSU {
	vi C;
	DSU() = default;

	explicit DSU(int n) : C(n) {
		for (int i = 0; i < n; ++i)
			C[i] = i;
	}

	int find(int x) {
		return (C[x] == x) ? x : C[x] = find(C[x]);
	}

	void merge(int x, int y) {
		C[find(x)] = find(y);
	}
};

int n, B;
vvi adj;
vi sz, center;
DSU dsu;

inline void merge(int a, int b) {
	int p1 = dsu.find(a);
	int p2 = dsu.find(b);
	sz[p1] += sz[p2];
	sz[p2] = sz[p1];
	dsu.merge(p1, p2);
}

void dfs(int node, int prnt = -1) {
	priority_queue<pii, vii, greater<>> pq;
	for (int& i : adj[node]) {
		if (i != prnt) {
			dfs(i, node);
			if (sz[dsu.find(i)] < B)
				pq.emplace(sz[dsu.find(i)], i);
		}
	}

	while (pq.size() > 1) {
		int a = pq.top().second; pq.pop();
		int b = pq.top().second; pq.pop();
		merge(a, b);
		if (sz[dsu.find(a)] < B)
			pq.emplace(sz[dsu.find(a)], a);
		else
			center[dsu.find(a)] = node;
	}

	sz[node] = 1;
	if (!pq.empty()) {
		merge(node, pq.top().second);
		pq.pop();
	}
}

bool done;
void dfsFix(int node, int prnt = -1) {
	for (int& i : adj[node]) {
		if (i != prnt) {
			if (dsu.find(i) != dsu.find(node)) {
				merge(i, node);
				done = true;
			}
			else dfsFix(i, node);
		}
		if (done) return;
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#else
	freopen("royal.in", "r", stdin);
	freopen("royal.out", "w", stdout);
#endif

	cin >> n >> B;
	adj.assign(n, vi());
	dsu = DSU(n);
	for (int i = 0; i < n - 1; ++i) {
		int u, v; cin >> u >> v;
		u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}


	sz.assign(n, 0);
	center.assign(n, -1);
	dfs(0);

	bool w = false;
	if (sz[dsu.find(0)] < B) {
		dfsFix(0);
		w = !done;
	}

	if (w) cout << 0 << endl;
	else {
		int c = 0;
		map<int, int> m;
		for (int i = 0; i < n; ++i) {
			m[dsu.find(i)] = 0;
		}
		for (auto& i : m)
			i.second = c++;

		cout << c << endl;
		map<int, int> cnt;
		for (int i = 0; i < n; ++i) {
			cout << m[dsu.find(i)] + 1 << " \n"[i == n -1];
			if (center[dsu.find(i)] == -1)
				center[dsu.find(i)] = dsu.find(i);
			cnt[dsu.find(i)] = center[dsu.find(i)];
		}

		center.clear();
		for (auto& i : cnt)
			center.push_back(i.second);
		for (int i = 0; i < c; ++i) {
			cout << center[i] + 1 << " \n"[i == c - 1];
		}
	}
}
