// 101801 - Tishreen-CPC 2018
// 101801K

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
const ll MOD = 1e9 + 7;
const ll INF = 1e15;
const long double EPS = 1e-6;
#define all(x) x.begin(),x.end()

typedef pair<ll, pii> ppi;

int n, m, k;
vector<vii> adj;

vii mem(1e6 + 6, pii(-1, -1));
pii maxPrimes(int n) {
	pii& ret = mem[n];
	if (~ret.first) return ret;
	ret = pii(-1, -1);

	while (n % 2 == 0) {
		ret.second = ret.first;
		ret.first = 2;
		n /= 2;
	}
	for (ll i = 3; i * i <= n; i += 2)
		while (n % i == 0) {
			ret.second = ret.first;
			ret.first = i;
			n /= i;
		}
	if (n > 2) {
		ret.second = ret.first;
		ret.first = n;
	}
	return ret;
}

vvi dist;
ll dijkstra(int s, int e) {
	dist.assign(n, vi(k + 1, INF)); dist[s][k] = 0;
	priority_queue<ppi, vector<ppi>, greater<ppi>> pq;
	pq.emplace(0, pii(s, k));

	while (!pq.empty()) {
		ppi front = pq.top(); pq.pop();
		ll ds = front.first;
		ll u = front.second.first, st = front.second.second;

		if (ds > dist[u][st]) continue;

		for (int j = 0; j < adj[u].size(); j++) {
			pii v = adj[u][j];
			// go normally
			if (dist[u][st] + v.second < dist[v.first][st]) {
				dist[v.first][st] = dist[u][st] + v.second;
				pq.emplace(dist[v.first][st], pii(v.first, st));
			}

			// use stone
			if (st && v.second > 1) {
				pii p = maxPrimes(v.second);
				ll d = v.second / p.first + 2 * p.first;
				if (~p.second)
					d = min(d, v.second / p.second + 2 * p.second);
				if (dist[u][st] + d < dist[v.first][st - 1]) {
					dist[v.first][st - 1] = dist[u][st] + d;
					pq.emplace(dist[v.first][st - 1], pii(v.first, st - 1));
				}
			}
		}
	}
	return *min_element(all(dist[e]));
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> n >> m >> k;
		adj.assign(n, vii());
		for (int i = 0; i < m; i++) {
			int u, v, w; cin >> u >> v >> w; u--, v--;
			adj[u].emplace_back(v, w);
			adj[v].emplace_back(u, w);
		}

		int a, b; cin >> a >> b; a--, b--;
		ll r = dijkstra(a, b);

		cout << (r == INF ? -1 : r) << endl;
	}
	cin.ignore(), cin.get();
}
