// 2019-2020 ACM-ICPC Latin American Regional Programming Contest
// 102428E

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
const int INF = 1e9;


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    string c; cin >> c;
    ll s; cin >> s;
    c += c;

    int a = 0, b = 0, n = c.length() / 2;
    int ce = 0;
    ll ans = 0;
    while (a < n) {
        while (b - a < s && ce == 0) {
            ce += (c[b] == 'E');
            b++;
        }

        if (ce)
            ans += s - (b - a) + 1;
        ce -= (c[a] == 'E');
        a++;
    }

    cout << ans << endl;
}
