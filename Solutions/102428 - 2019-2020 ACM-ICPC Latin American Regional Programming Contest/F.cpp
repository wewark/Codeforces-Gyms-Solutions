// 2019-2020 ACM-ICPC Latin American Regional Programming Contest
// 102428F

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vs = vector<string>;
const int INF = 1e9;
const ll MOD = 1e9 + 7;
#define all(x) x.begin(),x.end()

const int N = 5005;

ll mem[N][N];
ll solve(int s, int b) {
    if (b == 0) return 1;
    if (s <= 0) return 0;

    ll& ret = mem[s][b];
    if (~ret) return ret;
    ret = 0;

    if (s <= b)
        ret = solve(s, b - s);
    ret += solve(s - 1, b) * 2;
    ret -= solve(s - 2, b);
    ret += MOD;
    ret %= MOD;
    return ret;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    memset(mem, -1, sizeof(mem));
    int s, b;
    cin >> s >> b;
    cout << solve(s, b - s) << endl;
}
