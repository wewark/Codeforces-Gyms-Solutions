// 101778 - 2018 JUST Programming Contest 1.0
// 101778B

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

ll n, a;

inline bool valid(ll x) {
	return x + 1 <= n && x * (x + 1) / 2 <= n * (a - 1);
}

ll bs() {
	ll a = 0, b = 1e9, mid = (a + b + 1) / 2;
	while (a < b) {
		if (valid(mid))
			a = mid;
		else
			b = mid - 1;
		mid = (a + b + 1) / 2;
	}
	return mid;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> n >> a;
		cout << bs() + 1 << endl;
	}
	cin.ignore(), cin.get();
}
