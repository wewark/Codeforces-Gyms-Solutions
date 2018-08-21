// 101061 - Higher Institute for Applied Sciences and Technology Collegiate Programming Contest 2016
// 101061C

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<pair<int, int>, int> pii;
typedef vector<pii> vii;
typedef vector<bool> vb;
typedef vector<string> vs;
const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, 1, 0, -1 };
const ll MOD = 1e9 + 7;
const ll INF = 1e10;
const double EPS = 1e-10;
#define mp make_pair
#define all(x) x.begin(),x.end()

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		vll cap(n);
		for (int i = 0; i < n; i++)
			cin >> cap[i];
		vll f(n);
		for (int i = 0; i < m; i++) {
			ll x, y; cin >> x >> y; x--;
			f[x] += y;
		}

		ll w = 0;
		vll r(n);
		for (int i = 0; i < n; i++) {
			if (f[i] > cap[i]) {
				r[i] = cap[i];
				if (i < n - 1)
					f[i + 1] += f[i] - cap[i];
				else
					w += f[i] - cap[i];
			}
			else r[i] = f[i];
		}

		cout << w << endl;
		for (int i = 0; i < n; i++)
			cout << r[i] << " \n"[i == n - 1];
	}
	cin.ignore(), cin.get();
}
