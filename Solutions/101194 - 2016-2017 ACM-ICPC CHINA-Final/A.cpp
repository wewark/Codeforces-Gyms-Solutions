// 2016-2017 ACM-ICPC CHINA-Final
// 101194A

#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<bool> vb;
typedef vector<string> vs;
const ll MOD = 1e9 + 7;
const long double EPS = 1e-5;
#define all(x) x.begin(),x.end()
#define SZ(x) (int)(x).size()

#include <ext/hash_set>
#include <ext/numeric>

#define  fr first
#define  sc second

const int N = 1e5 + 5;
int dp[N];
int arr[N];
int n;


int main() {
//	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int t , cases = 1;
	arr[0] = 1;
	for (int i = 1; i < N; i++) {
		arr[i] = (arr[i - 1] << 1) % 7;
		int x = arr[i];
		x--;
		x += 7;
		x %= 7;
		dp[i] = dp[i - 1] + (x == 0);
	}

	scanf("%d", &t);
	while (t--) {
		scanf("%d",&n);
		printf("Case #%d: %d\n",cases++,dp[n]);
	}
	return 0;
}