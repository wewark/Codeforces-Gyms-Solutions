// 101201 - 2016-2017 ACM-ICPC Pacific Northwest Regional Contest (Div. 1)
// 101201H

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
const ll INF = 1e10;
const double EPS = 1e-10;
#define mp make_pair
#define all(x) x.begin(),x.end()

ll n, k;
vector<pair<ll, ll>> art;
vll a, b;

vll mem(200005, -1);
ll solve(int idx) {
	if (idx >= k) return 0;
	if (mem[idx] != -1) return mem[idx];

	ll ret = solve(idx + 1);

	auto it = upper_bound(all(a), b[idx]);
	if (it != a.end())
		ret = max(ret, solve(it - a.begin()) + b[idx] - a[idx] + 1);
	else
		ret = max(ret, b[idx] - a[idx] + 1);
	return mem[idx] = ret;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> k;
	art.resize(k);
	for (int i = 0; i < k; i++)
		cin >> art[i].first >> art[i].second;
	sort(all(art));

	a.resize(k), b = a;
	for (int i = 0; i < k; i++)
		a[i] = art[i].first, b[i] = art[i].second;

	cout << n - solve(0) << endl;
	cin.ignore(), cin.get();
}
