// 2012-2013 ACM-ICPC Central Europe Regional Contest (CERC 12)
// 100624J

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
#define SZ(x) (int)(x).size()

#include <ext/hash_set>
#include <ext/numeric>

#define  fr first
#define  sc second

const int N = 1e5 + 5;
int n, m;
vvi adj;
int lab[N];
vi prnts(N);

int solve(int cl) {
	vi l[2];
	for (int i = 0; i < n; ++i)
		if (prnts[i] == 0)
			l[lab[i]].push_back(i);

	int ret = 0;
	while (!(l[cl].empty() && l[!cl].empty())) {
		ret++;
		while (!l[cl].empty()) {
			int u = l[cl].back();
			l[cl].pop_back();
			for (int i = 0; i < adj[u].size(); ++i) {
				int v = adj[u][i];
				prnts[v]--;
				if (prnts[v] == 0)
					l[lab[v]].push_back(v);
			}
		}
		cl = !cl;
	}
	return ret - 1;
}



int main() {
//	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int t; cin >> t;
	while (t--) {
		scanf("%d%d", &n, &m);
		adj.assign(n + 5, vi());
		for (int i = 0; i < n; ++i) {
			scanf("%d", &lab[i]);
			lab[i]--;
		}
		for (int i = 0; i < m; ++i) {
			int u, v;
			scanf("%d %d", &u, &v);
			u--, v--;
			adj[u].push_back(v);
			prnts[v]++;
		}


		vi oprnts = prnts;
		int r = solve(0);
		prnts = oprnts;
		r = min(r, solve(1));
		printf("%d\n", r);
	}
	return 0;
}
