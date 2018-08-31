// 101808 - ACM International Collegiate Programming Contest, Damascus University Collegiate Programming Contest(2018)
// 101808J

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
const ll MOD = 7901;
const ll INF = 1e9;
const long double EPS = 1e-6;
#define all(x) x.begin(),x.end()

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int l[2], r[2], p[2], d[2];
		for (int i = 0; i < 2; i++) {
			cin >> l[i] >> r[i] >> p[i] >> d[i];
		}
		int k; cin >> k;

		int rs = 0;
		for (int i = 0; i < k; i++) {
			for (int j = 0; j < 2; j++) {
				if (d[j] == 0) {
					if (p[j] == l[j]) d[j] = 1, p[j]++;
					else p[j]--;
				}
				else {
					if (p[j] == r[j]) d[j] = 0, p[j]--;
					else p[j]++;
				}
			}

			if (p[0] == p[1]) rs++;
		}
		cout << rs << endl;
	}
	cin.ignore(), cin.get();
}
