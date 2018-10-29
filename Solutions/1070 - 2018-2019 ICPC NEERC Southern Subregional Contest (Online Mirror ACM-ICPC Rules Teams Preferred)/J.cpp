// 2018-2019 ICPC NEERC Southern Subregional Contest (Online Mirror ACM-ICPC Rules Teams Preferred)
// 1070J

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
const ll MOD = 1e9 + 7;
const long double EPS = 1e-5;
#define all(x) x.begin(),x.end()
#define SZ(x) (int)(x).size()

#include <ext/hash_set>
#include <ext/numeric>

const int INF = 1e9;
const int N = 3e4 + 4;
const int SL = 2e5 + 5;
const int R = 27;
int dp[N][R][R];
int vis[N][R][R], visid;
int freq[R];
char str[SL];
int n, m, k;

int solve(int idx, int L, int forb) {
	if (L < 0)return N;
	if (idx == R)return L;
	int &ret = dp[L][idx][forb];
	if (vis[L][idx][forb] == visid)return ret;
	vis[L][idx][forb] = visid;
	ret = solve(idx + 1, L, forb);
	if (idx == forb)return ret;
	ret = min(ret, solve(idx + 1, L - freq[idx], forb));
	return ret;
}


bool memo[SL][R];
int vis2[SL][R];

bool go(int sum , int idx){
	if(idx == R){
		return sum >= n && (k - sum) >= m;
	}

	bool &ret = memo[sum][idx];
	if(vis2[sum][idx] == visid)return ret;
	vis2[sum][idx] = visid;
	ret = go(sum , idx+1);
	if (ret)
		return ret;
	ret |= go(sum + freq[idx],idx+1);
	return ret;
}


int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int t;
	scanf("%d", &t);
	while (t--) {
		visid++;

		scanf("%d%d%d%s", &n, &m, &k, str);
		memset(freq, 0, sizeof freq);
		for (int i = 0; i < k; i++)
			freq[str[i] - 'A']++;

		int ans = INF;
		for (int jj = 0; jj < 2; jj++) {
			for (int i = 0; i < R; i++) if(freq[i]){
					int x = solve(0, n, i);
					if(freq[i] < x)continue;
					int rem = k - freq[i] - (n-x);
					int leftInM = max(m - rem, 0);
					ans = min(ans, leftInM * x);
				}
			swap(n, m);
		}

		if(go(0,0)){
			ans = 0;
		}


		printf("%d\n",ans);
	}


	return 0;
}