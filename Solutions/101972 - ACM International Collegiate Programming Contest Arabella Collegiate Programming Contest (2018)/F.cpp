// ACM International Collegiate Programming Contest Arabella Collegiate Programming Contest (2018)
// 101972F

#include <bits/stdc++.h>
#include <ext/hash_set>
#include <ext/numeric>

using namespace std;
typedef long long ll;
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
#define SZ(x) (int)x.size()


int main() {
//	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int t; cin >> t;
	while (t--) {
		vi num(26);
		for (int i = 0; i < 26; ++i) {
			cin >> num[i];
		}
		sort(num.rbegin(), num.rend());

		int l = 0, sz = INT_MAX;
		if (num[0] == 0) sz = 0;
		for (int i = 0; i < 26; ++i) {
			if (num[i] >= 2) {
				l += 2;
				sz = min(sz, num[i] / 2);
			}
			else if (num[i] == 1) {
				l++;
				int cnt = 0;
				for (int j = i; j < 26; ++j) {
					cnt += num[j];
				}
				sz = min(sz, cnt);
				break;
			}
		}
		cout << l <<  " " << sz << endl;
	}
}