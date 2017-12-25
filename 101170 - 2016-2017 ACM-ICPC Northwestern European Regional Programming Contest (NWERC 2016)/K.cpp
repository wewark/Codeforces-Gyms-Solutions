#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<ll, ll> pii;
typedef vector<pii> vii;
typedef vector<bool> vb;
typedef vector<string> vs;
const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, 1, 0, -1 };
const ll MOD = 5e6;
const ll INF = 1e8;
const long double EPS = 1e-6;
#define mp make_pair
#define all(x) x.begin(),x.end()

typedef complex<long double> point;

#define X real()
#define Y imag()
#define vec(a,b) ((b) - (a))
#define cross(a,b) ((conj(a) * (b)).imag())
#define dot(a,b) ((conj(a) * (b)).real())
#define colliner pointOnLine
#define same(a,b) (lengthSqr(vec(a, b)) < EPS)
#define lengthSqr(v) (dot(v, v))
#define normalize(p) ((p) / length(p))
#define length(v) ((long double)hypot((v).Y, (v).X))
#define perp(a) (point(-(a).Y, (a).X))
enum STATE {
	IN, OUT, BOUNDRY
};

bool intersect(const point &a, const point &b,
	const point &p, const point &q, point &ret) {
	//handle degenerate cases (2 parallel lines, 2 identical lines, line is 1 point)
	long double d1 = cross(p - a, b - a);
	long double d2 = cross(q - a, b - a);
	ret = (d1 * q - d2 * p) / (d1 - d2);
	if (fabs(d1 - d2) > EPS) return 1;
	return 0;
}

long double pointLineDist(const point& a, const point& b, const point& p) {
	// handle degenrate case: (a,b) is point
	return fabs(cross(vec(a, b), vec(a, p)) / length(vec(a, b)));
}

long double pointSegmentDist(const point &a, const point &b, const point &p) {
	if (dot(vec(a, b), vec(a, p)) < EPS)
		return length(vec(a, p));
	if (dot(vec(b, a), vec(b, p)) < EPS)
		return length(vec(b, p));
	return pointLineDist(a, b, p);
}

bool pointOnRay(const point& a, const point& b, const point& p) {
	//IMP NOTE: a,b,p must be collinear
	return dot(vec(a, p), vec(a, b)) > -EPS;
}

bool pointOnLine(const point& a, const point& b, const point& p) {
	// degenerate case: line is a point
	return fabs(cross(vec(a, b), vec(a, p))) < EPS;
}

bool pointOnSegment(const point& a, const point& b, const point& p) {
	//el satr da momken y3mel precision error
	if (!colliner(a, b, p)) return 0;
	return pointOnRay(a, b, p) && pointOnRay(b, a, p);
}

STATE pointInPolygon(const vector<point> &p, const point &pnt) {
	point p2 = pnt + point(1, 0);
	int cnt = 0;
	for (int i = 0; i < p.size(); i++) {
		int j = (i + 1) % p.size();
		if (pointOnSegment(p[i], p[j], pnt))
			return BOUNDRY;
		point r;
		if (!intersect(pnt, p2, p[i], p[j], r))
			continue;
		if (!pointOnRay(pnt, p2, r))
			continue;
		if (same(r, p[i]) || same(r, p[j]))
			if (fabs(r.Y - min(p[i].Y, p[j].Y)) < EPS)
				continue;
		if (!pointOnSegment(p[i], p[j], r))
			continue;
		cnt++;
	}
	return cnt & 1 ? IN : OUT;
}

void move(pair<point, point>& line) {
	point pr = normalize(perp(vec(line.first, line.second)));
	line.first.real(line.first.X + pr.X * (-3999.0 - EPS));
	line.first.imag(line.first.Y + pr.Y * (-3999.0 - EPS));
	line.second.real(line.second.X + pr.X * (-3999.0 - EPS));
	line.second.imag(line.second.Y + pr.Y * (-3999.0 - EPS));
}

void resize(pair<point, point>& line, pair<point, point>& a, pair<point, point>& b) {
	point from, to;
	intersect(line.first, line.second, a.first, a.second, from);
	intersect(line.first, line.second, b.first, b.second, to);
	line = { from, to };
}

bool valid(point p, vector<pair<point, point>>& plines, vector<point>& pol) {
	for (auto& line : plines)
		if (pointSegmentDist(line.first, line.second, p) < 3999.0 - EPS)
			return false;
	return pointInPolygon(pol, p) == IN;
}

int n;

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n;
	vector<point> p(n);
	vector<pair<point, point>> lines, plines;
	for (int i = 0; i < n; i++) {
		long double x, y; cin >> x >> y;
		p[i].real(x);
		p[i].imag(y);
	}
	for (int i = 0; i < n; i++) {
		lines.push_back({ p[i], p[(i + 1) % n] });
		plines.push_back(lines.back());
		move(lines.back());
	}

	for (int i = 0; i < n; i++) {
		resize(lines[(i + 1) % n], lines[i], lines[(i + 2) % n]);
		//cout << "Segment " << lines[(i + 1) % n].first.X << " " << lines[(i + 1) % n].first.Y << " ";
		//cout << lines[(i + 1) % n].second.X << " " << lines[(i + 1) % n].second.Y << endl;
	}
	vector<point> vip; // very important point
	for (int i = 0; i < n; i++)
		if (valid(lines[i].first, plines, p))
			vip.push_back(lines[i].first);

	for (int i = 0; i < vip.size(); i++)
		for (int j = i + 1; j < vip.size(); j++)
			if (length(vec(vip[i], vip[j])) > 2.0 * (3999.0 - EPS)) {
				//cout << length(vec(vip[i], vip[j])) << endl;
				cout << fixed << setprecision(8) << vip[i].X << " " << vip[i].Y << endl;
				cout << fixed << setprecision(8) << vip[j].X << " " << vip[j].Y << endl;
				cin.ignore(), cin.get();
				return 0;
			}

	cout << "impossible\n";
	cin.ignore(), cin.get();
}
