// 101801 - Tishreen-CPC 2018
// 101801I

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

ll fastPow(ll a, int p, int m = MOD) {
	if (p == 0)
		return 1;
	if (p % 2 == 1)
		return (a * fastPow(a, p - 1, m)) % m;
	ll c = fastPow(a, p / 2, m);
	return  (c * c) % m;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int q; cin >> q;
		vi num(n), even(n);
		for (int i = 0; i < n; i++) {
			cin >> num[i];
			even[i] = (num[i] % 2 == 0);
			if (i)
				even[i] += even[i - 1];
		}

		while (q--) {
			int l, r, tp; cin >> l >> r >> tp;
			l--, r--;

			ll en = even[r] - (l ? even[l - 1] : 0);
			ll on = r - l + 1 - en;
			ll evns = fastPow(2, en);
			ll odds = fastPow(2, on);
			if (tp == 0) {
				cout << (odds * (evns - 1)) % MOD << endl;
			}
			else {
				cout << (odds - 1) % MOD << endl;
			}
		}
	}
	cin.ignore(), cin.get();
}
