// 2019-2020 ACM-ICPC Brazil Subregional Programming Contest
// 102346H

#include <bits/stdc++.h>

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
const int MOD = int(998244353);
const long double EPS = 1e-8;
const double PI = acos(-1.0);
const ll INF = ll(1e9);
int di[] = {0, 1, 0, -1};
int dj[] = {1, 0, -1, 0};
#define all(x) x.begin(),x.end()


int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int v, n; cin >> v >> n;
	// More complex O(1) solution
	ll s = v * n;
	for (ll i = 10; i < 100; i += 10) {
		cout << (i * s + 99) / 100 << " \n"[i == 90];
	}
}