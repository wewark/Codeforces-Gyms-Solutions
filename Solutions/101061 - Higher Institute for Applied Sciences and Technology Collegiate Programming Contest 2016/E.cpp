// 101061 - Higher Institute for Applied Sciences and Technology Collegiate Programming Contest 2016
// 101061E

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<ll, ll> pii;
typedef vector<pii> vii;
typedef vector<bool> vb;
typedef vector<string> vs;
const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, 1, 0, -1 };
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const double EPS = 1e-11;
#define mp make_pair
#define all(x) x.begin(),x.end()

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		int n; cin >> n;

		deque<char> st;
		int c = 0;
		for (int i = 0; i < s.length(); ++i) {
			while (!st.empty() && st.back() > s[i] && c < n)
				st.pop_back(), c++;
			st.push_back(s[i]);
		}
		while (c < n)
			st.pop_back(), c++;
		while (!st.empty())
			cout << st.front(), st.pop_front();
		cout << endl;

		c = 0;
		for (int i = 0; i < s.length(); ++i) {
			while (!st.empty() && st.back() < s[i] && c < n)
				st.pop_back(), c++;
			st.push_back(s[i]);
		}
		while (c < n)
			st.pop_back(), c++;
		while (!st.empty())
			cout << st.front(), st.pop_front();
		cout << endl;
	}
}
