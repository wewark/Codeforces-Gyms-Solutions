// 101635 - 2017-2018 ACM-ICPC Southwestern European Regional Programming Contest (SWERC 2017)
// 101635C

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
const int di[] = { -1, 0, 1, 0, -1, 1, 1, -1 };
const int dj[] = { 0, 1, 0, -1, -1, 1, -1, 1 };
const ll MOD = 1e9;
const ll INF = 1e9;
const long double EPS = 1e-7;
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

ll n, m;
vvi mat;

void bt(int h, int& l, int& r) {
	if (h == n) {
		mat[l][r]++;
		return;
	}

	l |= (1 << h);
	bt(h + 1, l, r);
	l &= ~(1 << h);

	r |= (1 << h);
	bt(h + 1, l, r);
	r &= ~(1 << h);

	bt(h + 1, l, r);
	if (h + 1 < n)
		bt(h + 2, l, r);
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m;
	mat.assign(1 << n, vi(1 << n));
	int l = 0, r = 0;
	bt(0, l, r);

	mat = matrixPower(mat, m);
	cout << mat[0][0] << endl;
	cin.ignore(), cin.get();
}
