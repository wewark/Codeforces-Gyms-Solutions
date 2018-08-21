// 101401 - 2017 PSUT Coding Marathon
// 101401H

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
const ll INF = 1e11;
const double EPS = 1e-11;
#define mp make_pair
#define all(x) x.begin(),x.end()

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int n, m; cin >> n >> m;
	vi pos(n + 1);
	for (int i = 0; i < n; ++i) {
		int x; cin >> x;
		pos[x] = i;
	}

	int r = 0;
	for (int i = 0; i < m; ++i) {
		int a, b; cin >> a >> b;
		int mn = min(pos[a], pos[b]), mx = max(pos[a], pos[b]);
		int d1 = mx - mn - 1, d2 = n - mx + mn - 1;
		if (!(d1 % 2 == 0 && d2 % 2 == 0))
			r++;
	}
	cout << r << endl;
}
