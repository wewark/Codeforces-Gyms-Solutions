// 101512 - 2014 Benelux Algorithm Programming Contest (BAPC 14)
// 101512G

#include <bits/stdc++.h>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
#endif
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<double> a(n), b(n), c(n);
        double mx = 0, mxi = -1;
        for (int i = 0; i < n; ++i) {
            cin >> a[i] >> b[i] >> c[i];
            double mxx = b[i] / (2.0 * a[i]);
            double mxy = -a[i] * mxx * mxx + b[i] * mxx + c[i];
            if (mxy > mx)
                mx = mxy, mxi = i;
        }
        cout << mxi + 1 << endl;
    }
    return 0;
}