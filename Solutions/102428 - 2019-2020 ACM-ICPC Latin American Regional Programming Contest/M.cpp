// 2019-2020 ACM-ICPC Latin American Regional Programming Contest
// 102428M

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vs = vector<string>;
const int INF = 1e9;
const ll MOD = 1e9 + 7;


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    int n, x; cin >> n >> x;
    vi num(n);
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int cur = 1;
        for (int j = i; j < n - 1; ++j) {
            if (num[j + 1] - num[j] > x)
                break;
            cur++;
        }
        ans = max(ans, cur);
    }

    cout << ans << endl;

}
