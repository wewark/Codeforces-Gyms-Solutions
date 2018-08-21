// 101409 - 2010-2011 ACM-ICPC, NEERC, Western Subregional Contest
// 101409C

#include <bits/stdc++.h>
#define fs first
#define sc second
#define pb push_back

using namespace std;

typedef long long ll;
const ll N=1313132, M=4e6 + 7, INF=1e9;
const double PI = 3.141592653589793238462643383279502884197;

ll n, q;

ll bigP(ll x) {
	ll p = 1;
	while (p < x) p *= 2;
	return p / 2;
}

string typeA(int trgt, ll l, ll r) {
	if (l == r) return "";

	ll mid = bigP(r - l + 1) + l;
	if (trgt >= mid)
		return "R" + typeA(trgt, mid, r);
	return "L" + typeA(trgt, l, mid - 1);
}

ll typeB(string& path, ll idx, ll l, ll r) {
	if (idx == path.length()) return l;

	ll mid = bigP(r - l + 1) + l;
	if (path[idx] == 'R')
		return typeB(path, idx + 1, mid, r);
	return typeB(path, idx + 1, l, mid - 1);
}

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	freopen("cbt.out","w",stdout);
	freopen("cbt.in","r",stdin);

	cin >> n >> q;

	while (q--) {
		char c; cin >> c;
		if (c == 'A') {
			ll x; cin >> x;
			cout << typeA(x, 0, n - 1) << endl;
		}
		else {
			string s; cin >> s;
			cout << typeB(s, 0, 0, n - 1) << endl;
		}
	}
	return 0;
}
