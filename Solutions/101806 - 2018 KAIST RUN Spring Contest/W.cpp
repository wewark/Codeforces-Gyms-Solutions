// 2018 KAIST RUN Spring Contest
// 101806W

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

typedef pair<int, int> ii;
const int n_ = 1e6 + 6;
char str[n_];
int rnk[n_], suf[n_], newRnk[n_], LCP[n_], head[300], nxt[n_];
int rnkStrt[n_], newSuf[n_];

struct cmp {
	int len;
	bool operator()(int a, int b) const {
		return rnk[a] < rnk[b] || (rnk[a] == rnk[b] && rnk[a + len] < rnk[b + len]);
	}
};

int buildSuffArray() {
	int len = 0;
	memset(head, -1, sizeof(head));
	for (; !len || str[len - 1]; len++) {
		nxt[len] = head[str[len]];
		head[str[len]] = len;
	}

	int ng = 0, ns = 0;
	for (int i = 0; i < 300; ++i) {
		if (head[i] == -1) continue;
		rnkStrt[ng] = ns;
		for (int j = head[i]; j != -1; j = nxt[j]) {
			suf[ns++] = j;
			rnk[j] = ng;
		}
		ng++;
	}

	newRnk[len - 1] = -1;
	newSuf[0] = len - 1;
	for (int h = 1; newRnk[len - 1] != len - 1; h <<= 1) {
		cmp c = {h};
		for (int i = 0; i < len; ++i) {
			int j = suf[i] - h;
			if (j < 0) continue;
			newSuf[rnkStrt[rnk[j]]++] = j;
		}

		for (int i = 1; i < len; ++i) {
			bool newGrp = c(newSuf[i - 1], newSuf[i]);
			newRnk[i] = newRnk[i - 1] + newGrp;
			if (newGrp)
				rnkStrt[newRnk[i]] = i;
		}

		for (int i = 0; i < len; ++i) {
			suf[i] = newSuf[i];
			rnk[suf[i]] = newRnk[i];
		}
	}
	return suf[len-1];
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("in.txt", "rt", stdin);
//	freopen("out.txt", "wt", stdout);
#endif
	int n;
	string s;
	cin >> n >> s;
	if(s == string(n,'0') || s == string(n,'1')){
		cout << "0 0\n";
		return 0;
	}

	int idx = s.find('0');
	string tmp = s.substr(idx);
	for(int i = 0 ; i < tmp.size() ; i++)
		str[i] = tmp[i];
	str[SZ(tmp)] = 0;
	int best = buildSuffArray();
	cout << idx << " " << best << "\n";

	return 0;

}
