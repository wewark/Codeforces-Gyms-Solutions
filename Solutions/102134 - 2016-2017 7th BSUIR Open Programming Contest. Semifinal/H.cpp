// 2016-2017 7th BSUIR Open Programming Contest. Semifinal
// 102134H

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


const int K = 25;
int cnt[K];

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int n;
    cin >> n;
    vi v(n);
    for (int &x : v)cin >> x;
    ll ans = 0;
    // for(int i = 0 ; i < n ; i++){
    // 	for(int j = 0 ;j < n ; j++){
    // 		for(int k = 0 ; k < n ; k++){
    // 			ans += v[i] ^ v[j] ^ v[k];
    // 		}
    // 	}
    // }

    for (int i = 0; i < n; i++) {
        for (int k = 0; k < K; k++) {
            if (v[i] & (1 << k))cnt[k]++;
        }
    }

    for (int k = 0; k < K; k++) {
        ll one = cnt[k];
        ll zero = n - cnt[k];
        ans += one * one * one * (1 << k);
        ans += one * zero * zero * (1 << k) * 3;
    }

    cout << ans << endl;

    return 0;
}

