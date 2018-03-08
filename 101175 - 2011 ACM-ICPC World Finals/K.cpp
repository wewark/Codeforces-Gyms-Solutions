#include <bits/stdc++.h>

using namespace std;

typedef complex<double> point;
#define EPS 1e-9
#define OO 1e9
#define X real()
#define Y imag()
#define vec(a,b) 	((b) - (a))
#define length(v) 	((double)hypot((v).Y, (v).X))
#define cross(a,b) 	((conj(a) * (b)).imag())

double pointLineDist(const point& a, const point& b, const point& p) {
	return fabs(cross(vec(a, b), vec(a, p)) / length(vec(a, b)));
}

struct Point {
	double x, y;

	bool operator < (Point other) const {
		if (x != other.x)
			return x < other.x;
		return y < other.y;
	}

	bool operator == (Point other) const {
		return x == other.x && y == other.y;
	}
};

bool compare(Point a, Point b) {
	return a.x < b.x || (a.x == b.x && a.y < b.y);
}

double Cross(const Point &O, const Point &A, const Point &B) {
	return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

vector<Point> convex_hull(vector<Point> P) {
	int n = P.size(), k = 0;
	vector<Point> H(2 * n);
	sort(P.begin(), P.end(), compare);
	for (int i = 0; i < n; ++i) {
		while (k >= 2 && Cross(H[k - 2], H[k - 1], P[i]) < 0) k--;
		H[k++] = P[i];
	}

	for (int i = n - 2, t = k + 1; i >= 0; i--) {
		while (k >= t && Cross(H[k - 2], H[k - 1], P[i]) < 0) k--;
		H[k++] = P[i];
	}
	H.resize(k - 1);
	return H;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int n, tt = 0;
	while (cin >> n && n) {
		vector<Point> pc(n);
		for (int i = 0; i < n; ++i) {
			double x, y; cin >> x >> y;
			pc[i] = { x,y };
		}

		vector<Point> con = convex_hull(pc);
		vector<point> p;
		for (auto& i : con) {
			p.emplace_back();
			p.back().real(i.x);
			p.back().imag(i.y);
		}

		double r = 1e9;
		for (int i = 0; i < p.size(); ++i) {
			double x = 0;
			for (int j = 0; j < p.size(); ++j) {
				x = max(x, pointLineDist(p[i], p[(i + 1) % p.size()], p[j]));
			}
			r = min(r, x);
		}
		cout << "Case " << ++tt << ": ";
		cout << fixed << setprecision(2) << r << endl;
	}
	return 0;
}
