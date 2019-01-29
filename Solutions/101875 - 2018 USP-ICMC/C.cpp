// 2018 USP-ICMC
// 101875C

#include <bits/stdc++.h>
#include <ext/hash_set>
#include <ext/numeric>

using namespace __gnu_cxx;
using namespace std;

using ll = long long;
using vi = vector<ll>;
using vll = vector<ll>;
using vvi = vector<vi>;
using pii = pair<ll, ll>;
using vii = vector<pii>;
using vb = vector<bool>;
using vs = vector<string>;
const int MOD = (int) 1e9 + 7;
const long double EPS = 1e-4;
const double PI = 3.1415926535897932384626433;
const ll INF = 1e9;
int di[] = {0, 0, 1, -1};
int dj[] = {1, -1, 0, 0};
#define all(x) x.begin(),x.end()

vi primeFactorize(ll n) {
	vi ret;
	while (n % 2 == 0) {
		ret.push_back(2);
		n /= 2;
	}
	for (ll i = 3; i * i <= n; ++i) {
		while (n % i == 0)
			ret.push_back(i), n /= i;
	}
	if (n > 2) ret.push_back(n);
	return ret;
}

int b;
vi f;

int mem[50003][1003];
ll solve(int idx, int cb) {
	if (idx == f.size()) return cb == b;

	int& ret = mem[idx][cb];
	if (~ret) return ret;
	ret = 0;

	for (int i = 1; i <= f[idx] + 1; ++i) {
		if (cb * i > b) break;
		ret += solve(idx + 1, cb * i);
		ret %= MOD;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	memset(mem, -1, sizeof(mem));
	int n; cin >> b >> n;
	map<ll, int> m;
	for (int i = 0; i < n; ++i) {
		ll x; cin >> x;
		vi fact = primeFactorize(x);
		for (auto& j : fact)
			m[j]++;
	}

	for (auto& i : m)
		f.push_back(i.second);

	cout << solve(0, 1) << endl;
}
