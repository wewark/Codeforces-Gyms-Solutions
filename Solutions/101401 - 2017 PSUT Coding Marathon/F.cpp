// 101401 - 2017 PSUT Coding Marathon
// 101401F

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

string s;

int cuts(string n) {
	if (s.length() < n.length()) return -1;
	if (s == n) return 0;

	if (s.substr(0, n.length()) == n ||
		s.substr(s.length() - n.length()) == n)
		return 1;

	for (int i = 0; i < s.length() - n.length(); ++i)
		if (s.substr(i, n.length()) == n)
			return 2;
	return -1;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> s;

	int r = INT_MAX;
	string perm = "BGR";
	do {
		if (cuts(perm) != -1)
			r = min(r, cuts(perm));
		if (cuts(perm.substr(0, 2)) != -1 && cuts(perm.substr(2)) != -1) {
			r = min(r, cuts(perm.substr(0, 2)) + cuts(perm.substr(2)));
		}
		if (cuts(perm.substr(0, 1) + perm.substr(2)) != -1 && cuts(perm.substr(1, 1)) != -1) {
			r = min(r, cuts(perm.substr(0, 1) + perm.substr(2)) + cuts(perm.substr(1, 1)));
		}
		if (cuts(perm.substr(0, 1)) != -1 && cuts(perm.substr(1)) != -1) {
			r = min(r, cuts(perm.substr(0, 1)) + cuts(perm.substr(1)));
		}
		if (cuts(perm.substr(0, 1)) != -1 &&
			cuts(perm.substr(1, 1)) != -1 &&
			cuts(perm.substr(2, 1)) != -1) {
			r = min(r, cuts(perm.substr(0, 1)) +
					cuts(perm.substr(1, 1)) +
					cuts(perm.substr(2, 1)));
		}
	} while (next_permutation(perm.begin(), perm.end()));
	cout << r << endl;
}
