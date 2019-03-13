// 2018-2019 ACM-ICPC Asia Jiaozuo Regional Contest
// 102028D

#include <bits/stdc++.h>
#include <ext/hash_set>
#include <ext/numeric>

using namespace __gnu_cxx;
using namespace std;

using ll = long long;
using vi = vector<ll>;
using vll = vector<ll>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;
using vb = vector<bool>;
using vs = vector<string>;
const int MOD = int(1e9 + 7);
const long double EPS = 1e-8;
const double PI = 3.1415926535897932384626433;
const ll INF = ll(1e18);
int di[] = {0, 0, 1, -1, 1, -1, 1, -1};
int dj[] = {1, -1, 0, 0, 1, -1, -1, 1};
#define all(x) x.begin(),x.end()

typedef complex<double> Point;
#define X real()
#define Y imag()
#define vec(a,b) ((b) - (a))
#define polar(r,t) ((r) * exp(Point(0, (t))))
#define rotate(v,t) (polar(v, t))
#define length(v) ((double)hypot((v).Y, (v).X))
#define normalize(p) ((p) / length(p))
//#define cross(a,b) ((conj(a) * (b)).imag())

//bool intersect(Point& a, Point& b, Point& p, Point& q) {
//	double d1 = cross(p - a, b - a);
//	double d2 = cross(q - a, b - a);
//	Point ret = (d1 * q - d2 * p) / (d1 - d2);
//	return  fabs(d1 - d2) > EPS;
//}

double cross(Point& O, Point& A, Point& B) {
	return (A.X - O.X) * (B.Y - O.Y) - (A.Y - O.Y) * (B.X - O.X);
}

double a, b, r, d;

bool valid(double w) {
	Point v1(0, 1);
	v1 = rotate(v1, 2.0 * PI - (d / 180.0 * PI));
	v1 = normalize(v1);
	Point v2 = rotate(v1, 2.0 * PI - PI / 2.0);
	v2 = normalize(v2);
	Point p1 = v1 * (r + w);
	Point p2 = p1 + v2 * 1000.0;
	Point c1(0, r + a);
	Point c2 = c1 + Point(1, 0) * b;
	return cross(p1, p2, c2) <= 0;
}

double BS() {
	double st = a, ed = 1000, mid = (st + ed) / 2.0;
	for (int i = 0; i < 100; ++i) {
		if (fabs(st - ed) < EPS) break;
		if (valid(mid))
			ed = mid;
		else
			st = mid;
		mid = (st + ed) / 2.0;
	}
	return mid;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

//	cout << intersect(Point(0,1),Point(0,1),Point(0,1),Point(0,1))<<endl;

	int t; cin >> t;
	cout << fixed << setprecision(10);
	while (t--) {
		cin >> a >> b >> r >> d;
		if (atan(b / (a + r)) > d / 180.0 * PI) {
			cout << BS() << endl;
		}
		else {
			cout << sqrt((a + r) * (a + r) + b * b) - r << endl;
		}
	}
}
