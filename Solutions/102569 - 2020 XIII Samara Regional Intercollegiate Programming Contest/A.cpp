// 2020 XIII Samara Regional Intercollegiate Programming Contest
// 102569A

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

	int n; cin >> n;
	vi a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	vb pos(n);
	for (int i = n - 1; i >= 0; i -= 2) {
		pos[i] = true;
	}
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += pos[i] ? a[i] : -a[i];
	}

	int q; cin >> q;
	while (q--) {
		ll l, r, v; cin >> l >> r >> v;
		l--, r--;
		if (pos[l]) {
			ans += (r - l + 1 + 1) / 2 * v;
			ans -= (r - l + 1) / 2 * v;
		} else {
			ans += (r - l + 1) / 2 * v;
			ans -= (r - l + 1 + 1) / 2 * v;
		}
		cout << ans << endl;
	}
}
