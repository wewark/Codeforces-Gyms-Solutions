// 2018-2019 ACM-ICPC Brazil Subregional Programming Contest
// 101908I

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
const int di[] = {0, 0, 1, -1};
const int dj[] = {1, -1, 0, 0};
const ll MOD = 1e9 + 7;
const long double EPS = 1e-5;
#define all(x) x.begin(),x.end()

#include <ext/hash_set>
#include <ext/numeric>
int a[30];
map<ll,int>m;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int n, m; cin >> n >> m;
	vvi sw(n);
	vb lm(m);
	int l; cin >> l;
	for (int i = 0; i < l; ++i) {
		int x; cin >> x; x--;
		lm[x] = true;
	}
	for (int i = 0; i < n; ++i) {
		int sz; cin >> sz;
		sw[i].resize(sz);
		for (int j = 0; j < sz; ++j) {
			cin >> sw[i][j]; sw[i][j]--;
		}
	}

	bool f = false;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < sw[i].size(); ++j) {
			if (lm[sw[i][j]]) l--;
			else l++;
			lm[sw[i][j]] = !lm[sw[i][j]];
		}
		ans++;
		if (l == 0) {
			f = true; break;
		}
	}

	if (!f)
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < sw[i].size(); ++j) {
				if (lm[sw[i][j]]) l--;
				else l++;
				lm[sw[i][j]] = !lm[sw[i][j]];
			}
			ans++;
			if (l == 0) {
				f = true; break;
			}
		}

	cout << (f ? ans : -1) << endl;
	return 0;
}
