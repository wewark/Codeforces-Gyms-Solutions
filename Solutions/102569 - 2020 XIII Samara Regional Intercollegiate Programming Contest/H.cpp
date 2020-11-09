// 2020 XIII Samara Regional Intercollegiate Programming Contest
// 102569H

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vb = vector<bool>;
using pii = pair<int, int>;
using vii = vector<pii>;
using vs = vector<string>;
#define all(x) x.begin(), x.end()
// int di[] = {0, 1, 0, -1};
// int dj[] = {1, 0, -1, 0};
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const double PI = 3.14159265359;



int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#else
	//	freopen("document.in", "r", stdin);
//	freopen("document.out", "w", stdout);
#endif

	int n; cin >> n;
	vvi adj(n);
	for (int i = 0; i < n - 1; ++i) {
		int u, v; cin >> u >> v;
		u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int ch = 0;
	for (auto& i : adj) {
		if (i.size() == 1)
			ch++;
	}

	cout << (ch + 1) / 2 << endl;
}
