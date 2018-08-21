// 101170 - 2016-2017 ACM-ICPC Northwestern European Regional Programming Contest (NWERC 2016)
// 101170I

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
const ll MOD = 5e6;
const ll INF = 1e8;
const double EPS = 1e-12;
#define mp make_pair
#define all(x) x.begin(),x.end()

int n, m, k;
vvi adj, adjInv;
vb ore, coal;
vi ored, coald, dist;

void bfsOre() {
	queue<pii> q; //(idx,d)
	ored.assign(n, INF);
	for (int i = 0; i < n; i++)
		if (ore[i]) {
			q.push({ i,0 });
			ored[i] = 0;
		}

	while (!q.empty()) {
		int cur = q.front().first;
		int d = q.front().second;
		q.pop();

		for (int i = 0; i < adjInv[cur].size(); i++) {
			int v = adjInv[cur][i];
			if (ored[v] == INF) {
				ored[v] = d + 1;
				q.push({ v,d + 1 });
			}
		}
	}
}

void bfsCoal() {
	queue<pii> q; //(idx,d)
	coald.assign(n, INF);
	for (int i = 0; i < n; i++)
		if (coal[i]) {
			q.push({ i,0 });
			coald[i] = 0;
		}

	while (!q.empty()) {
		int cur = q.front().first;
		int d = q.front().second;
		q.pop();

		for (int i = 0; i < adjInv[cur].size(); i++) {
			int v = adjInv[cur][i];
			if (coald[v] == INF) {
				coald[v] = d + 1;
				q.push({ v,d + 1 });
			}
		}
	}
}

void bfsDist() {
	dist.assign(n, INF);
	queue<pii> q; q.push({ 0,0 }); //(idx,d)
	dist[0] = 0;

	while (!q.empty()) {
		int cur = q.front().first;
		int d = q.front().second;
		q.pop();

		for (int i = 0; i < adj[cur].size(); i++) {
			int v = adj[cur][i];
			if (dist[v] == INF) {
				dist[v] = d + 1;
				q.push({ v,d + 1 });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m >> k;
	adj.assign(n, vi());
	adjInv.assign(n, vi());
	ore.assign(n, false); coal = ore;

	for (int i = 0; i < m; i++) {
		int x; cin >> x; x--;
		ore[x] = true;
	}
	for (int i = 0; i < k; i++) {
		int x; cin >> x; x--;
		coal[x] = true;
	}
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		for (int j = 0; j < x; j++) {
			int v; cin >> v; v--;
			adj[i].push_back(v);
			adjInv[v].push_back(i);
		}
	}

	bfsOre(), bfsCoal(), bfsDist();
	int r = INF;
	for (int i = 0; i < n; i++) {
		r = min(r, dist[i] + ored[i] + coald[i]);
	}
	if (r >= INF)
		cout << "impossible\n";
	else
		cout << r << endl;
	cin.ignore(), cin.get();
}
