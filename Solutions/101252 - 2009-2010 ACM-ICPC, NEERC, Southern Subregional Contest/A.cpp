// 101252 - 2009-2010 ACM-ICPC, NEERC, Southern Subregional Contest
// 101252A

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
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
#define all(x) x.begin(),x.end()
#define x first
#define y second

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	int n, m; cin >> n >> m;
	vs g(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> g[i];
		g[i] += '0';
	}
	g.back() = string(m, '0');
	string s; cin >> s;

	int dir = 0, r = 0;
	pii p(0, 0);
	map<pii, bool> vis;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'M') {
			if (dir == 0) {
				r += (g[p.x][p.y] - '0') / (vis[p] ? 2 : 1);
				if (p.x - 1 >= 0)
					r += (g[p.x - 1][p.y] - '0') / (vis[{p.x - 1, p.y}] ? 2 : 1);
				vis[p] = vis[{p.x - 1, p.y}] = true;
				p.y++;
			}
			else if (dir == 1) {
				r += (g[p.x][p.y] - '0') / (vis[p] ? 2 : 1);
				if (p.y - 1 >= 0)
					r += (g[p.x][p.y - 1] - '0') / (vis[{p.x, p.y - 1}] ? 2 : 1);
				vis[p] = vis[{p.x, p.y - 1}] = true;
				p.x++;
			}
			else if (dir == 2) {
				if (p.x - 1 >= 0 && p.y - 1 >= 0)
					r += (g[p.x - 1][p.y - 1] - '0') / (vis[{p.x - 1, p.y - 1}] ? 2 : 1);
				if (p.y - 1 >= 0)
					r += (g[p.x][p.y - 1] - '0') / (vis[{p.x, p.y - 1}] ? 2 : 1);
				vis[{p.x - 1, p.y - 1}] = vis[{p.x, p.y - 1}] = true;
				p.y--;
			}
			else if (dir == 3) {
				if (p.x - 1 >= 0 && p.y - 1 >= 0)
					r += (g[p.x - 1][p.y - 1] - '0') / (vis[{p.x - 1, p.y - 1}] ? 2 : 1);
				if (p.x - 1 >= 0)
					r += (g[p.x - 1][p.y] - '0') / (vis[{p.x - 1, p.y}] ? 2 : 1);
				vis[{p.x - 1, p.y - 1}] = vis[{p.x - 1, p.y}] = true;
				p.x--;
			}
		}
		else if (s[i] == 'R')
			dir++, dir %= 4;
		else dir--, dir += 4, dir %= 4;
	}
	cout << r << endl;
	cin.ignore(), cin.get();
}
