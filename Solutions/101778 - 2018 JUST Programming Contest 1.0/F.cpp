// 101778 - 2018 JUST Programming Contest 1.0
// 101778F

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
const int di[] = { 0, 1 };
const int dj[] = { 1, 0 };
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const long double EPS = 1e-7;
#define all(n) n.begin(),n.end()

int n, m;
vector<vvi> cnt(105, vvi(105, vi(505))); // cnt[i][j][num]

void initCnt(vvi& g) {
	for (int k = 1; k < 505; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cnt[i][j][k] = g[i][j] == k;
				if (i) cnt[i][j][k] += cnt[i - 1][j][k];
				if (j) cnt[i][j][k] += cnt[i][j - 1][k];
				if (i && j) {
					cnt[i][j][k] -= cnt[i - 1][j - 1][k];
					cnt[i - 1][j - 1][k] += cnt[i - 1][j - 1][k - 1];
				}
			}
		}
		for (int j = 0; j < m; j++) {
			cnt[n - 1][j][k] += cnt[n - 1][j][k - 1];
		}
		for (int i = 0; i < n - 1; i++) {
			cnt[i][m - 1][k] += cnt[i][m - 1][k - 1];
		}
	}
}

inline int f(pii p1, pii p2, int x) {
	int ret = cnt[p2.first][p2.second][x];

	if (p1.first)
		ret -= cnt[p1.first - 1][p2.second][x];
	if (p1.second)
		ret -= cnt[p2.first][p1.second - 1][x];
	if (p1.first && p1.second)
		ret += cnt[p1.first - 1][p1.second - 1][x];

	return ret;
}

int BS(pii p1, pii p2) {
	int k = (p2.first - p1.first + 1) * (p2.second - p1.second + 1);
	k = (k + 1) / 2;
	int a = 1, b = 500, mid = (a + b) / 2;
	int c = 11;
	while (c--) {
		if (f(p1, p2, mid) >= k)
			b = mid;
		else
			a = mid + 1;
		mid = (a + b) / 2;
	}
	return mid;
}

int main() {
	//ios::sync_with_stdio(false), cin.tie(0);
	int t; //cin >> t;
	scanf("%d", &t);
	while (t--) {
		int q;
		//cin >> n >> m >> q;
		scanf("%d %d %d", &n, &m, &q);
		vvi g(n, vi(m));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf("%d", &g[i][j]);
				//cin >> g[i][j];
			}
		}

		initCnt(g);

		while (q--) {
			pii p[2];
			for (int i = 0; i < 2; i++) {
				scanf("%d %d", &p[i].first, &p[i].second);
				//cin >> p[i].first >> p[i].second;
				p[i].first--, p[i].second--;
			}

			printf("%d\n", BS(p[0], p[1]));
			//cout << BS(p[0], p[1]) << endl;
		}
	}
	cin.ignore(), cin.get();
}
