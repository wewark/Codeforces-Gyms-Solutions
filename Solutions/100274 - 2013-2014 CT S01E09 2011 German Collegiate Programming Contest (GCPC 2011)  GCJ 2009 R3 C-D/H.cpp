// 2013-2014 CT S01E09 2011 German Collegiate Programming Contest (GCPC 2011)  GCJ 2009 R3 C-D
// 100274H

#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<bool> vb;
typedef vector<string> vs;
const int di[] = {0, 0, 1, -1};
const int dj[] = {1, -1, 0, 0};
const ll MOD = 1e9 + 7;
const long double EPS = 1e-5;
#define all(x) x.begin(),x.end()

#include <ext/hash_set>
#include <ext/numeric>

const int N = 100005;

int n, T;
int L[N];
int a[N][2][2];
ll dp[N][2];
int vis[N][2];
int vid;
string ans = "FB";
string res;

ll calc(int idx, bool c) {
	if (idx == n)
		return 0;
	ll &ret = dp[idx][c];
	if (vis[idx][c] == vid)
		return ret;
	vis[idx][c] = vid;
	ret = min(calc(idx + 1, 0) + a[idx][!c][0], calc(idx + 1, 1) + a[idx][!c][1]) + L[idx];
	return ret;
}

void build(int idx, bool c) {
	if (idx == n)
		return;
	res += ans[c];
	ll ret = dp[idx][c] - L[idx];
	if (ret == calc(idx + 1, 0) + a[idx][!c][0])
		build(idx + 1, 0);
	else
		build(idx + 1, 1);
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int t;
	cin >> t;
	while (t--) {
		cin >> n >> T;
		for (int i = 0; i < n; i++) {
			cin >> L[i];
			for (int j = 0; j < 2; j++) {
				for (int k = 0; k < 2; k++) {
					cin >> a[i][j][k];
				}
			}
		}
		vid++;
		bool ok = 1;
		for (int i = 0; i < 2; i++) {
			if (calc(0, i) <= T) {
				ok = 0;
				res = "";
				build(0, i);
				cout << res << "\n";
				break;
			}
		}
		if (ok) {
			cout << "IMPOSSIBLE\n";
		}
	}

	return 0;
}