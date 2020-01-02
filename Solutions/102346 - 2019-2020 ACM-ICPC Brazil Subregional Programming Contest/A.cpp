// 2019-2020 ACM-ICPC Brazil Subregional Programming Contest
// 102346A

#include <bits/stdc++.h>

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
const int MOD = int(998244353);
const long double EPS = 1e-8;
const double PI = acos(-1.0);
const ll INF = ll(1e9);
int di[] = {0, 1, 0, -1};
int dj[] = {1, 0, -1, 0};
#define all(x) x.begin(),x.end()

int n, m, k;
vvi adj;

inline double dist(pii a, pii b) {
	return hypot(a.first - b.first, a.second - b.second);
}

int vis[1005], vf = 1, target;
bool DFS(int node) {
	vis[node] = vf;
	if (node == target)
		return true;

	for (auto& i : adj[node]) {
		if (vis[i] != vf && DFS(i))
			return true;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	cin >> m >> n >> k;
	vi x(k), y(k), s(k);
	adj.assign(k + 4, vi());
	for (int i = 0; i < k; ++i) {
		cin >> x[i] >> y[i] >> s[i];

		for (int j = 0; j < i; ++j) {
			if (s[i] + s[j] >= dist({x[i], y[i]}, {x[j], y[j]})) {
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}

		if (x[i] - s[i] <= 0) {
			adj[i].push_back(k);
			adj[k].push_back(i);
		}
		if (x[i] + s[i] >= m) {
			adj[i].push_back(k + 1);
			adj[k + 1].push_back(i);
		}
		if (y[i] - s[i] <= 0) {
			adj[i].push_back(k + 2);
			adj[k + 2].push_back(i);
		}
		if (y[i] + s[i] >= n) {
			adj[i].push_back(k + 3);
			adj[k + 3].push_back(i);
		}
	}

	int from[] = {0,0,1,2};
	int to[] = {2,1,3,3};
	for (int i = 0; i < 4; ++i) {
		vf++, target = k + to[i];
		if (DFS(k + from[i])) {
			cout << "N" << endl;
			return 0;
		}
	}
	cout << "S" << endl;
}
