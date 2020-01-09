// 2019 ICPC Universidad Nacional de Colombia Programming Contest
// 102307B

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


inline string reverse(string s) {
	reverse(all(s));
	return s;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	string s; cin >> s;
	int n = s.length();
	for (int i = n / 2 - 1; i < n; ++i) {
		int sz = n - 1 - i;
		if ((n % 2 == 0 || i >= n / 2) && s.substr(i + 1) == reverse(s.substr(i - (sz - 1), sz))) {
			cout << s + reverse(s.substr(0, n - sz * 2)) << endl;
			return 0;
		}

		sz--;
		if (i < n - 1 && s.substr(i + 2) == reverse(s.substr(i - (sz - 1), sz))) {
			cout << s + reverse(s.substr(0, n - sz * 2 - 1)) << endl;
			return 0;
		}
	}
}
