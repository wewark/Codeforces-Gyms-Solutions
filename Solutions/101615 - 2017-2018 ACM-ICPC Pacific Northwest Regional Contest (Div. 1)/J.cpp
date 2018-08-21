// 101615 - 2017-2018 ACM-ICPC Pacific Northwest Regional Contest (Div. 1)
// 101615J

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
const double EPS = 1e-4;
#define mp make_pair
#define all(x) x.begin(),x.end()

int n, m;
vs g;
vii limit;

vector<vll> mem(35, vll(35, -1));
ll solve(int rw, int mx) {
	if (rw == n) return 1;

	ll& ret = mem[rw][mx];
	if (ret != -1) return ret;
	ret = 0;

	int cmx = min(mx, limit[rw].second);
	for (int i = limit[rw].first; i <= cmx; i++) {
		ret += solve(rw + 1, i);
	}

	return ret;
}

bool check() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (g[i][j] == 'B') {
				for (int k = 0; k < i; k++) {
					for (int l = 0; l < j; l++) {
						if (g[i][j] == 'R')
							return false;
					}
				}
			}
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m;
	g.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> g[i];
	}

	bool w = !check();
	limit.assign(n, pii(0, 0));
	if (!w) for (int i = 0; i < n; i++) {
		int c = m - 1;
		while (c >= 0 && g[i][c] != 'B') c--;
		limit[i].first = c + 1;

		c = 0;
		while (c < m && g[i][c] != 'R') c++;
		limit[i].second = c;

		if (limit[i].first > limit[i].second) {
			w = true; break;
		}
	}

	if (w) cout << 0 << endl;
	else
		cout << solve(0, m) << endl;
	cin.ignore(), cin.get();
}
