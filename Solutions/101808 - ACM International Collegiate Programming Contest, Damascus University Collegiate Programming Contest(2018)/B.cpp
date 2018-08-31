// 101808 - ACM International Collegiate Programming Contest, Damascus University Collegiate Programming Contest(2018)
// 101808B

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
const int di[] = { 0, 0, 1, -1 };
const int dj[] = { 1, -1, 0, 0 };
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const long double EPS = 1e-6;
#define all(x) x.begin(),x.end()
#include <unordered_map>
#include <unordered_set>

vi mem(2e7, -1);
ll fastPow(ll a, int p, int m) {
	if (~mem[p]) return mem[p];

	if (p == 0)
		return mem[p] = 1;
	if (p % 2 == 1)
		return mem[p] = (a * fastPow(a, p - 1, m)) % m;
	ll c = fastPow(a, p / 2, m);
	return  mem[p] = (c * c) % m;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vii num(n);
		for (int i = 0; i < n; i++) {
			cin >> num[i].first >> num[i].second;
			if (num[i].first > num[i].second)
				swap(num[i].first, num[i].second);
		}

		int r = 0;
		for (int i = 1; i <= n; i++) {
			map<ll, int> cnt;

			ll b = 4001, m = 1e9 + 9;
			ll hash = 0;

			for (int j = 0; j < i; j++) {
				int x = num[j].first * 4000 + num[j].second;
				hash += fastPow(b, x, m);
			}
			cnt[hash]++;

			for (int j = i; j < n; j++) {
				int x = num[j - i].first * 4000 + num[j - i].second;
				hash -= fastPow(b, x, m);

				x = num[j].first * 4000 + num[j].second;
				hash += fastPow(b, x, m);
				r += cnt[hash]++;
			}
		}

		cout << r << endl;
	}
	cin.ignore(), cin.get();
}
