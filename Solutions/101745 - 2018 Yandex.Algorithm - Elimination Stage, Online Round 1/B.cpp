// 101745 - 2018 Yandex.Algorithm - Elimination Stage, Online Round 1
// 101745B

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
const long double EPS = 1e-7;
#define all(n) n.begin(),n.end()

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	string s; cin >> s;
	vvi pos(10);
	for (int i = 0; i < s.length(); i++) {
		pos[s[i] - '0'].push_back(i);
	}

	ll r = 0;
	vi p = { 0,1,2,3,4,5,6,7,8,9 };
	do {
		int cur = -1;
		bool w = false;
		for (int i = 0; i < 10; i++) {
			auto it = upper_bound(all(pos[p[i]]), cur);
			if (it == pos[p[i]].end()) {
				w = true; break;
			}
			cur = *it;
		}
		if (!w) r++;
	} while (next_permutation(all(p)));
	cout << r << endl;
	cin.ignore(), cin.get();
}
