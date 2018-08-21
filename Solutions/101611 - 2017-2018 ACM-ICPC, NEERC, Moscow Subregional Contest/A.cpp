// 101611 - 2017-2018 ACM-ICPC, NEERC, Moscow Subregional Contest
// 101611A

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
const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, 1, 0, -1 };
const ll MOD = 5e6;
const ll INF = 1e8;
const long double EPS = 1e-6;
#define mp make_pair
#define all(x) x.begin(),x.end()

ll solve(ll n, ll k, ll cur) {
	if (!k && n - cur) return INF;
	ll r = 0;
	while (cur <= n) {
		if (k >= n - cur) {
			r++; break;
		}
		cur += min(cur, (n - cur) / 2);
		r++;
	}
	return r;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	ll n, k; cin >> n >> k;
	ll cur = 1, r = 0;
	k--;
	r = solve(n, k, cur);
	while (k > 1 && cur + 1 <= (n - (cur + 1)) / 2)
		k--, cur++, r = min(r, solve(n, k, cur));
	cout << r << endl;
	cin.ignore(), cin.get();
}
