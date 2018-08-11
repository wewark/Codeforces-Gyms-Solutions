#include <bits/stdc++.h>

using namespace std;

bool w = false;
int n = 0;
vector<int> pos(51, -1);
long long r = 0;

void dfs(int cur, int st, int aux, int ed) {
    if (w || !cur) return;

    if (pos[cur] == st) {
        dfs(cur - 1, st, ed, aux);
    } else if (pos[cur] == ed) {
        dfs(cur - 1, aux, st, ed);
        r |= (1LL << (cur - 1));
    } else w = true;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    // freopen("in.txt", "rt", stdin);

    vector<bool> vis(55);
    for (int i = 1; i <= 3; ++i) {
        int k;
        cin >> k;
        while (k--) {
            int x;
            cin >> x;
            if (vis[x]) {
                w = true;
            }
            vis[x] = true;
            pos[x] = i;
            n = max(n, x);
        }
    }

    dfs(n, 1, 2, 3);

    if (w)
        cout << "No" << endl;
    else
        cout << (1LL << n) - 1 - r << endl;

    return 0;
}
