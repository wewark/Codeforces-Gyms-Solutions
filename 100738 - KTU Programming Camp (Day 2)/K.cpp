#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<bool> vb;
typedef vector<string> vs;
const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, 1, 0, -1 };
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const double EPS = 1e-5;
#define mp make_pair
#define all(x) x.begin(),x.end()

ll a, b, p;

inline bool overflow(ll n) {
	return a > LLONG_MAX / cbrt(n) || b > LLONG_MAX / sqrt(n);
}

inline ll f(ll n) {
	if (overflow(n)) return LLONG_MAX;
	return (long double)a * cbrt(n) + b * sqrt(n);
}

ll bs() {
	ll x = 0, y = 1e18, mid = (x + y) / 2;
	while (x < y) {
		if (f(mid) < p)
			x = mid + 1;
		else
			y = mid;
		mid = (x + y) / 2;
	}
	return mid;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> a >> b >> p;
	cout << bs() << endl;
	cin.ignore(), cin.get();
}