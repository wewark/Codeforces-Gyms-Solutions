// 2013-2014 CT S01E09 2011 German Collegiate Programming Contest (GCPC 2011)  GCJ 2009 R3 C-D
// 100274A

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
const int di[] = {0, 0, 1, -1};
const int dj[] = {1, -1, 0, 0};
const ll MOD = 1e9 + 7;
const long double EPS = 1e-5;
#define all(x) x.begin(),x.end()

#include <ext/hash_set>
#include <ext/numeric>

const ll INF = 1e18;

ll f(ll n, ll k) {
	ll p = k, res = 0;
	while (p <= n) {
		res += n / p;
		if(p >= LLONG_MAX/k)return res;
		p *= k;
	}
	return res;
}

vector<pair<ll,int> > pf;

void fact(ll n) {
	pf.clear();
	for (ll i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			pf.push_back({i,0});
			while (n % i == 0) {
				n /= i;
				pf.back().second++;
			}
		}
	}
	if (n > 1)
		pf.push_back({n,1});
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	int t;
	cin >> t;
	while (t--) {
		ll n, k;
		cin >> n >> k;
		fact(k);
		ll res = LLONG_MAX;
		for (auto x : pf) {
			res = min(res, f(n, x.first)/x.second);
		}
		cout << res << "\n";
	}
}