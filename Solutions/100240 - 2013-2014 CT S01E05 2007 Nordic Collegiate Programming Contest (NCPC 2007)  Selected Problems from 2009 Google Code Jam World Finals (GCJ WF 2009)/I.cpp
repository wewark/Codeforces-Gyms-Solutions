// 2013-2014 CT S01E05 2007 Nordic Collegiate Programming Contest (NCPC 2007)  Selected Problems from 2009 Google Code Jam World Finals (GCJ WF 2009)
// 100240I

#include <bits/stdc++.h>
#include <ext/hash_set>
#include <ext/numeric>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<bool> vb;
typedef vector<string> vs;
const ll MOD = 1e9 + 7;
const long double EPS = 1e-5;
const ll INF = 1e9;
#define all(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define fr first
#define sc second

const int MAXN = 202;
int n, c;
int x[MAXN];
double err[MAXN][MAXN];

int vis[MAXN][MAXN], vf = 0;
double mem[MAXN][MAXN];
double solve(int idx, int left) {
	if (idx == n - 1) return left ? INF : 0;
	if (!left) return INF;

	if (vis[idx][left] == vf) return mem[idx][left];
	vis[idx][left] = vf;

	double ret = INF;
	for (int i = idx + 1; i < n; ++i) {
		ret = min(ret, err[idx][i] + solve(i, left - 1));
	}
	return mem[idx][left] = ret;
}

inline double interPos(int i, int k, int j) {
	return x[i] + (x[j] - x[i]) * (k - i) / double(j - i);
}

void precompute() {
	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j) {
			err[i][j] = 0;
			for (int k = i + 1; k < j; ++k) {
				err[i][j] += abs(x[k] - interPos(i, k, j));
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;
	while (t--) {
		vf++;
		cin >> n >> c;
		for (int i = 0; i < n; ++i) {
			cin >> x[i];
		}
		precompute();
		cout << fixed << setprecision(4) << solve(0, c - 1) / double(n) << endl;
	}
	return 0;
}