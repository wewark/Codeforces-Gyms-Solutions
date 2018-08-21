// 100285 - 2013-2014 ACM-ICPC, NEERC, Eastern Subregional Contest
// 100285I

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<ll, ll> pii;
typedef vector<pii> vii;
typedef vector<bool> vb;
typedef vector<string> vs;
const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, 1, 0, -1 };
const ll MOD = 5e6;
const ll INF = 1e8;
const long double EPS = 1e-6;
#define mp make_pair
#define all(x) x.begin(),x.end()

ll n, m, k; vi num, cum;

int bs(int b) {
	int ob = b;
	if (b == -1 || cum[b] - cum[0] <= k) return -1;
	ll a = 0, mid = (a + b) / 2;
	while (a < b) {
		if (cum[ob] - cum[mid] <= k)
			b = mid - 1;
		else
			a = mid;
		mid = (a + b + 1) / 2;
	}
	return mid;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m >> k;
	num.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	cum = num;
	for (int i = 1; i < n; i++) {
		cum[i] += cum[i - 1];
	}

	vi ds(m);
	for (int i = 0; i < m; i++) {
		cin >> ds[i];
	}

	ll cur = 0; ll ct = 1;
	while (cur < n) {
		if (binary_search(all(ds), ct))
			cur = bs(cur - 1) + 1, ct++;
		else {
			auto it = upper_bound(all(ds), ct);
			if (it == ds.end() || *it - ct >= n - cur) {
				ct += n - cur; break;
			}
			cur += *it - ct;
			ct = *it;
		}
	}
	cout << ct - 1 << endl;
	cin.ignore(), cin.get();
}
