// 101778 - 2018 JUST Programming Contest 1.0
// 101778A

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<double, int> pii;
typedef vector<pii> vii;
typedef vector<bool> vb;
typedef vector<string> vs;
const int di[] = { 0, 1 };
const int dj[] = { 1, 0 };
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const long double EPS = 1e-7;
#define all(n) n.begin(),n.end()

ll fastPow(ll a, int p = MOD - 2, int m = MOD) {
	if (p == 0)
		return 1;
	if (p % 2 == 1)
		return (a * fastPow(a, p - 1, m)) % m;
	ll c = fastPow(a, p / 2, m);
	return  (c * c) % m;
}

vi memFact(5e5 + 5, -1);
ll fact(int n) {
	if (~memFact[n]) return memFact[n];
	if (!n) return 1;
	return memFact[n] = (n * fact(n - 1)) % MOD;
}

ll nCr(ll n, ll r) {
	return fact(n)
		* fastPow(fact(r) * fact(n - r) % MOD) % MOD;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		if (abs(n) > m || abs(n) % 2 != m % 2)
			cout << 0 << endl;
		else
			cout << nCr(m, (n + m) / 2) * fastPow(fastPow(2,m)) % MOD << endl;
	}
	cin.ignore(), cin.get();
}
