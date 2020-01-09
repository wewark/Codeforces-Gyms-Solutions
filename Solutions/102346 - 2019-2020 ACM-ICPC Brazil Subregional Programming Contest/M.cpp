// 2019-2020 ACM-ICPC Brazil Subregional Programming Contest
// 102346M

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


int n, c, t;
vi p;

inline bool valid(ll x) {
	ll amount = 0, comp = 0;
	for (int i = 0; i < n; ++i) {
		if (p[i] > x)
			return false;
		if (amount + p[i] <= x) {
			amount += p[i];
		} else {
			comp++;
			amount = p[i];
			if (comp == c)
				return false;
		}
	}
	return true;
}

ll BS() {
	ll a = *max_element(all(p)), b = 1e10 + 10, mid = (a + b) / 2;
	while (a < b) {
		if (valid(mid))
			b = mid;
		else
			a = mid + 1;
		mid = (a + b) / 2;
	}
	return (mid + t - 1) / t;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	cin >> n >> c >> t;
	p.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> p[i];
	}
	cout << BS() << endl;
}
