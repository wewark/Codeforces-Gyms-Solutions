#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<bool> vb;
typedef vector<string> vs;
const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, 1, 0, -1 };
const ll MOD = 1e9 + 9;
const ll INF = 1e9;
const double EPS = 1e-5;
#define mp make_pair
#define all(x) x.begin(),x.end()

// matA * matB
vvi matrixMult(vvi matA, vvi matB) {
	vvi ret(matA.size(), vi(matB[0].size()));
	for (int i = 0; i < ret.size(); i++) // matA row
		for (int j = 0; j < ret[0].size(); j++) // matA col
			for (int k = 0; k < matA[0].size(); k++) { // matB row
				ret[i][j] += (matA[i][k] * matB[k][j]) % MOD;
				ret[i][j] %= MOD;
			}
	return ret;
}

// mat ^ p
vvi matrixPower(vvi mat, ll p) {
	if (p == 1) return mat;
	if (p % 2 == 1)
		return matrixMult(mat, matrixPower(mat, p - 1));
	vvi cur = matrixPower(mat, p / 2);
	return matrixMult(cur, cur);
}

ll n, m, c;
vi k, f;

vvi constructMat() {
	vvi mat(n, vi(n));
	for (int i = 0; i < n - 1; i++)
		mat[i][i + 1] = 1;

	for (int i = 0; i < c; i++)
		mat.back()[n - k[i]] = 1;
	return mat;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m >> c;
	f.resize(n);
	for (int i = 0; i < n; i++)
		cin >> f[i];
	k.resize(c);
	for (int i = 0; i < c; i++)
		cin >> k[i];

	if (m <= n) {
		cout << f[m - 1] << endl; return 0;
	}

	vvi ft(n, vi(1));
	for (int i = 0; i < n; i++)
		ft[i][0] = f[i];

	vvi mat = constructMat();
	mat = matrixPower(mat, m - n);
	mat = matrixMult(mat, ft);

	cout << mat.back()[0] << endl;
	cin.ignore(), cin.get();
}
