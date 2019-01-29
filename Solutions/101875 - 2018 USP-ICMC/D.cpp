// 2018 USP-ICMC
// 101875D

#include <bits/stdc++.h>
#include <ext/hash_set>
#include <ext/numeric>

using namespace __gnu_cxx;
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using pii = pair<ll, ll>;
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


int main() {
	ios::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	ll n; cin >> n;
	pii a, b; cin >> a.first >> a.second >> b.first >> b.second;
	ll d = abs(a.first - b.first);
	d += abs(a.second - b.second);

	if (d > n) cout << 0 << endl;
	else {
		ll ans = (n - d) / 2 + (d > 0);
		cout << ans << endl;
	}

}
