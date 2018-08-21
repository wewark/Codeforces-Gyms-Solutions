// 101485 - 2015-2016 Northwestern European Regional Contest (NWERC 2015)
// 101485I

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

string s;

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> s;
	int mx = (1 << s.length());

	pii x(0, mx), y(0, mx);
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '0') {
			x.second = (x.first + x.second) / 2;
			y.second = (y.first + y.second) / 2;
		}
		else if (s[i] == '1') {
			x.first = (x.first + x.second) / 2;
			y.second = (y.first + y.second) / 2;
		}
		else if (s[i] == '2') {
			x.second = (x.first + x.second) / 2;
			y.first = (y.first + y.second) / 2;
		}
		else if (s[i] == '3') {
			x.first = (x.first + x.second) / 2;
			y.first = (y.first + y.second) / 2;
		}
	}
	cout << s.length() << " " << x.first << " " << y.first << endl;
	cin.ignore(), cin.get();
}
