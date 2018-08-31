// 101808 - ACM International Collegiate Programming Contest, Damascus University Collegiate Programming Contest(2018)
// 101808I

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
		int n; cin >> n;
		int mn = INF, sum = 0;
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			mn = min(mn, x);
			sum += x;
		}

		if (n % 2 && sum % 2 ||
			n % 2 == 0 && (sum % 2 || mn % 2))
			cout << "Yalalov" << endl;
		else
			cout << "Shin" << endl;
	}
	cin.ignore(), cin.get();
}
