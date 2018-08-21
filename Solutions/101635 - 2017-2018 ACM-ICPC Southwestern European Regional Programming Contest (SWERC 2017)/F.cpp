// 101635 - 2017-2018 ACM-ICPC Southwestern European Regional Programming Contest (SWERC 2017)
// 101635F

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
#define all(x) x.begin(),x.end()

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	ll n, w;
	cin >> w >> n;
	ll area = 0;
	for (int i = 0; i < n; i++) {
		ll x, y; cin >> x >> y;
		area += x * y;
	}
	cout << area / w << endl;
	cin.ignore(), cin.get();
}
