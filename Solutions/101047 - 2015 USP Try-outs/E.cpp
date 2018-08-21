// 101047 - 2015 USP Try-outs
// 101047E

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
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};
const ll MOD = 1e9 + 7;
const long double EPS = 1e-10;

#define all(x) x.begin(),x.end()

const int N = 1e3 + 3;
const int INF = 1e9;
char str[N][N];
int disF[N][N];
int dis[N][N];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, m;

bool valid(int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < m && str[x][y] != '#';
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
//	freopen("cube.in", "r", stdin);
//	freopen("cube.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++)scanf("%s", str[i]);
		queue<pair<int, int>> q;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (str[i][j] == 'F') {
					q.push(make_pair(i, j));
					disF[i][j] = 0;
				}
				else {
					disF[i][j] = INF;
				}
			}
		}

		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nxtx = x + dx[i];
				int nxty = y + dy[i];
				if (valid(nxtx, nxty) && disF[nxtx][nxty] > disF[x][y] + 1) {
					disF[nxtx][nxty] = disF[x][y] + 1;
					q.push({nxtx, nxty});
				}
			}
		}


		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (str[i][j] == 'S') {
					q.push(make_pair(i, j));
					dis[i][j] = 0;
				}
				else {
					dis[i][j] = INF;
				}
			}
		}


		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nxtx = x + dx[i];
				int nxty = y + dy[i];
				if (valid(nxtx, nxty) && dis[nxtx][nxty] > dis[x][y] + 1 && dis[x][y] + 1 < disF[nxtx][nxty]) {
					dis[nxtx][nxty] = dis[x][y] + 1;
					q.push({nxtx, nxty});
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (str[i][j] == 'E') {
					puts(dis[i][j] == INF ? "N" : "Y");
				}
			}
		}
	}


	return 0;
}