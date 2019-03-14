// 2016-2017 7th BSUIR Open Programming Contest. Final
// 102133C

#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace std;
//using namespace  __gnu_pbds;

#define SZ(x) (int)x.size()

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;


ll n;
// map<ll,bool> mp;
// const int N = 1e6 + 5;

// bool bt(ll cur) {
// 	if (abs(cur) > n)
// 		return cur < 0;

// 	if(mp.find(cur) != mp.end())
// 		return mp[cur];

// 	if (cur > 0) {
// 		for(int i = 9; i >= 2; i--) {
// 			if (bt(-cur * i))
// 				return mp[cur] = true;
// 		}
// 		return mp[cur] = false;
// 	}

// 	cur = -cur;
// 	for(int i = 9; i >= 2; i--) {
// 		if (!bt(cur * i))
// 			return  mp[-cur] = false;
// 	}
// 	return  mp[-cur] = true;
// }

bool solve(ll cn) {
	ll cur = 1;
	bool ret = false, nine = true;
	while (cur <= cn) {
		cur *= nine ? 9 : 2;
		ret = !ret;
		nine = !nine;
	}
	return ret;
}

// ll log9(ll x) {
// 	ll cur = 1, p = 0;
// 	while (cur * p <= x)
// 		p++, cur *= 9;
// 	return p;
// }

int main() {
// 	ios::sync_with_stdio(false), cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	// freopen("input.txt", "r", stdin);
#endif

	// int x; cin >> x;
	// for (int i = 2; i <= x; i++) {
	// 	n = i;
	// 	if (bt(1) != solve(i))
	// 		cout << "NOPE" << endl;
	// 	// cout << i << " " << log9(i) << " " << (bt(1) ? "YES" : "NO");
	// 	// cout << " " << (solve(i) ? "YES" : "NO") << endl;
	// 	mp.clear();
	// }
	

	int t; scanf("%d", &t);
	while (t--) {
		// mp.reserve(N);
		// mp.max_load_factor(0.25);
		scanf("%lld", &n);
		printf("%s\n", solve(n) ? "YES" : "NO");
		// mp.clear();
	}
}

// 1:YES
// 9:NO  9
// 18:YES 18
// 162:NO 18 * 9
// 324:YES 18 * 9 * 2
// 2916:NO 18 * 9 * 2 * 9
// 5832:YES 18 * 18 * 18
// 52488:NO 18^3 * 9