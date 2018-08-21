// 101512 - 2014 Benelux Algorithm Programming Contest (BAPC 14)
// 101512B

#include <bits/stdc++.h>

using namespace std;

const int N = 3605;
int n, target, a[N], vis[N], visID;
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
#endif
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &target);
        for (int i = 0; i < n; ++i)
            scanf("%d", a + i);
        queue<int> q;
        q.push(0);
        vis[0] = ++visID;
        int level = 0;
        int buttons = -1, time = 1e9;
        while (q.size()) {
            int sz = q.size();
            while (sz--) {
                auto cur = q.front();
                q.pop();
                if (cur >= target && time > cur) {
                    time = cur;
                    buttons = level;
                }
                for (int i = 0; i < n; ++i) {
                    int nxt = max(0, a[i] + cur);
                    nxt = min(3600, nxt);
                    if (vis[nxt] != visID) {
                        vis[nxt] = visID;
                        q.push(nxt);
                    }
                }
            }
            ++level;
        }
        printf("%d %d\n", buttons, time - target);
    }
    return 0;
}