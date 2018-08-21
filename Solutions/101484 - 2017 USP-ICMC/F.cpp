// 101484 - 2017 USP-ICMC
// 101484F

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
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const double EPS = 1e-5;
#define mp make_pair
#define all(x) x.begin(),x.end()

int n, m, w;
vector<vii> adj;
vvi nd, cum;
vi nodeLvl;

void cumulate() {
	for (int i = 0; i < cum.size(); i++)
		for (int j = 1; j < cum[i].size(); j++)
			cum[i][j] += cum[i][j - 1];
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m >> w;
	adj.assign(n, vii());
	nodeLvl.assign(n, 0);

	for (int i = 0; i < n - 1; i++) {
		int u, v, w; cin >> u >> v >> w;
		u--, v--;
		adj[v].push_back({ u,w });
	}

	nd.push_back({ 0 });
	cum.push_back({ w });
	for (int lvl = 0; lvl < cum.size(); lvl++) {
		bool f = false;
		for (int i = 0; i < nd[lvl].size(); i++)
			if (nd[lvl][i] != -1 && adj[nd[lvl][i]].size()) {
				cum.push_back({}), nd.push_back({});
				f = true;
				break;
			}

		if (f) for (int i = 0; i < cum[lvl].size(); i++) {
			int cur = nd[lvl][i];
			if (cur == -1) continue;
			for (int j = 0; j < adj[cur].size(); j++) {
				nd[lvl + 1].push_back(adj[cur][j].first);
				cum[lvl + 1].push_back(adj[cur][j].second);

				nodeLvl[adj[cur][j].first] = lvl + 1;
			}

			for (int j = adj[cur].size(); j < 2; j++) {
				nd[lvl + 1].push_back(-1);
				cum[lvl + 1].push_back(0);
			}
		}
	}

	cumulate();

	while (m--) {
		int x; cin >> x; x--;
		int r = 0;

		for (int i = 0; i < nodeLvl[x]; i++)
			r = max(r, cum[i].back());

		int a = 0;
		while (nd[nodeLvl[x]][a] != x) a++;

		for (int i = nodeLvl[x], sz = 1;
			i < cum.size();
			i++, a *= 2, sz *= 2) {

			int b = a + sz - 1;
			r = max(r, cum[i].back() - (cum[i][b] - (a == 0 ? 0 : cum[i][a - 1])));
		}

		cout << r << endl;
	}
	cin.ignore(), cin.get();
}
