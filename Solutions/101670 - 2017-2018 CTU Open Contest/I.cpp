// 2017-2018 CTU Open Contest
// 101670I

#include <bits/stdc++.h>

using namespace std;

#define loop(i, n) for(int i = 0;i < int(n);i++)
#define rloop(i, n) for(int i = int(n);i >= 0;i--)
#define range(i, a, b) for(int i = int(a);i <= int(b);i++)
#define SZ(c) int(c.size())
#define ALL(c) c.begin(), c.end()
#define RALL(c) c.rbegin(), c.rend()
#define PI acos(-1)
#define pb push_back
#define mp make_pair
#define fr first
#define sc second


typedef vector<int> vi;
typedef vector<pair<int, int> > vii;
typedef long long ll;
typedef pair<int, int> pii;


const int N = 1e5 + 5;
int n, x, y;

ll nC2(ll n) {
    return n * (n - 1) / 2;
}

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while (cin >> n) {
        map<int, int> m1, m2;
        ll tot = 1LL*n*n;
        loop(i, n) {
            cin >> x >> y;
            m1[x - y]++;
            m2[x + y]++;
        }

        ll ans = 0;
        for (auto p : m1)ans += nC2(p.sc);
        for (auto p : m2)ans += nC2(p.sc);
        cout << fixed << setprecision(12) << (2.0 * ans) / tot << "\n";
    }

    return 0;
}
