// 101606 - 2017 United Kingdom and Ireland Programming Contest (UKIEPC 2017)
// 101606D

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

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	string s; cin >> s;
	string sr = s;
	sort(all(sr));

	vii r;
	int cur = 0;
	for (char c = 'a'; c <= 'z'; c++) {
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == c) {
				if (i == cur) {
					cur++; continue;
				}
				r.push_back(s[cur] > c ? pii{ i, cur } : pii{ cur, i });
				swap(s[cur], s[i]);
				cur++;
			}
		}
	}

	for (int i = r.size() - 1; i >= 0; i--)
		cout << r[i].first + 1 << " " << r[i].second + 1 << endl;
	cin.ignore(), cin.get();
}
