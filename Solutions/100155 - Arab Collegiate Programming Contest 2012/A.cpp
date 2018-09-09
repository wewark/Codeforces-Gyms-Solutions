// Arab Collegiate Programming Contest 2012
// 100155A

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
const int di[] = { 0, 0, 1, -1 };
const int dj[] = { 1, -1, 0, 0 };
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const long double EPS = 1e-6;
#define all(x) x.begin(),x.end()

vi votes;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int c, v; cin >> c >> v;
		vvi pref(v, vi(c));
		for (int i = 0; i < v; i++) {
			for (int j = 0; j < c; j++) {
				cin >> pref[i][j];
				pref[i][j]--;
			}
		}

		if (c == 1) {
			cout << pref[0][0] << endl;
			continue;
		}

		votes.assign(c, 0);
		for (int i = 0; i < v; i++) {
			votes[pref[i][0]]++;
		};
		vi vc(c);
		iota(all(vc), 0);
		sort(all(vc), [](int a, int b) {
			return votes[a] > votes[b];
		});

		if (votes[vc[0]] != votes[vc[1]]) {
			cout << vc[0] + 1 << " 1" << endl;
			continue;
		}

		int a = 0, b = 0;
		for (int i = 0; i < v; i++) {
			for (int j = 0; j < c; j++) {
				if (pref[i][j] == vc[0]) {
					a++; break;
				}
				if (pref[i][j] == vc[1]) {
					b++; break;
				}
			}
		}

		if (a > b) cout << vc[0] + 1;
		else cout << vc[1] + 1;
		cout << " 2" << endl;
	}
}
