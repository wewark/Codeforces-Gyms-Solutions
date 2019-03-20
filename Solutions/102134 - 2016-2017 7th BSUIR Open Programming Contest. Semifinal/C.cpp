// 2016-2017 7th BSUIR Open Programming Contest. Semifinal
// 102134C

#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace std;
//using namespace  __gnu_pbds;

#define SZ(x) (int)x.size()

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int N = 1005;
int n, k;
string s;
int tenPow[N];

int mem[N][N][2];
bool solve(int idx, int md, bool first) {
	if (idx == n) return md == 0;

	int& ret = mem[idx][md][first];
	if (~ret) return ret;
	ret = false;
	
	if (s[idx] == '?') {
		for(int i = first; i < 10; i++) {
			if (solve(idx + 1, (md + i * tenPow[n - 1 - idx]) % k, false))
				return ret = true;
		}
		return ret = false;
	}
	if (first && s[idx] == '0')
		return ret = false;
	return ret = solve(idx + 1, (md + int(s[idx] - '0') * tenPow[n - 1 - idx]) % k, false);
}


void build(int idx, int md, bool first) {
	if (idx == n) return;

	if (s[idx] == '?') {
		for(int i = first; i < 10; i++) {
			if (solve(idx + 1, (md + i * tenPow[n - 1 - idx]) % k, false)) {
				s[idx] = '0' + i;
				build(idx + 1, (md + i * tenPow[n - 1 - idx]) % k, false);
				return;
			}
		}
		return;
	}
	build(idx + 1, (md + int(s[idx] - '0') * tenPow[n - 1 - idx]) % k, false);
}


int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	memset(mem, -1, sizeof(mem));
	cin >> n >> k >> s;
	tenPow[0] = 1 % k;
	for(int i = 1; i < n + 3; i++) {
		tenPow[i] = (tenPow[i - 1] * 10) % k;
	}

	if (solve(0, 0, n > 1)) {
		build(0, 0, n > 1);
		cout << s << endl;
	} else {
		cout << -1 << endl;
	}

	return 0;
}
