// 101801 - Tishreen-CPC 2018
// 101801C

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
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const long double EPS = 1e-6;
#define all(x) x.begin(),x.end()

int n, m, k;
vvi g;

inline bool valid(int w, int h) {
	for (int i = h - 1; i < n; i++) {
		for (int j = w - 1; j < m; j++) {
			int x = g[i][j];
			if (i != h - 1) x -= g[i - h][j];
			if (j != w - 1) x -= g[i][j - w];
			if (i != h - 1 && j != w - 1) x += g[i - h][j - w];

			if (x <= k) return true;
		}
	}
	return false;
}

int BS(int h) {
	int a = 1, b = m, mid = (a + b + 1) / 2;
	while (a < b) {
		if (valid(mid, h))
			a = mid;
		else
			b = mid - 1;
		mid = (a + b + 1) / 2;
	}
	return mid;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> n >> m >> k;
		g.assign(n, vi(m));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> g[i][j];
				if (i) g[i][j] += g[i - 1][j];
				if (j) g[i][j] += g[i][j - 1];
				if (i && j) g[i][j] -= g[i - 1][j - 1];
			}
		}

		int r = 0;
		for (int h = 1; h <= n; h++) {
			r = max(r, h * BS(h));
		}
		cout << r << endl;
	}
	cin.ignore(), cin.get();
}
