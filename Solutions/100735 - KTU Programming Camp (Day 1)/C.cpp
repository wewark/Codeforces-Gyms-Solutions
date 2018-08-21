// 100735 - KTU Programming Camp (Day 1)
// 100735C

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
#define x first
#define y second

struct State {
	pii a, g;
	int dis;
};

int n, m;
vs g;
pii a, G;
bool vis[25][25][25][25];

inline bool valid(int i, int j) {
	return i >= 0 && j >= 0 && i < n && j < m && g[i][j] != 'X';
}

int bfs() {
	queue<State> q;
	q.push({ a, G, 0 });

	while (!q.empty()) {
		State cur = q.front(); q.pop();

		if (cur.a == cur.g) continue;
		if (g[cur.a.x][cur.a.y] == 'P') return cur.dis;

		for (int i = 0; i < 4; i++) {
			State v = cur;
			if (valid(v.a.x + di[i], v.a.y + dj[i])) {
				v.a.x += di[i], v.a.y += dj[i];

				if (v.a.y < v.g.y && valid(v.g.x, v.g.y - 1)) v.g.y--;
				else if (v.a.y > v.g.y && valid(v.g.x, v.g.y + 1)) v.g.y++;
				else if (v.a.x < v.g.x && valid(v.g.x - 1, v.g.y)) v.g.x--;
				else if (v.a.x > v.g.x && valid(v.g.x + 1, v.g.y)) v.g.x++;

				v.dis++;
				if (!vis[v.a.x][v.a.y][v.g.x][v.g.y]) {
					vis[v.a.x][v.a.y][v.g.x][v.g.y] = true;
					q.push(v);
				}
			}
		}
	}

	return -1;
}

void initVis() {
	for (int i = 0; i < 25; i++) for (int j = 0; j < 25; j++)
		for (int k = 0; k < 25; k++) for (int l = 0; l < 25; l++)
			vis[i][j][k][l] = false;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m;
	g.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> g[i];
		for (int j = 0; j < m; j++) {
			if (g[i][j] == 'A') a = { i,j };
			else if (g[i][j] == 'G') G = { i,j };
		}
	}

	initVis();
	cout << bfs() << endl;
	cin.ignore(), cin.get();
}
