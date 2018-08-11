#include <bits/stdc++.h>
#include <ext/numeric>

using namespace std;
using namespace __gnu_cxx;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<bool> vb;
typedef vector<string> vs;
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const long double EPS = 1e-10;

#ifndef M_PI
#define M_PI 3.1415926535897932384626433832795
#endif

#define FOR(i, a, b) for(int i=(a);i<(b);i++)
#define pb push_back
#define sz(v) (int)v.size()
#define all(c) (c).begin(),(c).end()

const int MX = 3e3 + 30;
int n, m, k;
string a, b;
long double dp[MX][MX], cum[MX][MX];

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
//	freopen("cube.in", "r", stdin);
//	freopen("cube.out", "w", stdout);

	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m >> k;
		cin >> a >> b;
		a += "#", b += "$";

		for (int i = 0; i <= n + 1; ++i) {
			dp[i][m - 1] = dp[i][m] = dp[i][m + 1] = 0;
			cum[i][m - 1] = cum[i][m] = cum[i][m + 1] = 0;
		}

		for (int i = 0; i <= m + 1; ++i) {
			dp[n - 1][i] = dp[n][i] = dp[n + 1][i] = 0;
			cum[n - 1][i] = cum[n][i] = cum[n + 1][i] = 0;
		}


		dp[n][m] = 0;
		for (int i = n; i >= 0; --i) {
			for (int j = m; j >= 0; --j) {
				if (i == n && j == m) continue;

				long double &ret = dp[i][j];
				ret = INF;
				if (a[i] == b[j]) ret = dp[i + 1][j + 1];
				else {
					if (i < n)
						ret = min(ret, dp[i + 1][j] + 1);
					if (j < m)
						ret = min(ret, dp[i][j + 1] + 1);

					if (i == n)
						ret = min(ret, cum[i][j + 1] / (m - j) + k);
					else if (j == m)
						ret = min(ret, cum[i + 1][j] / (n - i) + k);
					else
						ret = min(ret, cum[i + 1][j + 1] / ((n - i) * (m - j)) + k);
				}
				cum[i][j] = dp[i][j] + cum[i + 1][j] + cum[i][j + 1] - cum[i + 1][j + 1];
			}
		}

		cout << fixed << setprecision(10) << dp[0][0] << "\n";
	}

	return 0;
}