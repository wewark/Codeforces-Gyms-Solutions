// 2017-2018 Northwestern European Regional Contest (NWERC 2017)
// 101623D

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


int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("in.txt", "rt", stdin);
//	freopen("out.txt", "wt", stdout);
#endif

	int n; cin >> n;
	vector<string> s;
	for (int i = 0; i < n; ++i) {
		string x; cin >> x;
		s.push_back(x);
	}

	map<string, ll> cor, incor;
	map<string, string> cort, incort;
	int m; cin >> m;
	for (int i = 0; i < m; ++i) {
		string d, e, c;
		cin >> d >> e >> c;
		if (c == "correct") {
			cor[d]++;
			cort[d] = e;
		}
		else {
			incor[d]++;
			incort[d] = e;
		}
	}

	ll num_cor = 1, tot = 1;
	bool single = true, single_cor = true;
	vector<string> sw;
	for (int i = 0; i < n; ++i) {
		num_cor *= cor[s[i]];
		tot *= (cor[s[i]] + incor[s[i]]);

		if (cor[s[i]] + incor[s[i]] > 1)
			single = false;
		if (single && cor[s[i]] == 0)
			single_cor = false;
		if (single)
			sw.push_back(cor[s[i]] ? cort[s[i]] : incort[s[i]]);
	}

	if (single) {
		for (int i = 0; i < n; ++i) {
			cout << sw[i] << " \n"[i == n - 1];
		}
		cout << (single_cor ? "correct" : "incorrect") << endl;
	}
	else {
		cout << num_cor << " correct" << endl;
		cout << tot - num_cor << " incorrect" << endl;
	}

	return 0;

}