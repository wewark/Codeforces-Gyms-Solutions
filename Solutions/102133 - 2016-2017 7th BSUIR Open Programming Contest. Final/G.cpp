// 2016-2017 7th BSUIR Open Programming Contest. Final
// 102133G

#include <bits/stdc++.h>
using namespace std;

#define SZ(x) (int)x.size()

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;


int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
//	freopen("in.txt", "rt", stdin);
//	freopen("out.txt", "wt", stdout);
#endif
	const ll mod = 1LL << 42;
	ll cur = 0, p = 1;
	string res;
	for (int i = 1; i <= 42; i++, p *= 10) {
		p %= mod;
		if ((cur + p) % (1LL << i) == 0) {
			res += '1';
			cur += p;
		} else {
			res += '2';
			cur += (p * 2) % mod;
		}
//		cout << res << endl;
		cur %= mod;
	}
	reverse(res.begin(), res.end());
	cout << res << endl;
	return 0;
}
