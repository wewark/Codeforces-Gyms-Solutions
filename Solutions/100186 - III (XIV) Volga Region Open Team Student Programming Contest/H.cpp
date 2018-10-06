// III (XIV) Volga Region Open Team Student Programming Contest
// 100186H

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

char s[8][8];

int intersect2D_2Segments(const point &a, const point &b, const point &p, const point &q, point &I0) {
	point u = b - a;
	point v = q - p;
	point w = a - p;
	double D = cross(u, v);

	if (fabs(D) < eps) {
		return 0;
	}
	double sI = cross(v, w) / D;
	if (sI < 0 || sI > 1)
		return 0;

	double tI = cross(u, w) / D;
	if (tI < 0 || tI > 1)
		return 0;

	I0 = a + sI * u;
	return 1;
}

bool isLattice(double x, double y) {
	int xr = round(x);
	int yr = round(y);
	return (xr % 100 == 0 && yr % 100 == 0);
}

bool go(int si, int sj, int ei, int ej, int i, int j) {
	if (i == si && j == sj)
		return 1;
	if (i == ei && j == ej)
		return 1;

	int cnt = 0, d = 0;
	point a = point(si * 100 + 50, sj * 100 + 50);
	point b = point(ei * 100 + 50, ej * 100 + 50);
	point I;

	point p = point(i * 100, j * 100);
	point q = point(i * 100 + 100, j * 100);
	if (intersect2D_2Segments(a, b, p, q, I)) {
		cnt++;
		if (isLattice(I.X, I.Y))
			d++;
	}

	p = point(i * 100, j * 100);
	q = point(i * 100, j * 100 + 100);
	if (intersect2D_2Segments(a, b, p, q, I)) {
		cnt++;
		if (isLattice(I.X, I.Y))
			d++;
	}

	p = point(i * 100 + 100, j * 100);
	q = point(i * 100 + 100, j * 100 + 100);
	if (intersect2D_2Segments(a, b, p, q, I)) {
		cnt++;
		if (isLattice(I.X, I.Y))
			d++;
	}

	p = point(i * 100, j * 100 + 100);
	q = point(i * 100 + 100, j * 100 + 100);
	if (intersect2D_2Segments(a, b, p, q, I)) {
		cnt++;
		if (isLattice(I.X, I.Y))
			d++;
	}
	if (cnt == 2 && d == 2)
		return 0;
	return cnt;
}

int calc(int si, int sj, int ei, int ej) {
	int res = 0;
	for (int i = 1; i < 6; i++) {
		for (int j = 0; j < 5; j++) {
//			cout << i << " " << j << " => " << s[i][j] << " " << go(si, sj, ei, ej, i, j) << endl;
			if (go(si, sj, ei, ej, i, j)) {
				if (s[i][j] == 'P')
					return 0;
				if (s[i][j] == 'A')
					res++;
			}
		}
	}
	return res;
}

int get(int si, int sj, int &ei, int &ej) {
	int res = 0;
	for (int i = 1; i < 6; i++) {
		for (int j = 0; j < 5; j++) {
			if (s[i][j] != 'A')
				continue;
			int v = calc(si, sj, i, j);
			if (v > res) {
				res = v;
				ei = i, ej = j;
			}
		}
	}
	return res;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("in.txt", "rt", stdin);
#else
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	for (int i = 1; i < 6; i++)
		cin >> s[i];
	int res = 0, si = 0, sj = 0, ei = 0, ej = 1;
	for (int j = 0; j < 5; j++) {
		int ii, jj;
		int v = get(0, j, ii, jj);
		if (v > res) {
			res = v;
			si = 0, sj = j;
			ei = ii, ej = jj;
		}
		v = get(6, j, ii, jj);
		if (v > res) {
			res = v;
			si = 6, sj = j;
			ei = ii, ej = jj;
		}
	}
	cout << res << "\n";
	cout << si + 1 << " " << sj + 1 << "\n";
	if (res == 0) {
		for (int i = 1; i < 6; i++) {
			for (int j = 0; j < 5; j++) {
				if (s[i][j] == 'A') {
					cout << i + 1 << " " << j + 1 << "\n";
					return 0;
				}
			}
		}
	}
	cout << ei + 1 << " " << ej + 1 << "\n";
	return 0;
}
