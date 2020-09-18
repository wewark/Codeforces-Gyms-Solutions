// CCPC 2016-2017 Finals
// 101206I
// Dynamic programming, Dijkstra

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
const int MOD = int(1e9 + 7);
const long double EPS = 1e-8;
const double PI = acos(-1.0);
const ll INF = ll(1e9);
int di[] = {0, 1, 0, -1};
int dj[] = {1, 0, -1, 0};
#define all(x) x.begin(),x.end()

const int M = 1e4 + 4, N = 202;

bool direct[N];
int price[N], magic[N];
int equResult[N];
vii equ[N]; // (type, qty)
vvi inEqu; // in which equations
int n, m, k;
vi cost;

void dijkstra() {
	priority_queue<pii, vii, greater<>> pq;
	for (int i = 0; i < n; ++i) {
		if (cost[i] != INF) {
			pq.emplace(cost[i], i);
		}
	}

	while(!pq.empty()) {
		pii tmp = pq.top();
		int cur = tmp.second, d = tmp.first;
		pq.pop();

		if (d > cost[cur])
			continue;

		for (auto& i : inEqu[cur]) {
			int curCost = 0;
			bool good = true;
			for (auto& p : equ[i]) {
				if (cost[p.first] == INF) {
					good = false;
					break;
				}
				curCost += cost[p.first] * p.second;
			}

			if (good && curCost < cost[equResult[i]] && curCost <= m) {
				cost[equResult[i]] = curCost;
				pq.emplace(curCost, equResult[i]);
			}
		}
	}
}

int mem[N][M];
int vis[N][M], vf = 0;
int solve(int idx, int mleft) {
	if (idx == n)
		return 0;

	int& ret = mem[idx][mleft];
	if (vis[idx][mleft] == vf)
		return ret;
  vis[idx][mleft] = vf;
	ret = solve(idx + 1, mleft);
	if (cost[idx] <= mleft) {
		ret = max(ret, solve(idx, mleft - cost[idx]) + price[idx]);
	}

	return ret;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int t, tt = 0;
	cin >> t;
	while (t--) {
		vf++;
		cin >> m >> n >> k;
		cost.assign(n, INF);
		inEqu.assign(n, vi());
		for (int i = 0; i < n; ++i) {
			int dir; cin >> dir;
			if (dir) {
				direct[i] = true;
				cin >> cost[i];
			}
			cin >> price[i];
		}

		for (int i = 0; i < k; ++i) {
			int resultType, sz;
			cin >> resultType >> sz;
			resultType--;
			equ[i].resize(sz);
			equResult[i] = resultType;
			for (int j = 0; j < sz; ++j) {
				int tp, cnt;
				cin >> tp >> cnt;
				tp--;
				inEqu[tp].push_back(i);
				equ[i][j] = pii(tp, cnt);
			}
		}

		dijkstra();

		cout << "Case #" << ++tt << ": ";
		cout << solve(0, m) << endl;
	}
}
