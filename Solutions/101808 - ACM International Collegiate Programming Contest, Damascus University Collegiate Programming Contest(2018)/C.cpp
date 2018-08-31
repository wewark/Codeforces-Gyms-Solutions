// 101808 - ACM International Collegiate Programming Contest, Damascus University Collegiate Programming Contest(2018)
// 101808C

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

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int t; cin >> t;
	while (t--) {
		string s1, s2; cin >> s1 >> s2;
		int a = 0, b = s1.length() - 1;
		int r = 0;
		bool rev = false;
		while (a < b) {
			if (!rev) {
				if (s1[a] != s2[a] || s1[b] != s2[b]) {
					swap(s1[a], s1[b]);
					if (s1[a] != s2[a] || s1[b] != s2[b]) {
						r = -1; break;
					}
					r++;
					rev = !rev;
				}
			}
			else if (s1[a] != s2[b] || s1[b] != s2[a]) {
				swap(s1[a], s1[b]);
				if (s1[a] != s2[b] || s1[b] != s2[a]) {
					r = -1; break;
				}
				r++;
				rev = !rev;
			}
			a++, b--;
		}
		if (s1[a] != s2[a]) r = -1;
		cout << r << endl;
	}
	cin.ignore(), cin.get();
}
