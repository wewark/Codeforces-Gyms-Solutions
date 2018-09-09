// Arab Collegiate Programming Contest 2012
// 100155F

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
const int di[] = { 0,0,1,-1,1,-1,-1,1 };
const int dj[] = { 1,-1,0,0,1,-1,1,-1 };
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const long double EPS = 1e-6;
#define all(x) x.begin(),x.end()

inline int dist(int a, int b) {
	int ax = a / 3, ay = a % 3;
	int bx = b / 3, by = b % 3;
	return abs(ax - bx) + abs(ay - by);
}

inline bool valid(int i, int j) {
	return i >= 0 && i < 3 && j >= 0 && j < 4;
}

vector<vvi> btw(12, vvi(12));
vb frb(12);

int mem[13][1001][(1 << 12) + 1];
int solve(int cur, int left, int msk) {
	if (left == 0) return 1;
	int& ret = mem[cur][left][msk];
	if (~ret) return ret;
	ret = 0;
	
	for (int i = 0; i < 12; i++)
		if (!(msk & (1 << i)) &&
			dist(cur, i) <= left &&
			!frb[i]) {
			bool good = true;
			for (auto& j : btw[cur][i])
				if (!(msk & (1 << j))) {
					good = false; break;
				}
			if (good)
				ret += solve(i, left - dist(cur, i), (msk | (1 << i)));
		}

	return ret;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	memset(mem, -1, sizeof mem);
	int l, n; cin >> l >> n;
	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y; x--, y--;
		frb[x + y * 3] = true;
	}

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 4; j++)
			for (int d = 0; d < 8; d++) {
				int mi = i + di[d];
				int mj = j + dj[d];
				int ci = i + di[d] * 2;
				int cj = j + dj[d] * 2;
				int cci = i + di[d] * 3;
				int ccj = j + dj[d] * 3;
				if (valid(ci, cj))
					btw[i + j * 3][ci + cj * 3].push_back(mi + mj * 3);
				if (valid(cci, ccj)) {
					btw[i + j * 3][cci + ccj * 3].push_back(mi + mj * 3);
					btw[i + j * 3][cci + ccj * 3].push_back(ci + cj * 3);
				}
			}

	ll r = 0;
	for (int i = 0; i < 12; i++)
		if (!frb[i])
			r += solve(i, l, 1 << i);
	if (r)
		cout << r << endl;
	else
		cout << "BAD MEMORY" << endl;
}
