// 101401 - 2017 PSUT Coding Marathon
// 101401B

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
const ll INF = 1e11;
const double EPS = 1e-11;
#define mp make_pair
#define all(x) x.begin(),x.end()

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	string s; cin >> s;
	int sm = 0;
	for (int i = 1; i < s.length(); ++i)
		if (s[i] == ')' && s[i - 1] == ':')
			sm++;

	int r = sm, sad = 0;
	for (int i = 1; i < s.length(); ++i) {
		if (s[i] == ')' && s[i - 1] == ':')
			sm--;

		int cur = sm;
		if (s[0] == ':' && s[i] != ':' && i < s.length() - 1 && s[i + 1] == ')')
			cur++;
		if (s[0] != ':' && s[i] == ':' && i < s.length() - 1 && s[i + 1] == ')')
			cur--;
		if (s[i] == ':' && s[i - 1] == '(')
			sad++;
		cur += sad;
		r = max(r, cur);
	}
	cout << r << endl;
}
