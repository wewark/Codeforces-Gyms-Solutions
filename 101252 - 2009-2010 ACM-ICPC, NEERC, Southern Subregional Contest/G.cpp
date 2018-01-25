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
const long double EPS = 1e-10;
#define all(x) x.begin(),x.end()

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		if (s.back() == 'x' || s.back() == 's' || s.back() == 'o' ||
			s.back() == 'h' && s.length() > 1 && s[s.length() - 2] == 'c') {
			s += "es";
		}
		else if (s.back() == 'f') {
			s.back() = 'v';
			s += "es";
		}
		else if (s.back() == 'e' && s.length() > 1 && s[s.length() - 2] == 'f') {
			s[s.length() - 2] = 'v';
			s += "s";
		}
		else if (s.back() == 'y') {
			s.back() = 'i';
			s += "es";
		}
		else s += "s";
		cout << s << endl;
	}
	cin.ignore(), cin.get();
}
