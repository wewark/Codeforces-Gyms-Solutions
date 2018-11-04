// 2013-2014 CT S01E05 2007 Nordic Collegiate Programming Contest (NCPC 2007)  Selected Problems from 2009 Google Code Jam World Finals (GCJ WF 2009)
// 100240F

#include <bits/stdc++.h>
#include <ext/hash_set>
#include <ext/numeric>

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
#define all(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define fr first
#define sc second

const int N = 1005;
const int INF = 1e9 + 2;
vector<pair<int, int> > adj[N];
int p[N];
int dis[N][105];
int n, m, q;


int Dij(int st, int ed, int mxC) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= mxC; j++)
			dis[i][j] = INF;

	priority_queue<pair<int, pii>, vector<pair<int, pii> >, greater<pair<int, pii> > > pq;
	pq.push({0, {0, st}});
	dis[st][0] = 0;
	while (!pq.empty()) {
		int w = pq.top().fr;
		int node = pq.top().sc.sc;
		int c = pq.top().sc.fr;
		pq.pop();
		if (node == ed)return w;
		if (dis[node][c] < w)continue;
		if (c + 1 <= mxC && dis[node][c + 1] > w + p[node]) {
			dis[node][c + 1] = w + p[node];
			pq.push({w + p[node], {c + 1, node}});
		}

		for (auto nxt : adj[node]) {
			if (nxt.fr > c)break;
			if (dis[nxt.sc][c - nxt.fr] > w) {
				dis[nxt.sc][c - nxt.fr] = w;
				pq.push({w, {c - nxt.fr, nxt.sc}});
			}
		}
	}

	return INF;
}

int main() {
//	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &p[i]);
	}

	int x, y, d;
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &x, &y, &d);
		adj[x].push_back({d, y});
		adj[y].push_back({d, x});
	}

	for (int i = 0; i < n; i++) {
		sort(all(adj[i]));
	}

	int q, s, e, mxC;
	scanf("%d", &q);
	while (q--) {
		scanf("%d%d%d", &mxC, &s, &e);
		int ans = Dij(s, e, mxC);
		if (ans == INF)puts("impossible");
		else printf("%d\n", ans);
	}


	return 0;
}