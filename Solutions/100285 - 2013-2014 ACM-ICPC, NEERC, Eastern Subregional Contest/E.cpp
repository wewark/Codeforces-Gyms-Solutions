// 100285 - 2013-2014 ACM-ICPC, NEERC, Eastern Subregional Contest
// 100285E

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
const ll MOD = 5e6;
const ll INF = 1e8;
const long double EPS = 1e-6;
#define mp make_pair
#define all(x) x.begin(),x.end()

long double nCr[205][205];
vector<vector<double>> mem(205, vector<double>(21, -1));
double solve(int n, int k) {
	if (n <= k) return 0;
	if (k == 0) return n;

	double &ret = mem[n][k];
	if (ret > -0.8) return ret;
	ret = 0;

	for (int i = 0; i < n; ++i) {
		double x = 0;
		for (int j = 0; j <= min(k, i); ++j) {
			long double prob = nCr[n - k][i - j] * nCr[k][j] / nCr[n][i];
			int left = max(0, n - k - i + j);
			x += prob * solve(left, k - j);
		}
		if (x > ret) ret = x;
	}
	return ret;
}

void init() {
	for (int i = 0; i < 205; i++)
		for (int j = 0; j <= i; j++) {
			if (i == j || j == 0) nCr[i][j] = 1;
			else if (i) nCr[i][j] = nCr[i][j - 1] * (i - j + 1) / j;
			else if (i < j) nCr[i][j] = nCr[i - 1][j] * i / (i - j);
			else nCr[i][j] = nCr[i - 1][j - 1] * i / j;
		}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int n, k;
	cin >> n >> k;
	init();
	cout << fixed << setprecision(10) << solve(n - k, k) << endl;
	cin.ignore(), cin.get();
}
