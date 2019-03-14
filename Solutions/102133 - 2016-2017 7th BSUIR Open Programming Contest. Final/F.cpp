// 2016-2017 7th BSUIR Open Programming Contest. Final
// 102133F

#include <bits/stdc++.h>

using namespace std;

#define SZ(x) (int)x.size()

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int N = 1e5 + 2;
const ll INF = 1e18;
ll dp[N][2][2][2];
int arr[N], mx[N], mxidx[N];
int n;
int S, A, B, START, END;

ll solve(int idx = 0, int start = 0, int leave = 0) {
    if (leave > 1)return -INF;
    if (idx == n)return -INF;
    ll &ret = dp[idx][start][leave][S];
    if (~ret)return ret;
    ret = -INF;
    if (start == 0) {
        ret = max(solve(idx + 1, start, leave), solve(idx + 1, 1, leave) + arr[idx]);//start
        ret = max(ret, 1LL * arr[idx]);//started and ended in same index
    } else if (start == 1) {
        ret = solve(idx + 1, start, leave) + arr[idx];//take
        ret = max(ret, solve(idx + 1, start, leave + 1));//leave
        ret = max(ret, 1LL * (leave ? mx[idx] : 0));//stop
        ret = max(ret, 1LL * arr[idx]);//stop here
    }
    return ret;
}

void build(int idx = 0, int start = 0, int leave = 0) {
    if (idx == n)return;
    ll &ret = dp[idx][start][leave][S];
    if (start == 0) {
        if (ret == solve(idx + 1, start, leave)) {
            build(idx + 1, start, leave);
        } else if (ret == solve(idx + 1, 1, leave) + arr[idx]) {
            START = idx;
            build(idx + 1, 1, leave);
        } else {
            START = END = idx;
        }
    } else if (start == 1) {
        if (ret == solve(idx + 1, start, leave) + arr[idx]) {
            build(idx + 1, start, leave);
        } else if (ret == solve(idx + 1, start, leave + 1)) {
            A = idx;
            build(idx + 1, start, leave + 1);
        } else if(ret == arr[idx]){
            END = idx;
        }else{
            B = mxidx[idx];
            END = idx - 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
#endif

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];


    long long ans = -1e18;
    int bests = 0;
    memset(dp, -1, sizeof dp);

    for (S = 0; S < 2; S++) {
        mx[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            mx[i] = max(arr[i], mx[i + 1]);
        }

        if (solve() > ans) {
            ans = solve();
            bests = S;
        }
        reverse(arr, arr + n);
    }

    cout << ans << endl;
    S = bests;
    if (bests == 1) {
        reverse(arr, arr + n);
    }

    mx[n - 1] = arr[n - 1];
    mxidx[n - 1] = n - 1;
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] > mx[i + 1]) {
            mx[i] = arr[i];
            mxidx[i] = i;
        } else {
            mx[i] = mx[i + 1];
            mxidx[i] = mxidx[i + 1];
        }
    }

    A = -1;
    B = -1;
    START = -1;
    END = n - 1;
    build();
    if (A == -1) {
        //didn't leave
        if (START != END) {
            A = START;
            B = END;
        } else {
            A = 0;
            B = 1;
        }
    } else if (B == -1) {
        //left but didn't replace
        B = END;
    }

    if (bests == 1) {
        A = n - 1 - A;
        B = n - 1 - B;
    }

    cout << A + 1 << " " << B + 1 << "\n";
    return 0;
}

/*
 5
 3 -1 -1 100 100
 */