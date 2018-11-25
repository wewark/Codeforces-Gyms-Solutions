// ACM International Collegiate Programming Contest Arabella Collegiate Programming Contest (2018)
// 101972H

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
#define fr first
#define sc second


int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int t; cin >> t;
	while (t--) {
		int n, m, k;
		cin >> n >> m >> k;
		string a, b;
		cin >> a >> b;
		vector<set<char>> bf(130);
		for (int i = k - 1; i < n; i++) {
			bf[a[i]].insert(a[i - k + 1]);
		}

		ll r = 0;
		vi cnt(130);
		for (int i = 0; i < m; ++i) {
			cnt[b[i]]++;
			for (auto &j : bf[b[i]])
				r += cnt[j];
		}
		cout << r << endl;
	}
}