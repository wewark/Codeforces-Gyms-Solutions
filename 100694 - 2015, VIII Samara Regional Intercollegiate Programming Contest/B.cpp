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
const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, 1, 0, -1 };
const ll MOD = 998244353;
const ll INF = 1e9;
const double EPS = 1e-5;
#define mp make_pair
#define all(x) x.begin(),x.end()

int p, n, x;

map<int, vii> adj;

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> p >> n >> x;
	n++;

	int col = x - x % p;
	adj[0].push_back({ col, col / p });

	int fromEnd = abs((x % p) - ((n - 1) % p));
	fromEnd += ((n - 1 - ((n - 1) % p)) - (x - (x % p))) / p;
	adj[n - 1].push_back({ x,fromEnd });

	if (n - 1 < p)
		adj[0].push_back({ n - 1, 1 });
	else {
		adj[0].push_back({ n - 1, (n - 1) / p + 1 });
		adj[0].push_back({ p - 1, 2 });
		adj[p - 1].push_back({ col - 1 + p, col / p });
	}

	adj[col].push_back({ x,x - col });
	if (col + p - 1 < n - 1)
		adj[col + p - 1].push_back({ x, col + p - 1 - x });
	else
		adj[n - 1].push_back({ x, n - 1 - x });

	// Dijkstra
	map<int, int> dist; dist[0] = 0;
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push(pii(0, 0));

	while (!pq.empty()) {
		pii front = pq.top(); pq.pop();
		int d = front.first, u = front.second;
		if (dist.find(u) != dist.end() && d > dist[u]) continue;

		for (int j = 0; j < adj[u].size(); j++) {
			pii v = adj[u][j];
			if (dist.find(v.first) == dist.end() || dist[u] + v.second < dist[v.first]) {
				dist[v.first] = dist[u] + v.second;
				pq.push(pii(dist[v.first], v.first));
			}
		}
	}
	cout << dist[x] << endl;
	cin.ignore(), cin.get();
}
