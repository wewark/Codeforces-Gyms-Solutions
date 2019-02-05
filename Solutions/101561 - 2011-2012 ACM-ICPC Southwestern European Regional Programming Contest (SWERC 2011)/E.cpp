// 2011-2012 ACM-ICPC Southwestern European Regional Programming Contest (SWERC 2011)
// 101561E

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

double dp[12][12];
int vis[12][12];
int vid;

double p, ttie, game;

double dptie[N][N];
int vistie[N][N];

double getTie(int cur, int win) {
	if (abs(win - (cur - win)) >= 2 && (win >= 7 || cur - win >= 7))
		return win > cur - win;
	if (cur == N)
		return 0;
	double &ret = dptie[cur][win];
	if (vistie[cur][win] == vid)
		return ret;
	vistie[cur][win] = vid;
	ret = getTie(cur + 1, win + 1) * p;
	ret += getTie(cur + 1, win) * (1 - p);
	return ret;
}

double dpgame[N][N];
int visgame[N][N];

double getGame(int cur, int win) {
	if (abs(win - (cur - win)) >= 2 && (win >= 4 || cur - win >= 4))
		return win > cur - win;
	if (cur == N)
		return 0;
	double &ret = dpgame[cur][win];
	if (visgame[cur][win] == vid)
		return ret;
	visgame[cur][win] = vid;
	ret = getGame(cur + 1, win + 1) * p;
	ret += getGame(cur + 1, win) * (1 - p);
	return ret;
}

double getMatch(double set) {
	return set * (set + (1 - set) * set) + (1 - set) * set * set;
}

double calc(int cur, int win) {
	if (abs(win - (cur - win)) >= 2 && (win >= 6 || cur - win >= 6))
		return win > cur - win;
	if (cur == 12 && win == 6)
		return ttie;
	if (cur >= 12)
		assert(0);
	double &ret = dp[cur][win];
	if (vis[cur][win] == vid)
		return ret;
	vis[cur][win] = vid;
	ret = calc(cur + 1, win + 1) * game;
	ret += calc(cur + 1, win) * (1 - game);
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
	cout << fixed << setprecision(10);
	while (cin >> p && p != -1) {
		vid++;
		ttie = getTie(0, 0);
		game = getGame(0, 0);
		double set = calc(0, 0);
		double match = getMatch(set);
		cout << game << " " << set << " " << match << "\n";
	}
	return 0;
}
