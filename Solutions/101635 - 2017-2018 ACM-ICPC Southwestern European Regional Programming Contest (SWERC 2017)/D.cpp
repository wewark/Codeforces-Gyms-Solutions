// 101635 - 2017-2018 ACM-ICPC Southwestern European Regional Programming Contest (SWERC 2017)
// 101635D

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
const int di[] = { -1, 0, 1, 0, -1, 1, 1, -1 };
const int dj[] = { 0, 1, 0, -1, -1, 1, -1, 1 };
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const long double EPS = 1e-7;
#define all(x) x.begin(),x.end()

int n;
string s;
vs c; vi p; // candy, price

int mem[52][52][402][2][52];
int solve(int idx, int cidx, int cc, bool full, int r) {
	if (cc == n) return -INF;
	if (idx == r)
		return !cidx || cidx == c[cc].length() ? 0 : -INF;

	int& ret = mem[idx][cidx][cc][full][r];
	if (~ret) return ret;
	ret = -INF;

	if (cidx == c[cc].length())
		cidx = cc = 0;

	if (s[idx] == c[cc][cidx])
		ret = max(ret, solve(idx + 1, cidx + 1, cc, full, r) + (!cidx ? p[cc] : 0));
	if (!cidx && !cc && !full)
		ret = max(ret, solve(idx + 1, 0, 0, false, r));
	if (!cidx)
		ret = max(ret, solve(idx, 0, cc + 1, full, r));
	if (cidx) {
		for (int i = idx + 1; i < r; i++) {
			ret = max(ret, solve(i, cidx, cc, false, r) + solve(idx, 0, 0, true, i));
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	memset(mem, -1, sizeof mem);
	cin >> s >> n;
	c.resize(n);
	p.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> c[i] >> p[i];
		c.push_back(c[i]);
		reverse(all(c.back()));
		p.push_back(p[i]);
	}
	n *= 2;

	cout << solve(0, 0, 0, false, s.length()) << endl;
	cin.ignore(), cin.get();
}
