// 2017-2018 CTU Open Contest
// 101670E

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

const int N = 105;

int n, m;
char a[N][N];

inline bool ok(int x, int y) {
	return x >= 1 && x <= n && y >= 1 && y <= n;
}

inline void stumpRoot(int x, int y) {
	if (ok(x, y)) {
		a[x][y] = 'o';
	}
}

inline void stumpSide(int x, int y) {
	if (ok(x, y)) {
		a[x][y] = '_';
	}
}

inline void stump(int x, int y) {
	stumpRoot(x, y);
	stumpSide(x - 1, y);
	stumpSide(x + 1, y);
}

inline void treeRootMid(int x, int y) {
	if (ok(x, y)) {
		a[x][y] = '|';
	}
}

inline void treeRootSide(int x, int y) {
	if (ok(x, y)) {
		a[x][y] = '_';
	}
}

inline void treeRoot(int x, int y) {
	treeRootMid(x, y);
	treeRootSide(x + 1, y);
	treeRootSide(x - 1, y);
}

inline void treeTop(int x, int y) {
	if (ok(x, y)) {
		a[x][y] = '^';
	}
}

inline void branchMid(int x, int y) {
	if (ok(x, y)) {
		a[x][y] = '|';
	}
}

inline void branchRight(int x, int y) {
	if (ok(x, y)) {
		a[x][y] = '\\';
	}
}

inline void branchLeft(int x, int y) {
	if (ok(x, y)) {
		a[x][y] = '/';
	}
}

inline void branch(int x, int y) {
	branchMid(x, y);
	branchRight(x + 1, y);
	branchLeft(x - 1, y);
}

inline void tree(int x, int y, int s) {
	treeRoot(x, y);
	treeTop(x, y + s + 1);
	for (int i = max(y + 1, 1); i <= min(y + s, n); i++)
		branch(x, i);
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("in.txt", "rt", stdin);
//	freopen("out.txt", "wt", stdout);
#endif
	while (cin >> n >> m) {
		MMS(a, '.');
		for (int i = 0; i <= n + 1; i++)
			a[i][0] = a[0][i] = a[i][n + 1] = a[n + 1][i] = '*';
		for (int i = 0; i < m; i++) {
			int s, x, y;
			cin >> s >> x >> y;
			x++, y++;
			if (s == 0) {
				stump(x, y);
			} else {
				tree(x, y, s);
			}
		}
		for (int j = n + 1; j >= 0; j--) {
			for (int i = 0; i <= n + 1; i++)
				putchar(a[i][j]);
			puts("");
		}
		puts("");
	}
	return 0;
}
