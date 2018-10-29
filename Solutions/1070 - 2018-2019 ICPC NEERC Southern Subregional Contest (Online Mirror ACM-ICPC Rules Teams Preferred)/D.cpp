// 2018-2019 ICPC NEERC Southern Subregional Contest (Online Mirror ACM-ICPC Rules Teams Preferred)
// 1070D

#include <bits/stdc++.h>

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
#define SZ(x) (int)(x).size()

#include <ext/hash_set>
#include <ext/numeric>

#define  fr first
#define  sc second

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int n, k; cin >> n >> k;
	deque<int> num(n);
	for (int i = 0; i < n; ++i) {
		cin >> num[i];
//num[i] = 1e9;
	}

	ll r = 0;
	while (!num.empty()) {
		if (!num[0]) {
			num.pop_front();
			continue;
		}
		r += num[0] / k;
		num[0] %= k;
		int cur = num[0];
		if (cur && num.size() > 1) {
			int mn = min(k - cur, num[1]);
			num[1] -= mn;
			cur += mn;
		}
		if (cur) r++;
		num.pop_front();
	}

	cout << r << endl;

	return 0;
}