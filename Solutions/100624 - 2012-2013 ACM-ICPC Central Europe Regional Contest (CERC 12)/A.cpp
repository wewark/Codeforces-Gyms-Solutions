// 2012-2013 ACM-ICPC Central Europe Regional Contest (CERC 12)
// 100624A

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

const int MSK = 10 + (1 << 20);
const int N = 21;
vi adj[MSK];
int dp[MSK], visid;
int arr[N][N];
bool one[MSK];

int OFF(int msk, int i) {
	i = (1 << i);
	return msk & (~i);
}

void solve(int msk) {
	if (dp[msk] == visid)return;
	dp[msk] = visid;
	if (one[msk])return;
	for (int idx : adj[msk]) {
		int sum = 0;
		for (int i : adj[msk])sum += arr[idx][i];
		if (sum > 0){
			solve(OFF(msk, idx));
		}
	}
}


int main() {
//	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	for (int msk = 0; msk < MSK; msk++) {
		for (int i = 0; i < N; i++) {
			if (msk & (1 << i)) {
				adj[msk].push_back(i);
			}
		}
		if (adj[msk].size() == 1)one[msk] = true;
	}

	int t, n;
	scanf("%d", &t);
	vi ans;
	while (t--) {
		ans.clear();
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &arr[i][j]);
			}
		}

		visid++;
		solve((1 << n) - 1);
		for (int i = 0; i < n; i++)
			if (dp[(1 << i)] == visid)ans.push_back(i+1);

		for (int i = 0; i < ans.size(); i++) {
			printf("%d%c", ans[i], " \n"[i == ans.size() - 1]);
		}

		if(ans.size() == 0){
			printf("0\n");
		}

	}
	return 0;
}
