// 2011-2012 ACM-ICPC Southwestern European Regional Programming Contest (SWERC 2011)
// 101561I

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
typedef complex<long double> point;

const int OO = (int) 2e9;
const double eps = 1e-15;

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

bool intersect(const point &a, const point &b, const point &p, const point &q, point &ret) {
	long double d1 = cross(p - a, b - a);
	long double d2 = cross(q - a, b - a);
	ret = (d1 * q - d2 * p) / (d1 - d2);
	if (fabs(d1 - d2) > eps)
		return 1;
	return 0;
}

bool circle3(const point& p1, const point& p2, const point& p3, point& cen, long double& r) {
	point m1 = mid(p1, p2);
	point m2 = mid(p2, p3);
	point perp1 = perp(vec(p1,p2));
	point perp2 = perp(vec(p2,p3));
	bool res = intersect(m1, m1 + perp1, m2, m2 + perp2, cen);
	r = length(vec(cen,p1));
	return res;
}

point cen;
long double r;
point p[3];
point v[3];
long double a[3];

bool solve(int n) {
	long double ang = 360.0;
	ang /= n;
	double err = 1e-6;
	long double dif0 = fmod(fabs(a[0] - a[1]), ang);
	long double dif1 = fmod(fabs(a[1] - a[2]), ang);
	if (dif0 > err && fabs(dif0 - ang) > err)
		return 0;
	if (dif1 > err && fabs(dif1 - ang) > err)
		return 0;
	return 1;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
//	freopen("in.txt", "rt", stdin);
//	freopen("out.txt", "wt", stdout);
#endif
	double x, y;
	string s;
//	cout << angle(vec(point(0, 0), point(0, 1))) * 180 / M_PI << endl;
	cout << fixed << setprecision(6);
	while (cin >> s) {
		if (s == "END")
			break;
		x = stod(s);
		cin >> y;
		p[0] = point(x, y);
		for (int i = 1; i < 3; i++) {
			cin >> x >> y;
			p[i] = point(x, y);
		}
		if (!circle3(p[0], p[1], p[2], cen, r)) {
			assert(0);
		}
		for (int i = 0; i < 3; i++) {
			v[i] = vec(cen, p[i]);
			a[i] = angle(v[i]);
			a[i] = a[i] * 180 / M_PI;
			if (a[i] < 0)
				a[i] += 360;
		}
		sort(a, a + 3);
		int res = -1;
		for (int n = 3; n <= 1000; n++) {
			if (solve(n)) {
				res = n;
				break;
			}
		}
//		assert(res != -1);
		cout << res << "\n";
	}
	return 0;
}
