#include <bits/stdc++.h>
#include <ext/numeric>

using namespace std;
using namespace __gnu_cxx;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<bool> vb;
typedef vector<string> vs;
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const long double EPS = 1e-10;

#ifndef M_PI
#define M_PI 3.1415926535897932384626433832795
#endif

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
#define sz(v) (int)v.size()
#define all(c) (c).begin(),(c).end()
const int si = 3;

int n;
double ang, len;

struct matrix {
	double arr[si][si];
	double *operator [](int x) {
		return arr[x];
	}
	const double *operator[](int x) const {
		return arr[x];
	}
};
struct mul {
	const matrix operator()(const matrix & a, const matrix &b) {
		matrix res;
		FOR(i , 0 , si)
		FOR(j , 0, si)
		{
			res[i][j] = 0;
			FOR(k , 0 , si)
			{
				res[i][j] += (a[i][k] * b[k][j]);
			}
		}
		return res;
	}
};
matrix identity_element(const mul &a) {
	matrix res;
	FOR(i , 0 , si)
	FOR(j , 0 , si)
	res[i][j] = (i == j);
	return res;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
//	freopen("cube.in", "r", stdin);
//	freopen("cube.out", "w", stdout);

	int t; cin >> t;
	while (t--) {
		cin >> ang >> len >> n;
		ang = ang * M_PI / 180.0;
		matrix a, b, res;
		a[0][0] = 0, a[0][1] = 0, a[0][2] = 1;
		b[0][0] = cos(ang), b[0][1] = sin(ang), b[0][2] = 0;
		b[1][0] = -sin(ang), b[1][1] = cos(ang), b[1][2] = 0;
		b[2][0] = len, b[2][1] = 0, b[2][2] = 1;
		mul m, mm;
		power(b, n, m);
		res = mm(a, power(b, n, m));
		cout << fixed << setprecision(5) << res[0][0] << " " << res[0][1] << "\n";
	}

	return 0;
}