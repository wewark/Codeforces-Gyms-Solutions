// 101673 - 2017-2018 ACM-ICPC East Central North America Regional Contest (ECNA 2017)
// 101673H

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
#define mp make_pair
#define all(x) x.begin(),x.end()

int n, m;
vs g;
vector<vb> vis;

inline bool valid(int i, int j) {
	return i >= 0 && i < n && j >= 0 && j < m;
}

void dfs(int cx, int cy) {
	vis[cx][cy] = true;
	for (int i = 0; i < 8; i++) {
		int ux = cx + di[i];
		int uy = cy + dj[i];
		if (valid(ux, uy) && !vis[ux][uy] && g[ux][uy] == '#')
			dfs(ux, uy);
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m;
	g.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> g[i];
	}

	vis.assign(n, vb(m));
	int r = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (g[i][j] == '#' && !vis[i][j]) {
				r++;
				dfs(i, j);
			}
		}
	}
	cout << r << endl;
	//cin.ignore(), cin.get();
}
