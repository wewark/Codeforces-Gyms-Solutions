// 101726 - 2013 USP Try-outs
// 101726H

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
const int di[] = { -1, 0, 1, 0, -1, 1, 1, -1 };
const int dj[] = { 0, 1, 0, -1, -1, 1, -1, 1 };
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const long double EPS = 1e-9;
#define all(x) x.begin(),x.end()

string sorobov(char d) {
	string ret = "00-11111";
	if (d >= '5') ret[1] = '1', d -= 5;
	else ret[0] = '1';
	ret[3 + d - '0'] = '0';
	return ret;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		reverse(all(s));
		vs g(9);
		for (int i = 0; i < s.length(); i++) {
			g[i] = sorobov(s[i]);
		}
		for (int i = s.length(); i < 9; i++) {
			g[i] = sorobov('0');
		}

		vs r(g[0].size(), string(g.size(), '0'));
		reverse(all(g));
		for (int i = 0; i < g.size(); i++) {
			for (int j = 0; j < g[i].size(); j++) {
				r[j][i] = g[i][j];
			}
		}

		for (int i = 0; i < r.size(); i++) {
			cout << r[i] << endl;
		}
		cout << endl;
	}
	cin.ignore(), cin.get();
}
