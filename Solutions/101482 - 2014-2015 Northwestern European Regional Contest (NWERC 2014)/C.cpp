// 2014-2015 Northwestern European Regional Contest (NWERC 2014)
// 101482C

#include <bits/stdc++.h>
using namespace std;

const int N = 2005;
const int INF = 1e8;
int arr[N];
int dp[N][25][12];
int n, d;

int f(int x) {
	if (x > 4)
		return 10;
	return 0;
}

int solve(int idx, int g, int mod) {
	if (g >= d)
		return INF;
	if (idx == n)
		return f(mod);
	int &ret = dp[idx][g][mod];
	if (~ret)
		return ret;
	ret = INF;
	int sum = arr[idx] + mod;
	ret = min(ret, solve(idx + 1, g, sum % 10) + (sum / 10) * 10);
	ret = min(ret, solve(idx, g + 1, 0) + f(mod));
	return ret;
}

int main() {
	scanf("%d %d", &n, &d);
	d++;
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	memset(dp, -1, sizeof dp);
	printf("%d\n", solve(0, 0, 0));
	return 0;
}
