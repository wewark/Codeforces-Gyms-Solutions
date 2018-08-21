// 101061 - Higher Institute for Applied Sciences and Technology Collegiate Programming Contest 2016
// 101061B

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<ll, ll> pii;
typedef vector<pii> vii;
typedef vector<bool> vb;
typedef vector<string> vs;
const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, 1, 0, -1 };
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const double EPS = 1e-11;
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
vvi matrixPower(vvi mat, int p) {
	if (p == 1) return mat;
	if (p % 2 == 1)
		return matrixMult(mat, matrixPower(mat, p - 1));
	vvi cur = matrixPower(mat, p / 2);
	return matrixMult(cur, cur);
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vvi mat = {
			{ 1,4,7 },
			{ 2,5,8 },
			{ 3,6,9 }
		};

		ll r = 0;
		if (n > 1) {
			mat = matrixMult(matrixPower(mat, n - 1), { {1},{1},{1} });
			for (int i = 0; i < 3; i++)
				r += mat[i][0], r %= MOD;
		}
		else r = 3;
		cout << r << endl;
	}
	cin.ignore(), cin.get();
}
