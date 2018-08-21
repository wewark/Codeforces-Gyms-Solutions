// 101755 - 2018, XI Samara Regional Intercollegiate Programming Contest
// 101755H

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
const int di[] = { -1, 0, 1, 0, -1, 1, 1, -1 };
const int dj[] = { 0, 1, 0, -1, -1, 1, -1, 1 };
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const long double EPS = 1e-10;
#define all(n) n.begin(),n.end()

int n, m, d;
vs g;

struct State {
	int x, y, d;
};

inline bool valid(int i, int j) {
	return i >= 0 && i < n && j >= 0 && j < m;
}

void bfsMonsters() {
	queue<State> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (g[i][j] == 'M')
				q.push(State{ i,j,d });
		}
	}

	while (!q.empty()) {
		State cur = q.front(); q.pop();

		g[cur.x][cur.y] = 'M';
		if (!cur.d) continue;

		for (int i = 0; i < 4; i++) {
			int cx = cur.x + di[i];
			int cy = cur.y + dj[i];
			if (valid(cx, cy) && (g[cx][cy] == '.' || g[cx][cy] == 'S' || g[cx][cy] == 'F')) {
				g[cx][cy] = 'M';
				q.push(State{ cx, cy, cur.d - 1 });
			}
		}
	}
}

int bfs() {
	queue<State> q;
	for (int i = 0; i < n && q.empty(); i++) {
		for (int j = 0; j < m && q.empty(); j++) {
			if (g[i][j] == 'S')
				q.push(State{ i,j,0 });
		}
	}

	vector<vb> vis(n, vb(m));
	while (!q.empty()) {
		State cur = q.front(); q.pop();

		if (g[cur.x][cur.y] == 'F') return cur.d;
		vis[cur.x][cur.y] = true;
		
		for (int i = 0; i < 4; i++) {
			int cx = cur.x + di[i];
			int cy = cur.y + dj[i];
			if (valid(cx, cy) && !vis[cx][cy] && (g[cx][cy] == '.' || g[cx][cy] == 'F')) {
				vis[cx][cy] = true;
				q.push(State{ cx, cy, cur.d + 1 });
			}
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m >> d;
	g.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> g[i];
	}

	bfsMonsters();
	cout << bfs() << endl;
	cin.ignore(), cin.get();
}
