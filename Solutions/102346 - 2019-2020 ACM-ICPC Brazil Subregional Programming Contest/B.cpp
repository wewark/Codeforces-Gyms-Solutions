// 2019-2020 ACM-ICPC Brazil Subregional Programming Contest
// 102346B

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

	int n; cin >> n;
	int mx = -1, mxi = -1;
	for (int i = 0; i < n; ++i) {
		int x; cin >> x;
		if (x > mx) {
			mx = x;
			mxi = i;
		}
	}
	cout << (mxi == 0 ? "S" : "N") << endl;
}
