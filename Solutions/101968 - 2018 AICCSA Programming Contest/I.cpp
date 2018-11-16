// 2018 AICCSA Programming Contest
// 101968I

#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ll;
typedef vector<ll> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<bool> vb;
typedef vector<string> vs;
const ll MOD = 1e9 + 7;
const long double EPS = 1e-5;
#define all(x) x.begin(),x.end()

#include <ext/hash_set>
#include <ext/numeric>

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;
	while (t--) {
		int m, n, R; cin >> m >> n >> R;
		vvi v(m, vi(n));
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> v[i][j];
			}
		}

		ll ans = 0, av = 0, avnxt = 0;
		vll buses(m);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				ll need = (v[j][i] + R - 1) / R;
				ll cav = buses[j];
				ll mn = min(need, cav);
				buses[j] = mn;
				need -= mn;
				cav -= mn;
				avnxt += cav;

				if (need) {
					mn = min(need, av);
					buses[j] += mn;
					need -= mn;
					av -= mn;
				}
				if (need) {
					ans += need;
					buses[j] += need;
				}
			}
			av += avnxt;
			avnxt = 0;
		}
		cout << ans << endl;
	}


	return 0;
}