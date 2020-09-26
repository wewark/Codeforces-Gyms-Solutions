// CCPC 2016-2017 Finals
// 101206J

#include <bits/stdc++.h>

using namespace __gnu_cxx;
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using pii = pair<int, ll>;
using vii = vector<pii>;
using vb = vector<bool>;
using vs = vector<string>;
const int MOD = int(1e9 + 7);
const long double EPS = 1e-8;
const double PI = acos(-1.0);
const ll INF = ll(1e18);
int di[] = {0, 1, 0, -1};
int dj[] = {1, 0, -1, 0};
#define all(x) x.begin(),x.end()

string wor;
string school[5][20];
string ec[20];

bool advance(int x, int y) {
	set<string> vis;
	for (int i = 0; i < 20 && x; ++i) {
		for (int j = 0; j < 5 && x; ++j) {
			if (vis.find(school[j][i]) == vis.end()) {
				vis.insert(school[j][i]);
				x--;
				if (school[j][i] == wor)
					return true;
			}
		}
	}

	for (int i = 0; i < 20 && y; ++i) {
		if (vis.find(ec[i]) == vis.end()) {
			vis.insert(ec[i]);
			y--;
			if (ec[i] == wor)
				return true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int t, tt = 0; cin >> t;
	while (t--) {
		int g;
		cin >> g >> wor;
		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 20; ++j) {
				cin >> school[i][j];
			}
		}
		for (int i = 0; i < 20; ++i) {
			cin >> ec[i];
		}

		cout << "Case #" << ++tt << ": ";

		bool adv = true;
		for (int y = 0; y <= g; ++y) {
			if (!advance(g - y, y)) {
				adv = false;
				cout << y << endl;
				break;
			}
		}

		if (adv) {
			cout << "ADVANCED!" << endl;
		}
	}
}
