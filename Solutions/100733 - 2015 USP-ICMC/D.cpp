// 100733 - 2015 USP-ICMC
// 100733D

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<pair<int, int>, int> pii;
typedef vector<pii> vii;
typedef vector<bool> vb;
typedef vector<string> vs;
const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, 1, 0, -1 };
const ll MOD = 1e9 + 7;
const ll INF = 1e10;
const double EPS = 1e-5;
#define mp make_pair
#define all(x) x.begin(),x.end()

int n;
vi num;

vi mem(1e6 + 1, -1);
int solve(int idx) {
	if (idx >= n) return 0;
	if (mem[idx] != -1) return mem[idx];
	int ret = solve(idx + 1);
	ret = max(ret, solve(idx + 3) + num[idx]);
	return mem[idx] = ret;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n;
	num.resize(n);
	for (int i = 0; i < n; i++)
		cin >> num[i];
	cout << solve(0) << endl;
	cin.ignore(), cin.get();
}
