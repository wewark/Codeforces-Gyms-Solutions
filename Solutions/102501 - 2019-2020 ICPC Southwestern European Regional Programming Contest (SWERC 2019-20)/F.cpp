// 2019-2020 ICPC Southwestern European Regional Programming Contest (SWERC 2019-20)
// 102501F - Geometry

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vb = vector<bool>;
using pii = pair<ll, ll>;
using vii = vector<pii>;
using vs = vector<string>;
#define all(x) x.begin(), x.end()
// int di[] = {0, 1, 0, -1};
// int dj[] = {1, 0, -1, 0};
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
#define x first
#define y second

long double polygonArea(vii& v) {
	ll ret = 0;
	for (int i = 0; i < v.size(); ++i) {
		ret += (v[i].x * v[(i + 1) % v.size()].y - v[i].y * v[(i + 1) % v.size()].x);
	}
	return abs(ret / (long double)2);
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int n; cin >> n;
	long double ans = 0;
	for (int i = 0; i < n; ++i) {
		int p; cin >> p;
		vii v(p);
		for (int j = 0; j < p; ++j) {
			cin >> v[j].x >> v[j].y;
		}
		ans += polygonArea(v);
	}
	cout << ll(ans) << endl;
}
