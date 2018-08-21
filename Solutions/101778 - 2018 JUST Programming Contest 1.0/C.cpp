// 101778 - 2018 JUST Programming Contest 1.0
// 101778C

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

ll phi(int n) {
	int result = n;
	for (int p = 2; p * p <= n; ++p) {
		if (n % p == 0) {
			while (n % p == 0)
				n /= p;
			result -= result / p;
		}
	}

	if (n > 1)
		result -= result / n;
	return result;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int t; cin >> t;
	while (t--) {
		ll n; cin >> n;
		cout << phi(n) * (n - 1) << endl;
	}
	cin.ignore(), cin.get();
}
