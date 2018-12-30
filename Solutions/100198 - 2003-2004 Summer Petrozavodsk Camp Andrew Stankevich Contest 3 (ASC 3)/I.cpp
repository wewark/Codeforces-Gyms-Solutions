// 2003-2004 Summer Petrozavodsk Camp Andrew Stankevich Contest 3 (ASC 3)
// 100198I

#include <bits/stdc++.h>
#include <ext/hash_set>
#include <ext/numeric>

using namespace __gnu_cxx;

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<bool> vb;
typedef vector<string> vs;
const ll MOD = 998244353;
const long double EPS = 1e-4;
const ll INF = 1e9;
int di[] = {0, 0, 1, -1};
int dj[] = {1, -1, 0, 0};
#define all(x) x.begin(),x.end()


double integrate(double fr, double to, double (*f)(double), int n = 1e7) {
	double h = (to - fr) / n;
	double integral = f(fr);
	for (int i = 1; i < n / 2; i++) {
		integral += 2.0 * f(fr + i * 2 * h) + 4.0 * f(fr + (i * 2 - 1) * h);
	}
	return h * (integral) / 3.0;
}

double r1, r2;

double f(double z) {
	return sqrt((r1 * r1 - z * z) * (r2 * r2 - z * z));
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#else
	freopen("twocyl.in", "r", stdin);
	freopen("twocyl.out", "w", stdout);
#endif

	cin >> r1 >> r2;
	cout << fixed << setprecision(10) << 8.0 * integrate(0, min(r1, r2), f) << endl;
}
