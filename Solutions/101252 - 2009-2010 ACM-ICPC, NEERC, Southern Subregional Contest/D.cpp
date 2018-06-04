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
const int di[] = { -1, 0, 1, 0, -1, 1, 1, -1 };
const int dj[] = { 0, 1, 0, -1, -1, 1, -1, 1 };
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const long double EPS = 1e-7;
#define all(x) x.begin(),x.end()

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	ll a, b, c; cin >> a >> b >> c;
	ll last = 1;
	for (int i = 0; i < 2e7; i++) {
		last = (a * last + last % b) % c;
	}

	bool have = false;
	ll x = 1, d = -1, start = -1;
	for (int i = 0; i <= 2e7; i++) {
		if (x == last) {
			if (have) {
				d = i - start;
				break;
			}
			start = i;
			have = true;
		}
		x = (a * x + x % b) % c;
	}

	if (!(have && ~d)) {
		cout << -1 << endl; return 0;
	}

	ll x1 = 1, x2 = 1;
	for (int i = 0; i < d; i++) {
		x2 = (a * x2 + x2 % b) % c;
	}
	for (int i = 0; i < 2e7; i++) {
		if (x1 == x2) {
			cout << i + d << endl;
			cin.ignore(), cin.get();
			return 0;
		}
		x1 = (a * x1 + x1 % b) % c;
		x2 = (a * x2 + x2 % b) % c;
	}
	cin.ignore(), cin.get();
}
