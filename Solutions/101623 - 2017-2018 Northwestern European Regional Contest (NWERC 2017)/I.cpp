// 2017-2018 Northwestern European Regional Contest (NWERC 2017)
// 101623I

#include <bits/stdc++.h>
#include <ext/hash_map>
#include <ext/numeric>

using namespace std;
using namespace __gnu_cxx;

#define REP(i,n) for( (i)=0 ; (i)<(n) ; (i)++ )
#define rep(i,x,n) for( (i)=(x) ; (i)<(n) ; (i)++ )
#define REV(i,n) for( (i)=(n) ; (i)>=0 ; (i)-- )
#define FORIT(it,x) for( (it)=(x).begin() ; (it)!=(x).end() ; (it)++ )
#define foreach(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define rforeach(it,c) for(__typeof((c).rbegin()) it=(c).rbegin();it!=(c).rend();++it)
#define foreach2d(i, j, v) foreach(i,v) foreach(j,*i)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define SZ(x) ((int)(x).size())
#define MMS(x,n) memset(x,n,sizeof(x))
#define mms(x,n,s) memset(x,n,sizeof(x)*s)
#define pb push_back
#define NX next_permutation
#define UN(x) sort(all(x)),x.erase(unique(all(x)),x.end())
#define CV(x,n) count(all(x),(n))
#define FIND(x,n) find(all(x),(n))-(x).begin()
#define ACC(x) accumulate(all(x),0)
#define PPC(x) __builtin_popcountll(x)
#define LZ(x) __builtin_clz(x)
#define TZ(x) __builtin_ctz(x)
#define mxe(x) *max_element(all(x))
#define mne(x) *min_element(all(x))
#define low(x,i) lower_bound(all(x),i)
#define upp(x,i) upper_bound(all(x),i)
#define NXPOW2(x) (1ll << ((int)log2(x)+1))
#define PR(x) cout << #x << " = " << (x) << endl ;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef pair<int, int> pii;

const int OO = (int) 2e9;
const double eps = 1e-9;

typedef pair<ll, ll> pll;

#define fr first
#define sc second

const int N = 502;
const int C = 1e4 + 2;
int dp[N][C];
int vis[N][C], visid;
vi ans[2];
pair<pii, int> arr[N];
int n, c;

int solve(int idx, int memory) {
	if (memory < 0)
		return -N;
	if (idx == n)
		return 0;
	int &ret = dp[idx][memory];
	if (vis[idx][memory] == visid)
		return ret;
	vis[idx][memory] = visid;
	ret = solve(idx + 1, memory);
	if (memory >= max(arr[idx].fr.fr, arr[idx].fr.sc))
		ret = max(ret, solve(idx + 1, memory - arr[idx].fr.sc) + 1);
	return ret;
}

void build(int idx, int memory, int K) {
	if (idx == n)
		return;

	int &ret = dp[idx][memory];
	if (ret == solve(idx + 1, memory)) {
		build(idx + 1, memory, K);
	} else {
		ans[K].push_back(arr[idx].sc);
		build(idx + 1, memory - arr[idx].fr.sc, K);
	}

}

int f(const pair<pii, int> a, const pair<pii, int> b){
	int init = max(a.fr.fr , a.fr.sc);
	int tmp = init - a.fr.sc;
	if(tmp >= max(b.fr.fr , b.fr.sc))return init;
	return init + max(b.fr.fr , b.fr.sc) - tmp;
}

bool cmp(const pair<pii, int> a, const pair<pii, int> b) {
	return f(a,b) < f(b,a);
}

bool cmp1(const pair<pii, int> a, const pair<pii, int> b) {
	if (max(a.fr.fr, a.fr.sc) != max(b.fr.fr, b.fr.sc))
		return max(a.fr.fr, a.fr.sc) > max(b.fr.fr, b.fr.sc);
	return a.fr.sc < b.fr.sc;
}

int main() {
//	std::ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("in.txt", "rt", stdin);
//	freopen("out.txt", "wt", stdout);
#endif

	scanf("%d%d", &n, &c);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &arr[i].fr.fr, &arr[i].fr.sc);
		arr[i].sc = i;
	}

	sort(arr, arr + n, cmp);
	visid++;
	solve(0, c);
	build(0, c, 0);

	sort(arr, arr + n, cmp1);
	visid++;
	solve(0, c);
	build(0, c, 1);

	int idx = 1;
	if (SZ(ans[0]) > SZ(ans[1]))
		idx = 0;
	printf("%d\n", SZ(ans[idx]));

	if (SZ(ans[idx])) {
		for (int i : ans[idx]) {
			printf("%d ", i+1);
		}
		printf("\n");
	}

	return 0;

}