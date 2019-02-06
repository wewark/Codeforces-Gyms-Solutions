// 2018 German Collegiate Programming Contest (GCPC 18)
// 102021K

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
int di[] = {0, 0, 0, 1, -1, 1, -1, 1, -1};
int dj[] = {0, 1, -1, 0, 0, 1, -1, -1, 1};
#define all(x) x.begin(),x.end()

int N, g;
vi num;

inline bool valid(double& x, double& sum, int& n) {
	return sum - x * (n + 1) >= g;
}

double BS(double sum, int n) {
	if (sum - 5.0 * (n + 1) > g || sum < g)
		return -0.5;

	double a = 0, b = 5.0, mid = (a + b) / 2.0;
	for (int i = 0; i < 200; ++i) {
		if (valid(mid, sum, n))
			a = mid;
		else
			b = mid;
		mid = (a + b) / 2.0;
	}
	return mid;
}

double mem[62][62][1500];
double solve(int idx, int n, int sum) {
	if (sum > 1500) return -0.5;
	if (idx == N) return BS(sum, n);

	double& ret = mem[idx][n][sum];
	if (ret > -0.7) return ret;

	ret = solve(idx + 1, n, sum);
	ret = max(ret, solve(idx + 1, n + 1, sum + num[idx]));
	return ret;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	for (auto &i : mem) {
		for (auto &j : i) {
			for (double &k : j) {
				k = -1;
			}
		}
	}

	cin >> N >> g;
	num.resize(N);
	for (int i = 0; i < N; ++i) {
		cin >> num[i];
	}

	if (solve(0, 0, 10) > -0.25)
		cout << fixed << setprecision(10) << solve(0, 0, 10) << endl;
	else
		cout << "impossible" << endl;
}
