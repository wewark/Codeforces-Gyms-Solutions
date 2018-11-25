// ACM International Collegiate Programming Contest Arabella Collegiate Programming Contest (2018)
// 101972A

#include <bits/stdc++.h>
#include <ext/hash_set>
#include <ext/numeric>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<bool> vb;
typedef vector<string> vs;
const ll MOD = 1e9 + 7;
const long double EPS = 1e-5;
#define all(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define fr first
#define sc second

vi special(int n) {
	vi ret;
	bool neg = n < 0;
	if (neg) n = -n;
	string s = to_string(n);
	for (int i = 0; i < s.length(); ++i) {
		int num = (ll(s[i] - '0')) * pow(10, s.length() - 1 - i);
		if (num)
			ret.push_back(num);
	}
	if (neg)
		for (int i = 0; i < ret.size(); ++i) {
			ret[i] = -ret[i];
		}
	return ret;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int t; cin >> t;
	while (t--) {
		int a, b; cin >> a >> b;
		vi av = special(a);
		vi bv = special(b);

		for (int i = 0; i < av.size(); ++i) {
			for (int j = 0; j < bv.size(); ++j) {
				if (i || j) cout << "+ ";
				cout << av[i] << " x " << bv[j] << " \n"[i == av.size() - 1 && j == bv.size() - 1];
			}
		}
	}


}