// 2012-2013 ACM-ICPC Central Europe Regional Contest (CERC 12)
// 100624H

#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<bool> vb;
typedef vector<string> vs;
const ll MOD = 1e9 + 7;
const long double EPS = 1e-5;
#define all(x) x.begin(),x.end()
#define SZ(x) (int)(x).size()

#include <ext/hash_set>
#include <ext/numeric>

#define  fr first
#define  sc second

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	while (t--) {
		int n; cin >> n;
		int r = 0;
		for (int i = 0; i < n; ++i) {
			int x, y; cin >> x >> y;
			for (int p = 10; p >= 1; --p) {
				if (x * x + y * y <= (20 * (11 - p)) * (20 * (11 - p))) {
					r += p;
					break;
				}
			}
		}
		cout << r << endl;
	}
	return 0;
}
