// 2018 AICCSA Programming Contest
// 101968H

#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<bool> vb;
typedef vector<string> vs;
const ll MOD = 1e9 + 7;
const long double EPS = 1e-5;
#define all(x) x.begin(),x.end()

#include <ext/hash_set>
#include <ext/numeric>

int n, L;
vi a, b;

int mem[1003][1003], vis[1003][1003], vf = 0;
int solve(int ctm, int tst) {
	if (ctm > L || tst == n) return 0;
	if (vis[ctm][tst] == vf)
		return mem[ctm][tst];
	vis[ctm][tst] = vf;

	int ret = solve(ctm, tst + 1);
	if (max(ctm, a[tst]) + b[tst] - 1 <= L)
		ret = max(ret, 1 + solve(max(ctm, a[tst]) + b[tst], tst + 1));
	return mem[ctm][tst] = ret;
}


int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	memset(mem, -1, sizeof(mem));
	int t; cin >> t;
	while (t--) {
		vf++;
		cin >> n >> L;
		a.resize(n);
		b.resize(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i] >> b[i];
		}
		cout << solve(1, 0) << "\n";
	}


	return 0;
}