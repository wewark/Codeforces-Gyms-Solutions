// 101512 - 2014 Benelux Algorithm Programming Contest (BAPC 14)
// 101512E

#include <bits/stdc++.h>

using namespace std;
const int N = 2e5 + 5;
int n;
int a[N], b[N], c[N];
int id[N];
int seg[N * 4];
const int OO = 1e9;

void upd(int ind, int ns, int ne, int tar, int val) {
    if (ns > tar || ne < tar)
        return;
    if (ns == tar && ne == tar) {
        seg[ind] = min(seg[ind], val);
        return;
    }
    int mid = ns + (ne - ns) / 2;
    int l = ind * 2, r = ind * 2 + 1;
    upd(l, ns, mid, tar, val);
    upd(r, mid + 1, ne, tar, val);
    seg[ind] = min(seg[l], seg[r]);
}

int rmq(int ind, int ns, int ne, int s, int e) {
    if (ns > e || ne < s)
        return OO;
    if (ns >= s && ne <= e)
        return seg[ind];

    int l = ind * 2, r = ind * 2 + 1;
    int md = ns + (ne - ns) / 2;
    return min(rmq(l, ns, md, s, e), rmq(r, md + 1, ne, s, e));
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
#endif
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        fill(seg, seg + n * 4, OO);
        for (int i = 0; i < n; i++) {
            scanf("%d %d %d", a + i, b + i, c + i);
        }
        iota(id, id + n, 0);
        sort(id, id + n, [](int i, int j) {
            if (a[i] != a[j]) return a[i] < a[j];
            if (b[i] != b[j]) return b[i] < b[j];
            return c[i] < c[j];
        });

        int nxt = 0, res = 0;
        for (int f = 0; f < n; f++) {
            int i = id[f];

            while (a[id[nxt]] < a[i]) {
                upd(1, 0, n, b[id[nxt]], c[id[nxt]]);
                nxt++;
            }

            if (rmq(1, 0, n, 0, b[i] - 1) >= c[i])
                res++;
        }
        printf("%d\n", res);
    }
    return 0;
}