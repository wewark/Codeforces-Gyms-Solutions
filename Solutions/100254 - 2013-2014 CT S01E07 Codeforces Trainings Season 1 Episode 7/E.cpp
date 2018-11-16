// 2013-2014 CT S01E07 Codeforces Trainings Season 1 Episode 7
// 100254E

#pragma GCC optimize ("O3")

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
const ll MOD = 1e9 + 7;
const long double EPS = 1e-5;
#define all(x) x.begin(),x.end()

#include <ext/hash_set>
#include <ext/numeric>

#define  fr first
#define  sc second
typedef pair<int, pair<int, int>> piii;

const int N = 105;

vector<int> adj[N];
int done[N], power[N], doneid;
int p[N], w[N];
vector<pair<int, pair<int, int> > > edgeList;
int n;

int f(int u) {
	if (u == p[u])return u;
	return p[u] = f(p[u]);
}

void connect(int u, int v) {
	u = f(u), v = f(v);
	if (u == v)return;
	if (w[u] < w[v])swap(u, v);
	w[u] += w[v];
	p[v] = u;
}

int main() {
//	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		doneid++;
		edgeList.clear();
		for (int i = 0; i < n; i++)
			adj[i].clear(), w[i] = 1, p[i] = i;

		int id, m;
		for (int i = 0; i < n; i++) {
			scanf("%d", &id);
			scanf("%d", &power[id]);
			scanf("%d", &m);
			adj[id].resize(m);
			for (int k = 0; k < m; k++) {
				scanf("%d", &adj[id][k]);
			}
		}

		for (int i = 0; i < n; i++) {
			for (int nxt : adj[i]) {
				if (done[nxt] == doneid)continue;
				edgeList.push_back({power[i] + power[nxt], {i, nxt}});
			}
			done[i] = doneid;
		}

		long long ans = 0;
		sort(edgeList.rbegin(), edgeList.rend());
		for (auto &nxt : edgeList) {
			int u = nxt.second.first, v = nxt.second.second , w = nxt.first;
//			cout << u << " " << v << " " << w << endl;
			if (f(u) == f(v)) {
				ans += w;
				continue;
			}
			connect(u, v);
		}

		printf("%lld\n", ans);

	}
	return 0;
}
