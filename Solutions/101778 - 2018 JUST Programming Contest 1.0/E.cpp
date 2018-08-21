// 101778 - 2018 JUST Programming Contest 1.0
// 101778E

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

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, x, y;
		cin >> n >> x >> y;

		int r = -2;
		vii num(n);
		for (int i = 0; i < n; i++) {
			int d, m; cin >> d >> m;
			
			if (d <= x && m >= y && (
				r == -2 ||
				d < num[r].first ||
				d == num[r].first && m > num[r].second))
				r = i;

			num[i] = pii{ d,m };
		}
		cout << r + 1 << endl;
	}
	cin.ignore(), cin.get();
}
