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
const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, 1, 0, -1 };
const ll MOD = 5e6;
const ll INF = 1e8;
const double EPS = 1e-12;
#define mp make_pair
#define all(x) x.begin(),x.end()

int n, m;
vs num;

int mem[40][400][10][40];
int solve(int rw, int cl, int prvDigit, int b) {
	if (rw == n) return 0;
	if (cl == m) return 0;
	if (rw > b) return 0;
	if (prvDigit > 9) return INF;
	int& ret = mem[rw][cl][prvDigit][b];
	if (ret != -1) return ret;

	ret = solve(rw, cl, prvDigit + 1, b);
	int ch = 0;
	for (int i = rw; i <= b; i++) {
		ch += (num[i][cl] - '0' != prvDigit);
		ret = min(ret, solve(i + 1, cl, prvDigit + 1, b)
			+ solve(rw, cl + 1, 0, i) + ch);
	}

	return ret;
}

void build(int rw, int cl, int prvDigit, int b) {
	if (rw == n) return;
	if (cl == m) return;
	if (rw > b) return;
	if (prvDigit > 9) return;

	int type = 1, mxi = -1;
	int ret = solve(rw, cl, prvDigit + 1, b);
	int ch = 0;
	for (int i = rw; i <= b; i++) {
		ch += num[i][cl] - '0' != prvDigit;
		int x = solve(i + 1, cl, prvDigit + 1, b)
			+ solve(rw, cl + 1, 0, i) + ch;
		if (x < ret) {
			type = 2;
			//num[i][cl] = prvDigit + '0';
			mxi = i;
			ret = x;
		}
	}

	if (type == 1)
		build(rw, cl, prvDigit + 1, b);
	else {
		for (int i = rw; i <= mxi; i++)
			num[i][cl] = prvDigit + '0';
		build(mxi + 1, cl, prvDigit + 1, b);
		build(rw, cl + 1, 0, mxi);
	}
}

void init() {
	for (int a = 0; a < 40; a++) for (int b = 0; b < 400; b++)
		for (int c = 0; c < 10; c++) for (int d = 0; d < 40; d++)
			mem[a][b][c][d] = -1;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m;
	num.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	init();
	//cout << solve(0, 0, 0, n - 1) << endl;
	build(0, 0, 0, n - 1);
	for (int i = 0; i < n; i++) {
		cout << num[i] << endl;
	}
	cin.ignore(), cin.get();
}
