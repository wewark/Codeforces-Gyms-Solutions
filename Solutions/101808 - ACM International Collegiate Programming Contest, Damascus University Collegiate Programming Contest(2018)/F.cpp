// 101808 - ACM International Collegiate Programming Contest, Damascus University Collegiate Programming Contest(2018)
// 101808F

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
const ll MOD = 7901;
const ll INF = 1e9;
const long double EPS = 1e-6;
#define all(x) x.begin(),x.end()

vi fact(1005);
void initFact() {
	fact[0] = 1;
	for (int i = 1; i < 1005; i++) {
		fact[i] = (fact[i - 1] * i) % MOD;
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	initFact();
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vi cnt(1005);
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			cnt[x]++;
		}

		int r = 1;
		for (int i = 0; i < cnt.size(); i++) {
			r = (r * fact[cnt[i]]) % MOD;
		}
		cout << r << endl;
	}
	cin.ignore(), cin.get();
}
