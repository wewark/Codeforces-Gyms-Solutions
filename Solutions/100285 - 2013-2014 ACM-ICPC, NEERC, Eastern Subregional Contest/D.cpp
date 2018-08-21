// 100285 - 2013-2014 ACM-ICPC, NEERC, Eastern Subregional Contest
// 100285D

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<ll, ll> pii;
typedef vector<pii> vii;
typedef vector<bool> vb;
typedef vector<string> vs;
const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, 1, 0, -1 };
const ll MOD = 5e6;
const ll INF = 1e8;
const long double EPS = 1e-6;
#define mp make_pair
#define all(x) x.begin(),x.end()

inline string tolowerStr(string s) {
	s[0] = tolower(s[0]);
	return s;
}

void solve(string s, bool first = false) {
	int a = s.find('{') + 1;
	int b = s.find('}');
	string tmp = s.substr(a, b - a);
	if (first) tmp[0] = toupper(tmp[0]);
	cout << tmp << " ";
	a = s.find('(') + 1;
	b = s.find(')');
	cout << tolowerStr(s.substr(a, b - a)) << " ";
	a = s.find('[') + 1;
	b = s.find(']');
	cout << tolowerStr(s.substr(a, b - a));
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	string s; getline(cin, s);
	if (s.find(',') != string::npos) {
		solve(s.substr(0, s.find(',')), true);
		s = s.substr(s.find(','));
		cout << s.substr(0, min(s.find('{'), min(s.find('('), s.find('['))));
		solve(s.substr(s.find(',') + 1));
	}
	else solve(s, true);
	//cin.ignore(), cin.get();
}
