// 2018 USP-ICMC
// 101875F

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

	int n; cin >> n;
	unordered_set<ll> love, hate;
	bool first = true;
	for (int i = 0; i < n; ++i) {
		int t, sz; cin >> t >> sz;

		if (t == 1) {
			unordered_set<ll> nxt;
			for (int j = 0; j < sz; ++j) {
				ll x; cin >> x;
				if (first) {
					if (hate.find(x) == hate.end())
						nxt.insert(x);
					continue;
				}

				if (love.find(x) != love.end())
					nxt.insert(x);
			}

			love = nxt;
			first = false;
		}
		else {
			for (int j = 0; j < sz; ++j) {
				ll x; cin >> x;
				love.erase(x);
				hate.insert(x);
			}
		}
	}

	if (first)
		cout << ll(1e18) - hate.size() << endl;
	else
		cout << love.size() << endl;
}
