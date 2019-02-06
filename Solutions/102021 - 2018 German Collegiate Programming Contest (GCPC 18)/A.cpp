// 2018 German Collegiate Programming Contest (GCPC 18)
// 102021A

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
const int MAXN = N * N;
const int LOGN = 20;

int n, m;
string g[N];
vi adj[N * N];

inline int get(const int &x, const int &y) {
	return x * m + y;
}

int LOG2[MAXN];
int P[MAXN][LOGN];
int F[MAXN];
int L[MAXN];
bool vis[MAXN];

void init() {
	queue<int> Q;
	Q.push(0);
	vis[0] = 1;
	L[0] = 0;
	F[0] = -1;
	int lvl = 0;
	while (SZ(Q)) {
		int sz = SZ(Q);
		while (sz--) {
			int cur = Q.front();
			Q.pop();
			for (int to : adj[cur]) {
				if (!vis[to]) {
					L[to] = lvl + 1;
					F[to] = cur;
					Q.push(to);
					vis[to] = 1;
				}
			}
		}
		lvl++;
	}
	LOG2[1] = 0;
	for (int i = 2; i < MAXN; i++)
		LOG2[i] = LOG2[i / 2] + 1;
	MMS(P, -1);
	for (int i = 0; i < n; i++)
		P[i][0] = F[i];
	for (int j = 1; 1 << j < n; j++)
		for (int i = 0; i < n; i++)
			if (P[i][j - 1] != -1)
				P[i][j] = P[P[i][j - 1]][j - 1];
}

int LCA(int a, int b) {
	if (L[a] < L[b])
		swap(a, b);
	int log = LOG2[L[a]];
	for (int i = log; i >= 0; i--) {
		if (L[a] - (1 << i) >= L[b])
			a = P[a][i];
	}
	if (a == b)
		return a;
	for (int i = log; i >= 0; i--)
		if (P[a][i] != -1 && P[a][i] != P[b][i])
			a = P[a][i], b = P[b][i];
	return F[a];
}

int solve(int u, int v) {
	int l = LCA(u, v);
	if (l == u || l == v)
		return abs(L[u] - L[v]);
	return L[u] + L[v] - 2 * L[l];
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
//	freopen("in.txt", "rt", stdin);
//	freopen("out.txt", "wt", stdout);
#endif
	cin >> n >> m;
	cin.ignore();
	for (int i = 0; i <= n; i++)
		getline(cin, g[i]);
	for (int i = 0, ii = 0; ii < n; ii++, i++) {
		for (int j = 1, jj = 0; jj < m; jj++, j += 2) {
			int u = get(ii, jj);
			if (g[i][j] == ' ') { // up
				int v = get(ii - 1, jj);
				adj[u].pb(v);
				adj[v].pb(u);
			}
			if (g[i + 1][j] == ' ') { // down
				int v = get(ii + 1, jj);
				adj[u].pb(v);
				adj[v].pb(u);
			}
			if (g[i + 1][j - 1] == ' ') { // left
				int v = get(ii, jj - 1);
				adj[u].pb(v);
				adj[v].pb(u);
			}
			if (g[i + 1][j + 1] == ' ') { // right
				int v = get(ii, jj + 1);
				adj[u].pb(v);
				adj[v].pb(u);
			}
		}
	}
	n *= m;
	init();
	ll res = 0;
	int q, x, y, u, v;
	cin >> q >> x >> y;
	u = get(x - 1, y - 1);
	while (--q) {
		cin >> x >> y;
		v = get(x - 1, y - 1);
		res += solve(u, v);
		u = v;
	}
	cout << res << endl;
	return 0;
}
