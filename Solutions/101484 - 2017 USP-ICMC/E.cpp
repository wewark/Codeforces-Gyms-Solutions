// 101484 - 2017 USP-ICMC
// 101484E

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
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const double EPS = 1e-5;
#define mp make_pair
#define all(x) x.begin(),x.end()

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

//Returns positive value if B lies to the left of OA, negative if B lies to the right of OA, 0 if collinear
double cross(const Point &O, const Point &A, const Point &B) {
	return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

//Returns a list of points on the convex hull
vector<Point> convex_hull(vector<Point> P) {
	int n = P.size(), k = 0;
	vector<Point> H(2 * n);
	sort(P.begin(), P.end(), compare);
	// Build lower hull
	for (int i = 0; i < n; ++i) {
		while (k >= 2 && cross(H[k - 2], H[k - 1], P[i]) < 0) k--;
		H[k++] = P[i];
	}

	// Build upper hull
	//i starts from n-2 because n-1 is the point which both hulls will have in common
	//t=k+1 so that the upper hull has atleast two points to begin with
	for (int i = n - 2, t = k + 1; i >= 0; i--) {
		while (k >= t && cross(H[k - 2], H[k - 1], P[i]) < 0) k--;
		H[k++] = P[i];
	}
	//the last point of upper hull is same with the fist point of the lower hull
	H.resize(k - 1);
	return H;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int n, m; cin >> n >> m;
	vector<Point> a(n), b(m);
	for (int i = 0; i < n; i++)
		cin >> a[i].x >> a[i].y;
	for (int i = 0; i < m; i++)
		cin >> b[i].x >> b[i].y;

	vector<Point> tot = a;
	tot.insert(tot.end(), all(b));

	vector<Point> ch = convex_hull(tot);

	sort(all(a));
	sort(all(b));
	sort(all(ch));

	cout << (ch == a || ch == b ? "YES" : "NO") << endl;
	cin.ignore(), cin.get();
}
