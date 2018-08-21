// 101047 - 2015 USP Try-outs
// 101047K

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
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const long double EPS = 1e-10;

#define all(x) x.begin(),x.end()

int n;
vector<double> num;

inline double area(double a, double b, double c) {
	double s((a + b + c) / 2);
	return sqrt(s * (s - a) * (s - b) * (s - c));
}

double solve(int a, int b) {
	double ret = INF;
	if (b < n - 1 && num[b + 1] < num[a] + num[b]) {
		ret = min(ret, area(num[a], num[b], num[b + 1]));

		int idx = lower_bound(all(num), num[a] + num[b]) - num.begin();
		idx--;
		if (idx > b && num[idx] < num[a] + num[b])
			ret = min(ret, area(num[a], num[b], num[idx]));
	}
	if (ret == INF) return -1;
	return ret;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
//	freopen("cube.in", "r", stdin);
//	freopen("cube.out", "w", stdout);

	int t; cin >> t;
	while (t--) {
		cin >> n;
		num.resize(n);
		for (int i = 0; i < n; ++i) {
			cin >> num[i];
		}
		sort(all(num));

		double r = INF;
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				double x = solve(i, j);
				if (x > -0.5)
					r = min(x, r);
			}
		}

		if (r == INF) cout << -1 << "\n";
		else cout << fixed << setprecision(10) << r << "\n";
	}

	return 0;
}