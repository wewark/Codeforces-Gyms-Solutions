// 101778 - 2018 JUST Programming Contest 1.0
// 101778J

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

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int t; cin >> t;
	while (t--) {
		ll l, r; cin >> l >> r;
		if (r <= 10) {
			cout << -1 << endl;
			continue;
		}

		string s; s = to_string(r);
		ll a = stoll(s.substr(0, (s.length() + 1) / 2));
		ll b = stoll(s.substr((s.length() + 1) / 2));
		if (b == 0) {
			r--;
			s = to_string(r);
			a = stoll(s.substr(0, (s.length() + 1) / 2));
			b = stoll(s.substr((s.length() + 1) / 2));
		}

		ll rs = -1;
		for (ll i = b; i > 0 && r >= l; i--, r--) {
			if (gcd(i, a) == 1) {
				rs = r; break;
			}
		}

		cout << rs << endl;
	}
	cin.ignore(), cin.get();
}
