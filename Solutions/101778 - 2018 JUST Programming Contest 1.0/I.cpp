// 101778 - 2018 JUST Programming Contest 1.0
// 101778I

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<double, int> pii;
typedef vector<pii> vii;
typedef vector<bool> vb;
typedef vector<string> vs;
const int di[] = { 0, 1 };
const int dj[] = { 1, 0 };
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const long double EPS = 1e-7;
#define all(n) n.begin(),n.end()

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		int r = -10;
		if (a + c == b + d) {
			if (c == b) r = -1;
			else if (c > d) r = 1;
			else r = 2;
		}
		else if (a + c > b + d) r = 1;
		else r = 2;
		cout << r << endl;
	}
	cin.ignore(), cin.get();
}
