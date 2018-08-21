// 101201 - 2016-2017 ACM-ICPC Pacific Northwest Regional Contest (Div. 1)
// 101201A

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

string s;

vvi mem(100, vi('z' + 1, -1));
int solve(int idx, char nxt) {
	if (nxt > 'z') return 0;
	if (idx >= s.length()) return 'z' - nxt + 1;
	if (mem[idx][nxt] != -1) return mem[idx][nxt];

	int ret = 1000;
	if (s[idx] == nxt)
		ret = solve(idx + 1, nxt + 1);
	else {
		ret = solve(idx + 1, nxt);
		ret = min(ret, solve(idx, nxt + 1) + 1);
	}
	return mem[idx][nxt] = ret;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> s;
	cout << solve(0, 'a') << endl;
	cin.ignore(), cin.get();
}
