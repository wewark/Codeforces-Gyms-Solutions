// 101673 - 2017-2018 ACM-ICPC East Central North America Regional Contest (ECNA 2017)
// 101673G

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
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const long double EPS = 1e-10;
#define mp make_pair
#define all(x) x.begin(),x.end()

int n, m;
vi num;

vvi mem(105, vi(20005, -1));
ll solve(int idx, ll cc) {
	if (idx >= n) return 0;
	ll& ret = mem[idx][cc];
	if (~ret) return ret;
	ret = 0;

	ret = max(ret, solve(idx + 1, (cc * 2) / 3) + min(num[idx], cc));
	if (cc == m) {
		ret = max(ret, solve(idx + 1, cc));
	}
	ret = max(ret, solve(idx + 2, cc) + min(num[idx], cc));
	ret = max(ret, solve(idx + 2, m));
	return ret;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m;
	num.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	cout << solve(0, m) << endl;
	//cin.ignore(), cin.get();
}
