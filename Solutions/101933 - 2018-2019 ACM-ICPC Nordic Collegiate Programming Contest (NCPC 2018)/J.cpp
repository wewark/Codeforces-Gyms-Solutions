// 2018-2019 ACM-ICPC Nordic Collegiate Programming Contest (NCPC 2018)
// 101933J

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

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("in.txt", "rt", stdin);
//	freopen("out.txt", "wt", stdout);
#endif

	ll a, b, c, d;
	cin >> a >> b >> c >> d;

	ll zero = 1, one = 1;
	ll A = 0, D = 0;

	while (A < a) {
		A += zero;
		zero++;
	}

	while (D < d) {
		D += one;
		one++;
	}

	if (a + b + c + d == 0) {
		cout << 0 << endl;
		return 0;
	}

	if (A != a || D != d) {
		cout << "impossible" << endl;
		return 0;
	}

	if (b == 0 && c == 0) {
		if (a && d)
			cout << "impossible" << endl;
		else if (a) {
			cout << string(zero, '0') << endl;
		} else if (d) {
			cout << string(one, '1') << endl;
		} else
			cout << "1" << endl;
		return 0;
	}

	if (zero * one != c + b) {
		cout << "impossible" << endl;
		return 0;
	}

	string s;
	ll C = zero * one;
	s = string(one, '1');
	int idxZ = SZ(s);
	s += string(zero, '0');

	ll idx1 = 0, idx0 = idxZ;
	while (C > c) {
		ll need = min(C - c, idx0 - idx1);
		C -= need;
		swap(s[idx0], s[idx0 - need]);
		idx0++;
		idx1++;
	}

//	int idx = -1;
//	while (C > c) {
//		int st = idxZ++;
//		int mv = st - (idx + 1);
//		if ((C - c) >= mv) {
//			swap(s[st], s[st - mv]);
//			idx++;
//			C -= mv;
//		} else {
//			swap(s[st], s[st - (C - c)]);
//			break;
//		}
////		cout << C << " " << st << " " << s << endl;
//	}

	cout << s << endl;

	return 0;
}
