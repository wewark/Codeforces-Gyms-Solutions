// 2018 USP-ICMC
// 101875I

#include <bits/stdc++.h>
#include <ext/hash_set>
#include <ext/numeric>

using namespace __gnu_cxx;
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;
using vb = vector<bool>;
using vs = vector<string>;
const int MOD = (int) 1e9 + 7;
const long double EPS = 1e-4;
const double PI = 3.1415926535897932384626433;
const ll INF = 1e9;
int di[] = {0, 0, 1, -1};
int dj[] = {1, -1, 0, 0};
#define all(x) x.begin(),x.end()

int n;
vvi adj;
vii rng;

void dfs(int node, int& ci) {
	rng[node].first = ci++;
	for (auto& i : adj[node])
		dfs(i, ci);
	rng[node].second = ci - 1;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int q; cin >> n >> q;
	adj.assign(n, vi());
	vi prnt(n);
	for (int i = 0; i < n; ++i) {
		int p; cin >> p;
		prnt[i] = p;
		if (~p)
			adj[p].push_back(i);
	}

	rng.resize(n);
	int idx = 0;
	for (int i = 0; i < n; ++i) {
		if (prnt[i] == -1) {
			dfs(i, idx);
		}
	}

	while (q--) {
		int x, y; cin >> x >> y;
		idx = rng[x].first;
		if (idx >= rng[y].first && idx <= rng[y].second)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
}