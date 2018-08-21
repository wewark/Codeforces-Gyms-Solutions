// 101170 - 2016-2017 ACM-ICPC Northwestern European Regional Programming Contest (NWERC 2016)
// 101170C

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<ll, ll> pii;
typedef vector<pii> vii;
typedef vector<bool> vb;
typedef vector<string> vs;
const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, 1, 0, -1 };
const ll MOD = 5e6;
const ll INF = 1e9;
const double EPS = 1e-12;
#define mp make_pair
#define all(x) x.begin(),x.end()

ll x, y, n;
vii sh; vector<long double> v;

long double dist(long double h) {
	double cx = 0;
	for (int i = 0; i < n; i++) {
		if (i == 0)
			cx = h * sh[i].first;
		else
			cx += h * (sh[i].first - sh[i - 1].second);

		cx += (h * v[i]) * (sh[i].second - sh[i].first);
	}

	cx += h * (y - (n == 0 ? 0 : sh.back().second));
	return cx - x;
}

long double bs() {
	long double a = -1e7 - 1000, b = 1e7 + 1000, mid = (a + b) / 2.0;
	while (abs(a - b) > EPS) {
		if (dist(mid) > 0)
			b = mid;
		else
			a = mid;
		mid = (a + b) / 2.0;
	}
	return mid;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> x >> y >> n;
	sh.resize(n);
	v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> sh[i].first >> sh[i].second >> v[i];
	}
	cout << fixed << setprecision(12) << bs() << endl;
	cin.ignore(), cin.get();
}
