// 2020 XIII Samara Regional Intercollegiate Programming Contest
// 102569B

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vb = vector<bool>;
using pii = pair<int, int>;
using vii = vector<pii>;
using vs = vector<string>;
#define all(x) x.begin(), x.end()
// int di[] = {0, 1, 0, -1};
// int dj[] = {1, 0, -1, 0};
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const double PI = 3.14159265359;



int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#else
	//	freopen("document.in", "r", stdin);
//	freopen("document.out", "w", stdout);
#endif

	int n, t; cin >> n >> t;
	vi v(n);
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}

	int a = 0, b = 0;
	auto it2 = upper_bound(all(v), t);
	if (it2 == v.begin()) {
		cout << 0 << endl;
		return 0;
	}
	it2--;
	b = it2 - v.begin();

	auto it1 = lower_bound(all(v), 0);
	a = it1 - v.begin();

	ans = max(ans, b - a + 1);
	while (a && -v[a - 1] <= t) {
		while (a) {
			if (v[b] >= 0) {
				if (!(-v[a - 1] * 2 + v[b] <= t ||
					-v[a - 1] + v[b] * 2 <= t))
					break;
			} else {
				if (-v[a - 1] > t)
					break;
			}
			a--;
		}

		ans = max(ans, b - a + 1);
		b--;
	}

	cout << ans << endl;
}
