// 2010-2011 ACM-ICPC NEERC Moscow Subregional Contest
// 100714A

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
const int di[] = { 0,0,1,-1 };
const int dj[] = { 1,-1,0,0 };
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const long double EPS = 1e-9;
#define all(x) x.begin(),x.end()

typedef complex<double> Point;
#define X real()
#define Y imag()
#define vec(a, b) ((b) - (a))
#define length(v) ((double)hypot((v).Y, (v).X))
#define lengthSqr(v) (dot(v, v))
#define dot(a, b) ((conj(a) * (b)).real())
#define same(a, b) (lengthSqr(vec(a, b)) < EPS)
#define normalize(p) ((p) / length(p))
#define polar(r, t) ((r) * exp(Point(0, (t))))
#define rotate(v, t) (polar(v, t))

const double PI = 3.14159265358979323846264338327950288419716939;

double cosRule(double a, double b, double c) {
	double res = (b * b + c * c - a * a) / (2.0 * b * c);
	if (res > 1)
		res = 1;
	if (res < -1)
		res = -1;
	return acos(res);
}

int circleCirclIntersection(
	const Point& c1, const double& r1,
	const Point& c2, const double& r2,
	Point& res1, Point& res2) {
	if (same(c1, c2) && fabs(r1 - r2) < EPS) {
		res1 = res2 = c1;
		return fabs(r1) < EPS ? 1 : INF;
	}
	double len = length(vec(c1, c2));
	if (fabs(len - (r1 + r2)) < EPS ||
		fabs(fabs(r1 - r2) - len) < EPS) {
		Point d, c;
		double r;
		if (r1 > r2)
			d = vec(c1, c2), c = c1, r = r1;
		else
			d = vec(c2, c1), c = c2, r = r2;
		res1 = res2 = normalize(d) * r + c;
		return 1;
	}
	if (len > r1 + r2 || len < fabs(r1 - r2))
		return 0;
	double a = cosRule(r2, r1, len);
	Point c1c2 = normalize(vec(c1, c2)) * r1;
	res1 = rotate(c1c2, a) + c1;
	res2 = rotate(c1c2, -a) + c1;
	return 2;
}

double triangleArea2SidesAngle(double a, double b, double t) {
	return fabs(a * b * sin(t) / 2.0);
}

double circleCirclIntersectionArea(
	const Point& c1, const double& r1,
	const Point& c2, const double& r2) {
	Point i1, i2;
	int cnt = circleCirclIntersection(c1, r1, c2, r2, i1, i2);
	if (cnt < 2) return 0;

	double ret = 0;
	Point v1 = vec(c1, i1), v2 = vec(c1, i2);
	double ang = acos(dot(v1, v2) / (length(v1) * length(v2)));
	double triArea = triangleArea2SidesAngle(r1, r1, ang);
	double circleArea = PI * r1 * r1;
	ret = ang * circleArea / (2.0 * PI) - triArea;

	v1 = vec(c2, i1), v2 = vec(c2, i2);
	ang = acos(dot(v1, v2) / (length(v1) * length(v2)));
	triArea = triangleArea2SidesAngle(r2, r2, ang);
	circleArea = PI * r2 * r2;
	ret += ang * circleArea / (2.0 * PI) - triArea;

	return ret;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);

	int n, r; cin >> n >> r;
	vi c(n);
	for (int i = 0; i < n; i++)
		cin >> c[i];
	sort(all(c));

	double rs = PI * r * r * n;
	for (int i = 0; i < n - 1; i++) {
		rs -= circleCirclIntersectionArea(c[i], r, c[i + 1], r);
	}
	cout << fixed << setprecision(10) << rs << endl;
}
