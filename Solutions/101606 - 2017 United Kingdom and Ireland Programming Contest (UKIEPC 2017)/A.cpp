// 101606 - 2017 United Kingdom and Ireland Programming Contest (UKIEPC 2017)
// 101606A

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
const ll INF = 1e9;
const double EPS = 1e-5;
#define mp make_pair
#define all(x) x.begin(),x.end()

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int n; cin >> n;
	vector<vb> st(n);
	int day = 0;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		st[i].assign(x, 0);
		day = max(day, x);

		int a, b; cin >> a >> b;
		if (b < a) {
			for (int j = a + 1; j < x; j++)
				st[i][j] = true;
			for (int j = 0; j < b; j++)
				st[i][j] = true;
		}
		else for (int j = a + 1; j < b; j++)
			st[i][j] = true;
	}

	int idx = 0;
	bool w = false;
	while (true) {
		bool allday = true;
		for (int i = 0; i < n; i++)
			if (st[i][idx % st[i].size()]) {
				allday = false; break;
			}

		if (allday) break;
		idx++;
		if (idx / day >= 1825) {
			w = true; break;
		}
	}

	if (w) cout << "impossible\n";
	else
		cout << idx << endl;
	cin.ignore(), cin.get();
}
