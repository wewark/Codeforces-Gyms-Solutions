// 2013-2014 CT S01E07 Codeforces Trainings Season 1 Episode 7
// 100254H

#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ll;
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
#define SZ(x) (int)(x).size()

#include <ext/hash_set>
#include <ext/numeric>

#define  fr first
#define  sc second
typedef pair<int, pair<int, int>> piii;

typedef complex<double> point;
#define X real()
#define Y imag()
#define vec(a, b) ((b) - (a))
#define cross(a, b) ((conj(a) * (b)).imag())
#define dot(a, b) ((conj(a) * (b)).real())
#define lengthSqr(v) (dot(v, v))
#define same(a, b) (lengthSqr(vec(a, b)) < EPS)


struct cmp {
	point about;

	cmp(point c) {
		about = c;
	}

	bool operator()(const point &p, const point &q) const {
		double cr = cross(vec(about, p), vec(about, q));
		if (fabs(cr) < EPS)
			return make_pair(p.Y, p.X) < make_pair(q.Y, q.X);
		return cr > 0;
	}
};

void sortAntiClockWise(vector<point> &pnts) {
	point mn(1 / 0.0, 1 / 0.0);
	for (int i = 0; i < SZ(pnts); i++) {
		if (make_pair(pnts[i].Y, pnts[i].X) < make_pair(mn.Y, mn.X))
			mn = pnts[i];
	}
	sort(all(pnts), cmp(mn));
}

void convexHull(vector<point> pnts, vector<point> &convex) {
	sortAntiClockWise(pnts);
	convex.clear();
	convex.push_back(pnts[0]);
	if (SZ(pnts) == 1)
		return;
	convex.push_back(pnts[1]);
	if (SZ(pnts) == 2) {
		if (same(pnts[0], pnts[1]))
			convex.pop_back();
		return;
	}
	for (int i = 2; i <= SZ(pnts); i++) {
		point c = pnts[i % SZ(pnts)];
		while (SZ(convex) > 1) {
			point b = convex.back();
			point a = convex[SZ(convex) - 2];
			if (cross(vec(b, a), vec(b, c)) < -EPS)
				break;
			convex.pop_back();
		}
		if (i < SZ(pnts))
			convex.push_back(pnts[i]);
	}
}

int n, p, q;

struct tmpPoint {
	int x, y;
};

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	int t, x, y;
	cin >> t;
	while (t--) {
		cin >> p >> q >> n;
		set<pair<pii, pii> > S;
		vector<point> pnts;
		for (int i = 0; i < n; i++) {
			cin >> x >> y;
			pnts.push_back(point(x, y));
		}
		for (int i = 0; i < n; i++) {
			S.insert({{pnts[i].X, pnts[i].Y}, {pnts[(i + 1) % n].X, pnts[(i + 1) % n].Y}});
		}
		vector<point> convex;
		convexHull(pnts, convex);
		int m = SZ(convex);
		int b = m;
		for (int i = 0; i < m; i++) {
			int j = (i + 1) % m;
			if (S.find({{convex[i].X, convex[i].Y}, {convex[j].X, convex[j].Y}}) == S.end() &&
			    S.find({{convex[j].X, convex[j].Y}, {convex[i].X, convex[i].Y}}) == S.end()) {
				b--;
			}
		}
		int a = m - b;
		int res = max(0, b * q - a * p);
		cout << res << "\n";
	}
	return 0;
}
