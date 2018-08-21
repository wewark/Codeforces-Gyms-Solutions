// 101754 - Yandex.Algorithm 2018, second qualification round
// 101754B

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
const int di[] = { -1, 0, 1, 0, -1, 1, 1, -1 };
const int dj[] = { 0, 1, 0, -1, -1, 1, -1, 1 };
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const long double EPS = 1e-7;
#define all(n) n.begin(),n.end()

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	ll n, m; cin >> n >> m;
	vll a(n), b(m);
	ll mxa = -1, mxai = -1;
	ll mxb = -1, mxbi = -1;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] > mxa)
			mxa = a[i], mxai = i;
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i];
		if (b[i] > mxb)
			mxb = b[i], mxbi = i;
	}

	ll last = n - 1;
	while (a[last] != mxa) last--;

	ll r = 0;
	for (int i = 0; i < mxai; i++) {
		r += 1e9 * a[i];
		r += b[0];
	}
	for (int i = 0; i <= mxbi; i++) {
		r += b[i];
		r += 1e9 * mxa;
	}
	for (int i = mxai + 1; i <= last; i++) {
		r += mxb;
		r += 1e9 * a[i];
	}
	for (int i = mxbi + 1; i < m; i++) {
		r += 1e9 * mxa;
		r += b[i];
	}
	for (int i = last + 1; i < n; i++) {
		r += 1e9 * a[i];
		r += b.back();
	}
	cout << r << endl;
	cin.ignore(), cin.get();
}
