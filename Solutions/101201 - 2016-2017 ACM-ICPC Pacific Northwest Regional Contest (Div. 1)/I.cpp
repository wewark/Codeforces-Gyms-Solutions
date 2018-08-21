// 101201 - 2016-2017 ACM-ICPC Pacific Northwest Regional Contest (Div. 1)
// 101201I

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
const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, 1, 0, -1 };
const ll MOD = 1e9 + 7;
const ll INF = 1e10;
const double EPS = 1e-10;
#define mp make_pair
#define all(x) x.begin(),x.end()

int n, k;
deque<pair<ll, ll>> h;

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int x, m; cin >> x >> m;
		if (x)
			h.push_back(mp(x, m));
	}
	h.push_back(mp(0, 0));
	sort(all(h));

	ll r = 0;
	while (h.front().first) {
		ll x = h.front().first, m = h.front().second;
		h.pop_front();
		r += -x * 2 * (m / k);
		m %= k;

		if (m) {
			ll ck = k - m;
			r += -x * 2;
			while (h.front().first && ck) {
				if (ck >= h.front().second) {
					ck -= h.front().second;
					h.pop_front();
				}
				else {
					h.front().second -= ck;
					ck = 0;
				}
			}
		}
	}
	while (h.back().first) {
		ll x = h.back().first, m = h.back().second;
		h.pop_back();
		r += x * 2 * (m / k);
		m %= k;

		if (m) {
			ll ck = k - m;
			r += x * 2;
			while (h.back().first && ck) {
				if (ck >= h.back().second) {
					ck -= h.back().second;
					h.pop_back();
				}
				else {
					h.back().second-=ck;
					ck = 0;
				}
			}
		}
	}
	cout << r << endl;
	cin.ignore(), cin.get();
}
