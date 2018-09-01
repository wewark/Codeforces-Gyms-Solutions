// 2015-2016 ACM-ICPC Nordic Collegiate Programming Contest (NCPC 2015)
// 100781G

#include <bits/stdc++.h>
#include <ext/hash_map>
#include <ext/hash_set>

#define fr first
#define sc second

using namespace __gnu_cxx;
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<ll, ll> pii;
const int MOD = 1e9 + 7;

const int N = 1e5 + 5;

const int M = 10001;

bool g[M][M];
int n, m;
int x[N], y[N];

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
#endif
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}
	cin >> m;
	for (int k = 0; k < m; k++) {
		int xx, yy, rr;
		cin >> xx >> yy >> rr;
		int stX = max(xx - rr, 0), enX = min(xx + rr, M - 1);
		int stY = max(yy - rr, 0), enY = min(yy + rr, M - 1);
		for (int i = stX; i <= enX; i++) {
			for (int j = stY; j <= enY; j++) {
				if ((i - xx) * (i - xx) + (j - yy) * (j - yy) <= rr * rr) {
					g[i][j] = 1;
				}
			}
		}
	}
	int res = 0;
	for (int i = 0; i < n; i++) {
		res += !g[x[i]][y[i]];
	}
	cout << res << endl;
}