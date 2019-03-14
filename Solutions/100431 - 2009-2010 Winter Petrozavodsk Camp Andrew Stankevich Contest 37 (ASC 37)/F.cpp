// 2009-2010 Winter Petrozavodsk Camp Andrew Stankevich Contest 37 (ASC 37)
// 100431F

#include <bits/stdc++.h>

using namespace std;


#define SZ(x) (int)x.size()

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int N = 303;
const int MOD = 1000000007;
int dp[N][N];
bool increase[N];
int n, k;


int solve(int done, int idx) {
    if (done == n)return 1;
    int E = n - done;
    if (idx < 0)return 0;
    if (idx >= E)return 0;
    int &ret = dp[done][idx];
    if (~ret)return ret;

    if (increase[done]) {
        ret = solve(done, idx + 1);
        if (!increase[done + 1]) {
            ret += solve(done + 1, idx - 1);
        } else {
            ret += solve(done + 1, idx);
        }
    } else {
        ret = solve(done, idx - 1);
        if (!increase[done + 1]) {
            ret += solve(done + 1, idx - 1);
        } else {
            ret += solve(done + 1, idx);
        }
    }
	if(ret >= MOD)ret -= MOD;
    return ret;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
#else
    freopen("monotonic.in", "r", stdin);
    freopen("monotonic.out", "w", stdout);
#endif
    int sum = 0, x;
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        cin >> x;
        sum += x;
        increase[sum] = true;
    }

    memset(dp, -1, sizeof dp);
    if (increase[0])
        cout << solve(0, 0) << "\n";
    else
        cout << solve(0, n - 1) << "\n";


    return 0;

}
