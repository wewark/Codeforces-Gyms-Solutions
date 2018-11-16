// 2013-2014 ACM-ICPC NEERC Northern Subregional Contest
// 100269G

#include <bits/stdc++.h>

using namespace std;

#define SZ(x) (int)x.size()

typedef long long ll;
typedef pair<int, int> pii;

const double eps = 1e-9;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//    freopen("input.in", "r", stdin);
    freopen("garage.in", "r", stdin);
    freopen("garage.out", "w", stdout);

    int W, H, w, h;
    cin >> W >> H >> w >> h;
    int n = 0, m = 0;
    double a = 0, b = 0;
    do {
        a += w + (w - eps);
        n++;
    } while (W - a >= w);
    do {
        b += h + (h - eps);
        m++;
    } while (H - b >= h);
    cout << n * 1LL * m << endl;
    return 0;
}