// 2016-2017 7th BSUIR Open Programming Contest. Final
// 102133B

#include <bits/stdc++.h>

using namespace std;

#define SZ(x) (int)x.size()

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;


int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
#endif
    int n;
    cin >> n;

    if (n == 2 || n == 3) {
        cout << -1 << endl;
        return 0;
    }


    cout << n << "\n";
    if (n == 1) {
        cout << n << "\n";
        return 0;
    }

    vector<int> ans;
    for (int i = 2; i <= n; i += 2)
        ans.push_back(i);

    for (int i = 1; i <= n; i += 2)
        ans.push_back(i);


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[j] + i * n << " \n"[j == n - 1];
        }
    }


    return 0;
}

