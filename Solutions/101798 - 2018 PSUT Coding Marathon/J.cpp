// 101798 - 2018 PSUT Coding Marathon
// 101798J

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
const int di[] = { 0, 0, 1, -1 };
const int dj[] = { 1, -1, 0, 0 };
const ll MOD = 1e9 + 9;
const ll INF = 1e9;
const long double EPS = 1e-7;
#define all(n) n.begin(),n.end()

int n, m;
vs g;

inline bool valid(int i, int j) {
	return i >= 0 && i < n * 2 - 1 && j >= 0 && j < m * 2 - 1;
}

inline int closedEdges(int i, int j) {
	int c = 0;
	for (int k = 0; k < 4; k++) {
		int x = i + di[k];
		int y = j + dj[k];
		if (g[x][y] == '|' || g[x][y] == '-')
			c++;
	}
	return c;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m;
	g.resize(n * 2 - 1);
	for (int i = 0; i < 2 * n - 1; i++) {
		cin >> g[i];
	}

	queue<pii> q;
	for (int i = 1; i < 2 * n - 1; i += 2) {
		for (int j = 1; j < 2 * m - 1; j += 2) {
			q.emplace(i, j);
		}
	}

	while (!q.empty()) {
		int i = q.front().first;
		int j = q.front().second;
		q.pop();

		if (g[i][j] == 'x') continue;

		if (closedEdges(i, j) == 3) {
			for (int k = 0; k < 4; k++) {
				int x = i + di[k];
				int y = j + dj[k];
				if (g[x][y] == '.') {
					g[x][y] = '|';
					if (valid(x + di[k], y + dj[k]))
						q.emplace(x + di[k], y + dj[k]);
					break;
				}
			}
		}
	}

	int r = 0;
	for (int i = 1; i < 2 * n - 1; i += 2) {
		for (int j = 1; j < 2 * m - 1; j += 2) {
			if (g[i][j] == 'x') continue;
			r += closedEdges(i, j) == 4;
		}
	}

	cout << r << endl;
	cin.ignore(), cin.get();
}
