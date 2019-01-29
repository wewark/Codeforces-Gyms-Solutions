// 2018 USP-ICMC
// 101875G

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
const int MOD = (int) 1e9 + 7;
const long double EPS = 1e-4;
const double PI = 3.1415926535897932384626433;
const ll INF = 1e9;
int di[] = {0, 0, 1, -1};
int dj[] = {1, -1, 0, 0};
#define all(x) x.begin(),x.end()

using ld = long double;

inline ld pos(pii& a, ld& t) {
	return ld(a.first) + t * a.second;
}

double meet(pii a, pii b) {
	return (b.first - a.first) / double(a.second - b.second);
}

bool valid(vii v, ld t) {
	for (int i = 0; i < v.size() - 1; ++i) {
		if (pos(v[i], t) < pos(v.back(), t))
			return false;
	}
	return true;
}

ld BS(vii& v) {
	ld a = 0, b = 2e9, mid = (a + b) / 2;
	for (int i = 0; i < 100; ++i) {
		if (valid(v, mid))
			b = mid;
		else
			a = mid;
		mid = (a + b) / 2;
	}
	return mid;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int n; cin >> n;
	vii c(n);
	for (int i = 0; i < n; ++i) {
		cin >> c[i].first >> c[i].second;
	}
	sort(all(c));

	double ans = 0;
	for (int i = n - 2; i >= 0; --i) {
		if (c[i].second > c[i + 1].second) {
			ans = max(ans, meet(c[i], c[i + 1]));
			c[i] = c[i + 1];
		}
	}

	cout << fixed << setprecision(10) << ans << endl;
}