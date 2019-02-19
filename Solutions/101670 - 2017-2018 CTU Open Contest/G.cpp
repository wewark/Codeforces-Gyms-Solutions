// 2017-2018 CTU Open Contest
// 101670G

#include <bits/stdc++.h>
#include <ext/hash_set>
#include <ext/numeric>

using namespace __gnu_cxx;
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;
using vb = vector<bool>;
using vs = vector<string>;
const int MOD = int(1e9 + 7);
const long double EPS = 1e-8;
const double PI = 3.1415926535897932384626433;
const ll INF = ll(1e9);
int di[] = {0, 0, 0, 1, -1, 1, -1, 1, -1};
int dj[] = {0, 1, -1, 0, 0, 1, -1, -1, 1};
#define all(x) x.begin(),x.end()


int main() {
//	ios::sync_with_stdio(false), cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int n, k;
	while (~scanf("%d %d", &n, &k)) {
		vvi st(n);
		for (int i = 0; i < n; ++i) {
			int sz; scanf("%d", &sz);
			st[i].resize(sz);
			for (int j = 0; j < sz; ++j) {
				scanf("%d", &st[i][j]);
				st[i][j]--;
			}
		}
		vvi v = st;
		st.insert(st.end(), all(v));

		vi cnt(k);
		int dis = 0, tot = 0, ans = INF;
		int a = 0, b = 0;
		while (true) {
			while (b < 2 * n && dis < k) {
				for (auto& i : st[b]) {
					if (cnt[i] == 0) dis++;
					cnt[i]++;
					tot++;
				}
				b++;
			}

			if (dis < k) break;

			while (a < b && dis == k) {
				ans = min(ans, tot);
				for (auto& i : st[a]) {
					cnt[i]--;
					tot--;
					if (cnt[i] == 0) dis--;
				}
				a++;
			}
		}

		if (ans == INF) ans = -1;
		printf("%d\n", ans);
	}
}
