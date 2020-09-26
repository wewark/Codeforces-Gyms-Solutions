// 2019-2020 ICPC Southwestern European Regional Programming Contest (SWERC 2019-20)
// 102501A - Dynamic programming

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
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
#define x first
#define y second

pii house, dest;
int B, T, n;
int C[105], dist[1005][1005];
pii pos[1005];
vii adj[1005];

void initDist() {
	for (int i = 0; i <= n + 1; ++i) {
		pii a = pos[i];
		for (int j = i + 1; j <= n + 1; ++j) {
			pii b = pos[j];
			dist[i][j] = dist[j][i] = ceil(hypot((a.x - b.x), (a.y - b.y)));
		}
	}
}

int mem[1005][105];
int solve(int st, int bleft) {
	if (bleft < 0) return INF;

	int& ret = mem[st][bleft];
	if (~ret) return ret;

	ret = INF;
	if (dist[st][n + 1] <= bleft)
		ret = dist[st][n + 1] * C[0];
	for (auto& i : adj[st]) {
		int d = dist[st][i.first];
		ret = min(ret,
			solve(i.first, bleft - d)
			+ d * C[i.second]);
	}
	return ret;
}

int main(int argc, char **argv) {
	ios::sync_with_stdio(false), cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	memset(mem, -1, sizeof(mem));

	cin >> house.x >> house.y;
	cin >> dest.x >> dest.y;
	cin >> B >> C[0] >> T;
	for (int i = 1; i <= T; ++i) {
		cin >> C[i];
	}
	cin >> n;
	pos[n] = house;
	pos[n + 1] = dest;
	for (int i = 0; i < n; ++i) {
		cin >> pos[i].x >> pos[i].y;
		int sz; cin >> sz;
		for (int j = 0; j < sz; ++j) {
			int v, m; cin >> v >> m;
			adj[i].emplace_back(v, m);
			adj[v].emplace_back(i, m);
		}
	}

	initDist();

	int ans = INF;
	if (dist[n][n + 1] <= B)
		ans = dist[n][n + 1] * C[0];
	for (int i = 0; i < n; ++i) {
		int cur = dist[n][i] * C[0];
		int s = solve(i, B - dist[n][i]);
		if (s >= INF) continue;
		ans = min(ans, cur + s);
	}
	cout << (ans < INF ? ans : -1) << endl;
}
