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

int n;
vector<vll> g;

ll bs(int d, int r) {
	ll a = -1e16, b = 1e16, mid = (a + b) / 2;
	while (a + 1 < b) {
		if (d + mid * n > r + mid)
			b = mid - 1;
		else
			a = mid;
		mid = (a + b) / 2;
	}
	return mid;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n;
	g.assign(n, vll(n));

	vll cs(n);
	ll sum = LLONG_MAX;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> g[i][j];
			cs[i] += g[i][j];
		}
		sum = min(sum, cs[i]);
	}

	sum++;
	ll ds = 0, ods = 0;
	for (int i = 0; i < n; i++) {
		g[i][i] = sum - cs[i];
		ds += g[i][i];
		ods += g[i][n - i - 1];
	}
	ll r = g[0][0] + cs[0];
	if (n % 2 == 1)
		ods -= g[n / 2][n / 2], ds -= g[n / 2][n / 2];
	ll m = (ods - ds) / (n - (n % 2));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << g[i][j] + (i == j ? m : 0) << " \n"[j == n - 1];
		}
	}

	cin.ignore(), cin.get();
}
