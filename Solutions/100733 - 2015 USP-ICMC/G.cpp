// 100733 - 2015 USP-ICMC
// 100733G

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<pair<int, int>, int> pii;
typedef vector<pii> vii;
typedef vector<bool> vb;
typedef vector<string> vs;
const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, 1, 0, -1 };
const ll MOD = 1e9 + 7;
const ll INF = 1e10;
const double EPS = 1e-5;
#define mp make_pair
#define all(x) x.begin(),x.end()

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	string s; cin >> s;
	bool ng = false;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ')' || s[i] == '(') continue;
		if (s[i] == '[')
			ng = !ng, s[i] = '(';
		else if (s[i] == ']')
			ng = !ng, s[i] = ')';
		else if (ng) {
			if (isalpha(s[i])) {
				if (islower(s[i])) s[i] = toupper(s[i]);
				else s[i] = tolower(s[i]);
			}
			else if (s[i] == '+') s[i] = '*';
			else s[i] = '+';
		}
	}
	cout << s << endl;
	cin.ignore(), cin.get();
}
