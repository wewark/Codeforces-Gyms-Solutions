// 101341 - 2017, X Samara Regional Intercollegiate Programming Contest
// 101341B

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
const int di[] = { -1,0,1,0 };
const int dj[] = { 0,1,0,-1 };
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
#define mp make_pair

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	string s; cin >> s;
	vi h; string p = "happiness";
	if (s.length() < p.length()) {
		cout << "YES\n1 2\n";
		return 0;
	}
	for (int i = 0; i < s.length() - p.length() + 1; i++)
		if (s.substr(i, p.length()) == p)
			h.push_back(i);
	if (h.size() <= 2) {
		cout << "YES" << endl;
		if (h.size() == 0) {
			swap(s[0], s[1]);
			if (s.substr(0, p.length()) != p &&
				(s.length() == p.length() || s.length() > p.length() && s.substr(1, p.length()) != p))
				cout << "1 2\n";
			else
				cout << "2 3\n";
		}
		else if (h.size() == 1) cout << h[0] + 1 << " " << h[0] + 2 << endl;
		else cout << h[0] + 1 << " " << h[1] + 2 << endl;
	}
	else cout << "NO\n";
	//cin.ignore(), cin.get();
}
