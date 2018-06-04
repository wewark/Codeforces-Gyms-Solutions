#include <bits/stdc++.h>

using namespace std;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int r, c;

bool valid(int i, int j) {
	return i >= 0 && j >= 0 && i < r && j < c;
}

const int N = 51;
const int M = 1e4 + 1;

bool memo[M][N][N];
string s;
int adj[N][N][4]; // step
string keyboard[N];

struct State {
	int i,j,idx, dist;
};

int bfs() {
	queue<State> q; q.push(State{0,0,0,0});

	while (!q.empty()) {
		State cur = q.front(); q.pop();

		while (cur.idx < s.length() && keyboard[cur.i][cur.j] == s[cur.idx])
			cur.idx++;

		if (cur.idx == s.length())
			return cur.dist;

		for (int i = 0; i < 4; ++i) {
			if (!adj[cur.i][cur.j][i]) continue;
			int x = cur.i + dx[i] * adj[cur.i][cur.j][i];
			int y = cur.j + dy[i] * adj[cur.i][cur.j][i];

			if (!memo[cur.idx][x][y]) {
				memo[cur.idx][x][y] = true;
				q.push(State{x,y,cur.idx, cur.dist + 1});
			}
		}
	}
	return -1;
}


int main() {
	cin >> r >> c;
	for (int i = 0; i < r; i++)
		cin >> keyboard[i];
	cin >> s;
	s += '*';

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			for (int k = 0; k < 4; k++) {

				int step = 0;
				for (int factor = 1;; ++factor) {
					int ii = i + factor * dx[k], jj = j + factor * dy[k];
					if (!valid(ii, jj))
						break;
					++step;
					if (keyboard[i][j] != keyboard[ii][jj]) {
						adj[i][j][k] = step;
						break;
					}
				}
			}
		}
	}
	cout << bfs() + s.size() << endl;
}
