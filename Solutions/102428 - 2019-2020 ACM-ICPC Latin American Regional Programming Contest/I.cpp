// 2019-2020 ACM-ICPC Latin American Regional Programming Contest
// 102428I

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
const int INF = 1e9;
const ll MOD = 1e9 + 7;

const int N = 2e3 + 3;
int n, l;
vvi adj;

vi mem(N, -1);
ll solve(int cur) {
    if (cur >= l) return 1;
    ll& ret = mem[cur];
    if (~ret) return ret;

    ret = 0;
    for (auto& i : adj[cur]) {
        ret += solve(i);
        ret %= MOD;
    }
    return ret;
}


vi mem2(N, -1);
ll solve2(int cur) {
    ll& ret = mem2[cur];
    if (~ret) return 0;
    if (cur >= l) return ret = 1;

    ret = 0;
    for (auto& i : adj[cur]) {
        ret += solve2(i);
        ret %= MOD;
    }
    return ret;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    cin >> n >> l;
    adj.assign(l, vi());
    for (int i = 0; i < l; ++i) {
        int sz; cin >> sz;
        for (int j = 0; j < sz; ++j) {
            int v; cin >> v; v--;
            adj[i].push_back(v);
        }
    }

    cout << solve(0) << " " << solve2(0) << endl;
}
