// 101778 - 2018 JUST Programming Contest 1.0
// 101778H

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
		int n, m; cin >> n >> m;
		string s; cin >> s;
		int w = 0;
		for (int i = 0; i < s.length() / 2; i++) {
			if (s[i] != s[s.length() - 1 - i])
				w++;
		}

		int r = 0;
		while (m--) {
			int p; char c;
			cin >> p >> c; p--;

			if (!(s.length() % 2 && p == s.length() / 2) &&
				s[p] == s[s.length() - 1 - p] && c != s[p])
				w++;
			if (!(s.length() % 2 && p == s.length() / 2) &&
				c == s[s.length() - 1 - p] && c != s[p])
				w--;

			s[p] = c;
			r += w == 0;
		}
		cout << r << endl;
	}
	cin.ignore(), cin.get();
}
