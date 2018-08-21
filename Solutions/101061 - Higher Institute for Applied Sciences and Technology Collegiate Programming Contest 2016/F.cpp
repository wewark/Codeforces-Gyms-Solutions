// 101061 - Higher Institute for Applied Sciences and Technology Collegiate Programming Contest 2016
// 101061F

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

int n;
vi num;

vvi mem(101, vi(20001, -1));
int solve(int idx, int diff) {
	if (idx == n) return abs(diff);
	if (mem[idx][diff + 10000] != -1) return mem[idx][diff + 10000];

	int unf = abs(diff);
	int ret = max(unf, solve(idx + 1, diff + num[idx]));
	ret = min(ret, max(unf, solve(idx + 1, diff - num[idx])));
	return mem[idx][diff + 10000] = ret;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int t; cin >> t;
	while (t--) {
		mem.assign(101, vi(20001, -1));
		cin >> n;
		num.resize(n);
		for (int i = 0; i < n; i++)
			cin >> num[i];
		cout << solve(0, 0) << endl;
	}
	cin.ignore(), cin.get();
}
