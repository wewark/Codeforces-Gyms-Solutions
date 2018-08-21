// 101801 - Tishreen-CPC 2018
// 101801E

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
const int di[] = { 0, 0, 1, -1 };
const int dj[] = { 1, -1, 0, 0 };
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const long double EPS = 1e-6;
#define all(x) x.begin(),x.end()

vvi mem(105, vi((1 << 7) + 7, -1));
ll solve(int left, int cxor) {
	ll& ret = mem[left][cxor];
	if (~ret) return ret;
	ret = 0;

	if (!left && cxor)
		ret++;
	for (int i = 1; i <= left; i++) {
		ret += solve(left - i, cxor ^ i);
		ret %= MOD;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		cout << solve(n, 0) << endl;
	}
	cin.ignore(), cin.get();
}
