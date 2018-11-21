// 2018 KAIST RUN Spring Contest
// 101806S

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

int r[5], f[5];

inline string classify(int cr, int cf) {
	if (cr <= r[1]) {
		if (cf <= f[1]) return "New Customer";
		if (cf <= f[3]) return "Potential Loyalist";
		if (cf <= f[4]) return "Loyal Customer";
		return "Champion";
	}
	if (cr <= r[2]) {
		if (cf <= f[1]) return "Promising";
		if (cf <= f[3]) return "Potential Loyalist";
		return "Loyal Customer";
	}
	if (cr <= r[3]) {
		if (cf <= f[2]) return "About to Sleep";
		if (cf <= f[3]) return "Need Attention";
		return "Loyal Customer";
	}
	if (cr <= r[4]) {
		if (cf <= f[1]) return "Lost";
		if (cf <= f[2]) return "Hibernating";
		return "About to Leave";
	}

	if (cf <= f[2]) return "Lost";
	if (cf <= f[4]) return "About to Leave";
	return "Can't Lose Them";
}

int n;
map<string, int> last, freq;

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("in.txt", "rt", stdin);
//	freopen("out.txt", "wt", stdout);
#endif

	for (int i = 1; i <= 4; ++i) {
		cin >> r[i];
	}
	for (int i = 1; i <= 4; ++i) {
		cin >> f[i];
	}
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int t; string name;
		cin >> t >> name;
		if (t == 1) {
			last[name] = i;
			freq[name]++;
		}
		else {
			if (last.find(name) == last.end())
				cout << "None" << endl;
			else
				cout << classify(i - last[name], freq[name]) << endl;
		}
	}

}
