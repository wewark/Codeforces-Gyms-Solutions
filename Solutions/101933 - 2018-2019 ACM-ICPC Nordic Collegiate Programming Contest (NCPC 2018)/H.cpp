// 2018-2019 ACM-ICPC Nordic Collegiate Programming Contest (NCPC 2018)
// 101933H

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
const double EPS = 1e-9;

struct Mower {
	string name;
	int idx, p, c, t, r;

	bool operator < (Mower other) const {
		if (p != other.p)
			return p < other.p;
		return idx < other.idx;
	}
};

ll l;
inline bool valid(Mower& m) {
	ll times = (m.t * m.c); // / double(l);
	ll tot_weeks = (m.t + m.r); // / 10080.0;
	return times * 10080 >= tot_weeks * l;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("in.txt", "rt", stdin);
//	freopen("out.txt", "wt", stdout);
#endif

	int m; cin >> l >> m;
	cin.ignore();
	string s;
	vector<Mower> mower(m), valids;
	for (int i = 0; i < m; ++i) {
		getline(cin,s);
		bool flag = 0;

		string name , num;
		vi v;
		int x = 0;
		for(int c : s){
			if(!flag && c == ','){
				flag = true;
			}else if(flag){
				if(c == ','){
					v.push_back(x);
					x = 0;
				}else{
					x *= 10;
					x += (c-'0');
				}
			}else{
				mower[i].name += c;
			}
		}
		v.push_back(x);
		mower[i].p = v[0];
		mower[i].c = v[1];
		mower[i].t = v[2];
		mower[i].r = v[3];
		mower[i].idx = i;

//		cout << mower[i].name << endl;
//		for(int x : v){
//			cout << x << endl;
//		}

		if (valid(mower[i])) {
//			cout << mower[i].name << endl;
			valids.push_back(mower[i]);
		}
	}

	sort(all(valids));
	if (valids.empty())
		cout << "no such mower" << endl;
	else {
		for (int i = 0; i < valids.size(); ++i) {
			if (valids[i].p == valids[0].p)
				cout << valids[i].name << endl;
		}
	}


	return 0;
}
