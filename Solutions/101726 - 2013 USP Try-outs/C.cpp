// 101726 - 2013 USP Try-outs
// 101726C

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
const int di[] = { -1, 0, 1, 0, -1, 1, 1, -1 };
const int dj[] = { 0, 1, 0, -1, -1, 1, -1, 1 };
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const long double EPS = 1e-6;
#define all(x) x.begin(),x.end()

struct Point3D {
	double x, y, z;

	inline double dot(const Point3D& other) {
		double ret = 0;
		ret += x * other.x;
		ret += y * other.y;
		ret += z * other.z;
		return ret;
	}

	inline Point3D cross(const Point3D& other) {
		Point3D ret = {
			y * other.z - z * other.y,
			z * other.x - x * other.z,
			x * other.y - y * other.x,
		};
		return ret;
	}

	Point3D operator + (const Point3D& other) {
		Point3D ret = *this;
		ret.x += other.x;
		ret.y += other.y;
		ret.z += other.z;
		return ret;
	}

	Point3D operator - (const Point3D& other) {
		Point3D ret = *this;
		ret.x -= other.x;
		ret.y -= other.y;
		ret.z -= other.z;
		return ret;
	}

	Point3D operator * (double other) {
		Point3D ret = *this;
		ret.x *= other;
		ret.y *= other;
		ret.z *= other;
		return ret;
	}

	Point3D operator / (double other) {
		Point3D ret = *this;
		ret.x /= other;
		ret.y /= other;
		ret.z /= other;
		return ret;
	}

	bool operator == (Point3D& other) {
		return fabs(x - other.x) < EPS &&
			fabs(y - other.y) < EPS &&
			fabs(z - other.z) < EPS;
	}

	double norm() {
		return sqrt(x * x + y * y + z * z);
	}
};

double dist(Point3D& a, Point3D& b) {
	return sqrt(
		(a.x - b.x) * (a.x - b.x) +
		(a.y - b.y) * (a.y - b.y) +
		(a.z - b.z) * (a.z - b.z));
}

inline double ang(Point3D v1, Point3D v2) {
	return acos(v1.dot(v2) / (v1.norm() * v2.norm()));
}

inline double ang(Point3D p0, Point3D p1, Point3D p2) {
	return ang(p0 - p1, p2 - p1);
}

bool linePlaneIntersect(Point3D& p, Point3D& q, Point3D& pp, Point3D& norm, Point3D& ret, Point3D& t0, Point3D& t1, Point3D& t2) {
	double d = (q - p).dot(norm);
	if (fabs(d) < EPS) return false;

	double t = (pp - p).dot(norm) / d;
	ret = p + (q - p) * t;

	// For segment-plane intersection
	if (fabs(dist(ret, p) + dist(ret, q) - dist(p, q)) <= EPS &&
		(ret == t0 || ret == t1 || ret == t2 ||
			fabs(ang(ret, t0, t1) + ang(ret, t0, t2) - ang(t1, t0, t2)) <= EPS &&
			fabs(ang(ret, t1, t0) + ang(ret, t1, t2) - ang(t0, t1, t2)) <= EPS &&
			fabs(ang(ret, t2, t1) + ang(ret, t2, t0) - ang(t1, t2, t0)) <= EPS))
		return true;

	return false;
}

bool canSee(Point3D& a, Point3D& b, Point3D& c, Point3D& other, Point3D& x) {
	Point3D mid = (a + b + c) / 3.0;

	Point3D norm[3] = {
		(a - other).cross(b - other),
		(b - other).cross(c - other),
		(a - other).cross(c - other)
	};

	Point3D dummy;
	if (linePlaneIntersect(mid, x, other, norm[0], dummy, a, b, other) ||
		linePlaneIntersect(mid, x, other, norm[1], dummy, b, c, other) ||
		linePlaneIntersect(mid, x, other, norm[2], dummy, a, c, other))
		return false;

	return true;
}


int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int t; cin >> t;
	while (t--) {
		Point3D p[4], x;
		for (int i = 0; i < 4; i++) {
			cin >> p[i].x >> p[i].y >> p[i].z;
		}
		cin >> x.x >> x.y >> x.z;

		cout << (canSee(p[3], p[1], p[2], p[0], x) ? "Y" : "N");
		cout << (canSee(p[0], p[3], p[2], p[1], x) ? "Y" : "N");
		cout << (canSee(p[0], p[1], p[3], p[2], x) ? "Y" : "N");
		cout << (canSee(p[0], p[1], p[2], p[3], x) ? "Y" : "N");
		cout << endl;
	}
	cin.ignore(), cin.get();
}
