// 101801 - Tishreen-CPC 2018
// 101801B

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
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

unordered_map<int, int> cnt;

void primeFactorize(int n) {
	if (n % 2 == 0) cnt[2]++;
	while (n % 2 == 0) n /= 2;

	for (int i = 3; i * i <= n; i += 2) {
		if (n % i == 0) cnt[i]++;
		while (n % i == 0) n /= i;
	}
	if (n > 2) cnt[n]++;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vi num(n);
		cnt.clear();
		for (int i = 0; i < n; i++) {
			cin >> num[i];
			primeFactorize(num[i]);
		}

		ll r = 0;
		for (auto& i : cnt) {
			r += (i.second + 2) / 3;
		}
		cout << r << endl;
	}
	cin.ignore(), cin.get();
}
