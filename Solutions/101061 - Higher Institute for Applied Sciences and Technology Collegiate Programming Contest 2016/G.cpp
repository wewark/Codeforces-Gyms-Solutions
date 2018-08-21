// 101061 - Higher Institute for Applied Sciences and Technology Collegiate Programming Contest 2016
// 101061G

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

ll bigmod(ll a, int p, int m = MOD) {
	if (p == 0)
		return 1;
	if (p % 2 == 1)
		return ((a % m) * (bigmod(a, p - 1, m) % m)) % m;
	ll c = bigmod(a, p / 2, m);
	return (c * c) % m;
}

ll modInv(ll n) {
	return bigmod(n, MOD - 2);
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int t; cin >> t;
	while (t--) {
		ll m;
		string n;
		cin >> m >> n;
		ll x = bigmod(10, n.length());
		cout << (((stoll(n) * (1 - bigmod(x, m))) % MOD) * modInv(1 - x)) % MOD << endl;
	}
	cin.ignore(), cin.get();
}
