// 100738 - KTU Programming Camp (Day 2)
// 100738B

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
	ll cur; cin >> cur;
	int r = 0;
	if (cur <= 4) {
		cout << -1 << endl; return 0;
	}
	while (cur < 1e9) {
		cur = (cur / 2) * (cur - cur / 2);
		r++;
	}
	cout << max(1, r) << endl;
	cin.ignore(), cin.get();
}