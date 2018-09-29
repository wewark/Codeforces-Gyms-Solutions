// 2018-2019 ACM-ICPC Brazil Subregional Programming Contest
// 101908F

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
#define mp make_pair
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

const int N = 1003;

int q, n;
pair<pii, pii> a[N];
int dp[N][1 << 10];
bool vis[N][1 << 10];

int calc(int idx, int msk) {
	if (idx == n) {
		if (msk == (1 << q) - 1)
			return 0;
		return -OO;
	}
	int &ret = dp[idx][msk];
	if (vis[idx][msk])
		return ret;
	vis[idx][msk] = 1;
	ret = calc(idx + 1, msk);
	int nxt = lower_bound(a + idx + 1, a + n, mp( mp(a[idx].first.second, 0), mp(0, 0))) - a;
	ret = max(ret, calc(nxt, msk | (1 << a[idx].second.second)) + a[idx].second.first);
	return ret;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
//	freopen("in.txt", "rt", stdin);
//	freopen("out.txt", "wt", stdout);
#endif
	cin >> q;
	for (int i = 0; i < q; i++) {
		int m;
		cin >> m;
		for (int j = 0; j < m; j++) {
			cin >> a[n].first.first >> a[n].first.second >> a[n].second.first;
			a[n].second.second = i;
			n++;
		}
	}
	sort(a, a + n);
//	for (int i = 0; i < n; i++) {
//		cout << a[i].first.first << " " << a[i].first.second << " => " << a[i].second.first << " " << a[i].second.second << endl;
//	}
	int res = calc(0, 0);
	if (res < 0)
		res = -1;
	cout << res << endl;
	return 0;
}
