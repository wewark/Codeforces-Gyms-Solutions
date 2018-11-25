// ACM International Collegiate Programming Contest Arabella Collegiate Programming Contest (2018)
// 101972C

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
#define all(x) x.begin(),x.end()
#define SZ(x) (int)x.size()

typedef pair<double, double> pdd;
typedef complex<double> Point;

#define X real()
#define Y imag()
#define vec(a, b) ((b) - (a))

inline double dist(pdd a, pdd b) {
	return sqrt((a.second - b.second) * (a.second - b.second) +
			            (a.first - b.first) * (a.first - b.first));
}

inline double f(pdd& fr, pdd& to, double x, double y) {
	return dist(fr, pdd(x, y)) + dist(pdd(x, y), to);
}

double TS(pdd fr, pdd to, double C) {
	double a = fr.second, b = to.second;
	double c = a + (b - a) / 3.0;
	double d = b - (b - a) / 3.0;
	for (int i = 0; i < 70; ++i) {
		if (f(fr, to, C, c) > f(fr, to, C, d))
			a = c;
		else
			b = d;
		c = a + (b - a) / 3.0;
		d = b - (b - a) / 3.0;
	}
	return f(fr, to, C, (c + d) / 2.0);
}

int main() {
//	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int t = 1;
	cin >> t;
	while (t--) {
		double a, b, c, x;
		scanf("%lf %lf %lf %lf", &a, &b, &c, &x);

		double r = 0;
		r += TS(pdd(0, 0), pdd(-b, -a), c);

		r += dist(pdd(-b, -a), pdd(0, 0)) * x / 100.0;

		Point cur(-b, -a);
		Point v = vec(cur, Point(0, 0));
		cur += v * x / 100.0;

		r += TS(pdd(cur.X, cur.Y), pdd(0, 0), c);
		printf("%.10lf\n", r);
	}
}