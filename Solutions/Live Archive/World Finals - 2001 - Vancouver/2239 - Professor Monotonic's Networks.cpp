// World Finals >> 2001 - Vancouver
// 2239 - Professor Monotonic's Networks

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
const ll INF = 1e18;
int di[] = { 0, 0, 1, -1 };
int dj[] = { 1, -1, 0, 0 };
#define all(x) x.begin(),x.end()

int n, k;
vii p;
vi cnt;

bool good(int msk) {
	vi v(n);
	for (int i = 0; i < n; ++i)
		if (msk & (1 << i))
			v[i] = 1;

	for (int i = 0; i < k; ++i)
		if (v[p[i].first] > v[p[i].second])
			swap(v[p[i].first], v[p[i].second]);

	for (int i = 1; i < n; ++i)
		if (v[i] < v[i - 1])
			return false;
	return true;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int tt = 0;
	while (cin >> n >> k && n) {
		p.resize(k);
		cnt.assign(n, 0);
		int d = 0;
		for (int i = 0; i < k; ++i) {
			cin >> p[i].first >> p[i].second;
			p[i].first--, p[i].second--;
			int mx = max(cnt[p[i].first], cnt[p[i].second]) + 1;
			cnt[p[i].first] = cnt[p[i].second] = mx;
			d = max(d, mx);
		}

		bool sorting = true;
		for (int msk = 0; msk < (1 << n); ++msk)
			if (!good(msk)) {
				sorting = false; break;
			}

		cout << "Case " << ++tt << " is ";
		cout << (sorting ? "" : "not ") << "a sorting network ";
		cout << "and operates in " << d << " time unit" << (d == 1 ? "" : "s") << "." << endl;
	}

}