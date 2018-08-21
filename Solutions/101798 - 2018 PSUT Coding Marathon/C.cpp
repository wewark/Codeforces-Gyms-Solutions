// 101798 - 2018 PSUT Coding Marathon
// 101798C

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
const int di[] = { 0, 1 };
const int dj[] = { 1, 0 };
const ll MOD = 1e9 + 9;
const ll INF = 1e9;
const long double EPS = 1e-7;
#define all(n) n.begin(),n.end()

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int n; cin >> n;
	int r = 1, mx;
	cin >> mx;
	
	for (int i = 1; i < n; i++) {
		int x; cin >> x;
		if (x > mx) r++, mx = x;
	}

	cout << r << endl;
	cin.ignore(), cin.get();
}
