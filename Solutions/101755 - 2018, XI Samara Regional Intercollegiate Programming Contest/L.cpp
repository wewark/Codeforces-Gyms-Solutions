// 101755 - 2018, XI Samara Regional Intercollegiate Programming Contest
// 101755L

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
const int di[] = { -1, 0, 1, 0, -1, 1, 1, -1 };
const int dj[] = { 0, 1, 0, -1, -1, 1, -1, 1 };
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const long double EPS = 1e-10;
#define all(n) n.begin(),n.end()

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	string s; cin >> s;
	vvi idx(150);
	for (int i = 0; i < s.length(); i++) {
		idx[s[i]].push_back(i);
	}
	for (int i = 0; i < 150; i++) {
		sort(all(idx[i]));
	}

	vb p;
	vi last;

	int q; cin >> q;
	while (q--) {
		string op;
		cin >> op;

		bool yes = true;
		if (op == "push") {
			char c; cin >> c;

			int curlast = -1;
			if (!last.empty()) curlast = last.back();

			auto it = upper_bound(all(idx[c]), curlast);
			if (it == idx[c].end()) {
				yes = false;
				last.push_back(INF);
			}
			else
				last.push_back(*it);
			p.push_back(yes);
		}
		else {
			last.pop_back();
			p.pop_back();
			if (!p.empty()) yes = p.back();
		}

		cout << (yes ? "YES" : "NO") << endl;
	}

	cin.ignore(), cin.get();
}
