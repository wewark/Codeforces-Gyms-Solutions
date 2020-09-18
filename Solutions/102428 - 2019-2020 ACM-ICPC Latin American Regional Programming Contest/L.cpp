// 2019-2020 ACM-ICPC Latin American Regional Programming Contest
// 102428L

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vs = vector<string>;
const int INF = 1e9;
const ll MOD = 1e9 + 7;

int n, m;
vs g;
vvi mx;

inline bool valid(int x) {
    for (int j = 0; j < m - x + 1; ++j) {
        int a = 0, b = a;
        while (b < n) {
            while (b < n && mx[b][j] >= x) {
                b++;
            }
            if (b - a >= x)
                return true;
            a = a == b ? ++b : b;
        }
    }
    return false;
}

int BS() {
    int a = 1, b = min(n, m), mid = (a + b) / 2;
    while (a < b) {
        if (valid(mid))
            a = mid;
        else
            b = mid - 1;
        mid = (a + b + 1) / 2;
    }
    return mid * mid;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    cin >> n >> m;
    g.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> g[i];
    }

    mx.assign(n, vi(m));
    for (int i = 0; i < n; ++i) {
        int a = m - 1, b = a;
        while (b >= 0) {
            while (b >= 0 && g[i][b] == g[i][a]) {
                mx[i][b] = a - b + 1;
                b--;
            }
            a = b;
        }
    }

    cout << BS() << endl;
}
