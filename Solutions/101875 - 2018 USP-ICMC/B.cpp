// 2018 USP-ICMC
// 101875B

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

vi kmp(string& s) {
	int m = s.size();
	vi pi(m + 1);
	pi[0] = -1;
	for (int i = 0; i < m; ++i) {
		pi[i + 1] = pi[i];
		while (pi[i + 1] > -1 && s[pi[i + 1]] != s[i])
			pi[i + 1] = pi[pi[i + 1]];
		pi[i + 1]++;
	}
	return pi;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int n; string s;
	cin >> n >> s;
	s += s;
	vi pi = kmp(s);
	for (int i = 0; i < 2 * n - 1; ++i) {
		if (s[i + 1] < s[pi[i + 1]]) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
}
