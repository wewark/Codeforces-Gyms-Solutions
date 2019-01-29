// 2018 USP-ICMC
// 101875E

#include <bits/stdc++.h>
#include <ext/hash_set>
#include <ext/numeric>

using namespace __gnu_cxx;
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;
using vb = vector<bool>;
using vs = vector<string>;
const int MOD = int(1e9 + 7);
const long double EPS = 1e-4;
const double PI = 3.1415926535897932384626433;
const ll INF = ll(1e9);
int di[] = {0, 0, 1, -1};
int dj[] = {1, -1, 0, 0};
#define all(x) x.begin(),x.end()

int n, k;
string s;

const int N = 451;
int dp[2][N][N];

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	cin >> n >> k >> s;

	for (int idx = n - 1; idx >= 0; --idx) {
		for (int cnt = 0; cnt < n; ++cnt) {
			for (int left = 0; left < n; ++left) {
				dp[idx & 1][cnt][left] = INF;
				if (s[idx] == '1') {
					dp[idx & 1][cnt][left] = min(dp[idx & 1][cnt][left], cnt + 1 + dp[(idx + 1) & 1][cnt + 1][left]);
					if (left)
						dp[idx & 1][cnt][left] = min(dp[idx & 1][cnt][left], dp[(idx + 1) & 1][0][left - 1]);
				}
				else {
					dp[idx & 1][cnt][left] = min(dp[idx & 1][cnt][left], dp[(idx + 1) & 1][0][left]);
				}
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		if (dp[0][0][i] <= k) {
			cout << i << endl;
			return 0;
		}
	}
}
