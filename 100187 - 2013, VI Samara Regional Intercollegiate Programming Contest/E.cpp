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
const int di[] = { -1,0,1,0 };
const int dj[] = { 0,1,0,-1 };
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
#define mp make_pair
#define all(x) x.begin(),x.end()

int n, m; vs g1, g2;

bool valid(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

int bfsBoth() {
	queue<pair<pii, int>> q; q.push(mp(mp(0, 0), 0));
	vector<vb> vis(n, vb(m));
	vis[0][0] = true;
	while (!q.empty()) {
		pii cur = q.front().first;
		int d = q.front().second;
		q.pop();

		if (cur == mp(n - 1, m - 1))
			return d;

		for (int i = 0; i < 4; i++) {
			int cx = cur.first + di[i];
			int cy = cur.second + dj[i];
			if (valid(cx, cy) &&
				!vis[cx][cy] && g1[cx][cy] == '.' && g2[cx][cy] == '.') {
				vis[cx][cy] = true;
				q.push(mp(mp(cx, cy), d + 1));
			}
		}
	}
	return false;
}

int bfs(vs& cg) {
	queue<pair<pii, int>> q; q.push(mp(mp(0, 0), 0));
	vector<vb> vis(n, vb(m));
	vis[0][0] = true;
	while (!q.empty()) {
		pii cur = q.front().first;
		int d = q.front().second;
		q.pop();

		if (cur == mp(n - 1, m - 1))
			return d;

		for (int i = 0; i < 4; i++) {
			int cx = cur.first + di[i];
			int cy = cur.second + dj[i];
			if (valid(cx, cy) &&
				!vis[cx][cy] && cg[cx][cy] == '.') {
				vis[cx][cy] = true;
				q.push(mp(mp(cx, cy), d + 1));
			}
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m;
	g1.resize(n), g2.resize(n);
	for (int i = 0; i < n; i++)
		cin >> g1[i];
	for (int i = 0; i < n; i++)
		cin >> g2[i];
	int both = bfsBoth(), d1 = bfs(g1), d2 = bfs(g2);
	cout << (both == d1 && both == d2 ? "YES" : "NO") << endl;
	cin.ignore(), cin.get();
}
