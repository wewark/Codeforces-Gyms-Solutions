// 101047 - 2015 USP Try-outs
// 101047B

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
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};
const ll MOD = 1e9 + 7;
const long double EPS = 1e-10;

#define all(x) x.begin(),x.end()

const int N = 1e3 + 3;

bool go(int n, int b) {
	string res;
	while (n) {
		int cur = n % b;
		res += (cur > 9) ? ('A' + cur - 10) : (cur + '0');
		n /= b;
	}
	string tmp = res;
	reverse(tmp.begin(), tmp.end());
	return res == tmp;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
//	freopen("cube.in", "r", stdin);
//	freopen("cube.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> res;
		for (int i = 2; i < 17; i++) {
			if (go(n, i))
				res.push_back(i);
		}
		if (res.empty())
			res.push_back(-1);
		n = res.size();
		for (int i = 0; i < n; i++)
			cout << res[i] << " \n"[i == n - 1];
	}


	return 0;
}