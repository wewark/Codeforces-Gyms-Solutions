// 2009-2010 VI International Zhautykov Olympiad
// 100143A

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vb = vector<bool>;
using pii = pair<int, int>;
using vii = vector<pii>;
using vs = vector<string>;
#define all(x) x.begin(), x.end()
// int di[] = {0, 1, 0, -1};
// int dj[] = {1, 0, -1, 0};
const ll MOD = 998244353;
const ll INF = 1e9;


int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#else
	freopen("document.in", "r", stdin);
	freopen("document.out", "w", stdout);
#endif

	int n; cin >> n;
	int cur = 0, ans = 0;
	vi v(5);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 5; ++j) {
			cin >> v[j];
		}
		while (v[cur] == 0) {
			ans++;
			cur++;
			if (cur == 5)
				cur = 0, ans += 2;
		}
		cur++;
		ans++;
		if (cur == 5 && i < n - 1)
			cur = 0, ans += 2;
	}
	cout << ans << endl;
}
