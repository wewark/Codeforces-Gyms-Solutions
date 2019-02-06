// 2018 German Collegiate Programming Contest (GCPC 18)
// 102021B

#include <bits/stdc++.h>
#include <ext/hash_map>
#include <ext/numeric>

using namespace std;
using namespace __gnu_cxx;

#define REP(i,n) for( (i)=0 ; (i)<(n) ; (i)++ )
#define rep(i,x,n) for( (i)=(x) ; (i)<(n) ; (i)++ )
#define REV(i,n) for( (i)=(n) ; (i)>=0 ; (i)-- )
#define FORIT(it,x) for( (it)=(x).begin() ; (it)!=(x).end() ; (it)++ )
#define foreach(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define rforeach(it,c) for(__typeof((c).rbegin()) it=(c).rbegin();it!=(c).rend();++it)
#define foreach2d(i, j, v) foreach(i,v) foreach(j,*i)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define SZ(x) ((int)(x).size())
#define MMS(x,n) memset(x,n,sizeof(x))
#define mms(x,n,s) memset(x,n,sizeof(x)*s)
#define pb push_back
#define mp make_pair
#define NX next_permutation
#define UN(x) sort(all(x)),x.erase(unique(all(x)),x.end())
#define CV(x,n) count(all(x),(n))
#define FIND(x,n) find(all(x),(n))-(x).begin()
#define ACC(x) accumulate(all(x),0)
#define PPC(x) __builtin_popcount(x)
#define LZ(x) __builtin_clz(x)
#define TZ(x) __builtin_ctz(x)
#define mxe(x) *max_element(all(x))
#define mne(x) *min_element(all(x))
#define low(x,i) lower_bound(all(x),i)
#define upp(x,i) upper_bound(all(x),i)
#define NXPOW2(x) (1ll << ((int)log2(x)+1))
#define PR(x) cout << #x << " = " << (x) << endl ;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef pair<int, int> pii;
typedef complex<double> point;

const int OO = (int) 2e9;
const double eps = 1e-9;

#define X real()
#define Y imag()
#define vec(a,b) ((b)-(a))
#define polar(r,t) ((r)*exp(point(0,(t))))
#define angle(v) (atan2((v).Y,(v).X))
#define length(v) ((double)hypot((v).Y,(v).X))
#define lengthSqr(v) (dot(v,v))
#define dot(a,b) ((conj(a)*(b)).real())
#define cross(a,b) ((conj(a)*(b)).imag())
#define rotate(v,t) (polar(v,t))
#define rotateabout(v,t,a)  (rotate(vec(a,v),t)+(a))
#define reflect(p,m) ((conj((p)/(m)))*(m))
#define normalize(p) ((p)/length(p))
#define same(a,b) (lengthSqr(vec(a,b))<eps)
#define mid(a,b) (((a)+(b))/point(2,0))
#define perp(a) (point(-(a).Y,(a).X))

enum STATE {
	IN, OUT, BOUNDRY
};

#ifndef M_PI
#define M_PI acos(-1)
#endif

int circleLineIntersection(const point& p0, const point& p1, const point& cen, double rad, point& r1, point & r2) {
	double a, b, c, t1, t2;
	a = dot(p1 - p0, p1 - p0);
	b = 2 * dot(p1 - p0, p0 - cen);
	c = dot(p0-cen,p0-cen) - rad * rad;
	double det = b * b - 4 * a * c;
	int res;
	if (fabs(det) < eps)
		det = 0, res = 1;
	else if (det < 0)
		res = 0;
	else
		res = 2;
	det = sqrt(det);
	t1 = (-b + det) / (2 * a);
	t2 = (-b - det) / (2 * a);
	r1 = p0 + t1 * (p1 - p0);
	r2 = p0 + t2 * (p1 - p0);
	return res;
}

STATE circlePoint(const point & cen, const double & r, const point& p) {
	long lensqr = lengthSqr(vec(cen,p));
	if (fabs(lensqr - r * r) < eps)
		return BOUNDRY;
	if (lensqr < r * r)
		return IN;
	return OUT;
}

int tangentPoints(const point & cen, const double & r, const point& p, point &r1, point &r2) {
	STATE s = circlePoint(cen, r, p);
	if (s != OUT) {
		r1 = r2 = p;
		return s == BOUNDRY;
	}
	point cp = vec(cen, p);
	double h = length(cp);
	double a = acos(r / h);
	cp = normalize(cp) * r;
	r1 = rotate(cp,a) + cen;
	r2 = rotate(cp,-a) + cen;
	return 2;
}

point cen;
double r;

double calcArc(point p1, point p2) {
	double d = length(vec(p1, p2));
	double ang = (angle(vec(cen, p1)) - angle(vec(cen, p2))) * 180 / M_PI;
	if (ang < 0)
		ang += 360;
	ang = min(ang, 360 - ang);
	return r * ang * M_PI / 180;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
//	freopen("in.txt", "rt", stdin);
//	freopen("out.txt", "wt", stdout);
#endif
	int x, y;
	point src, snk;
	cin >> x >> y;
	src = point(x, y);
	cin >> x >> y;
	snk = point(x, y);
	cin >> x >> y >> r;
	cin >> x >> y >> r;
	cen = point(x, y);
	double res = 0;
	point p1, p2, p3, p4;
	if (circleLineIntersection(src, snk, cen, r, p1, p2) == 2) {
		tangentPoints(cen, r, src, p1, p2);
		tangentPoints(cen, r, snk, p3, p4);
		res = OO;
		res = min(res, length(vec(src, p1)) + calcArc(p1, p3) + length(vec(p3, snk)));
		res = min(res, length(vec(src, p1)) + calcArc(p1, p4) + length(vec(p4, snk)));
		res = min(res, length(vec(src, p2)) + calcArc(p2, p3) + length(vec(p3, snk)));
		res = min(res, length(vec(src, p2)) + calcArc(p2, p4) + length(vec(p4, snk)));
	} else {
		res = length(vec(src, snk));
	}
	cout << fixed << setprecision(10) << res << endl;
	return 0;
}
