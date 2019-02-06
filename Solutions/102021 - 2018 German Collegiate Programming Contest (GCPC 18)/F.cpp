// 2018 German Collegiate Programming Contest (GCPC 18)
// 102021F

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

const int N = 1e6 + 6;
int idx[N];
int p[N];
vi ones;


int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int x = 1, y = 1;
    bool flag = true;
    while (x < N && y < N) {
        p[min(x, y)] = max(x, y);
        if (flag) x += y;
        else y += x;
        flag ^= 1;
    }

    memset(idx, -1, sizeof idx);
    int n;
    cin >> n;
    loop(i, n) {
        cin >> x;
        if (idx[x] == -1)
            idx[x] = i;
        if (x == 1)ones.pb(i);
    }

    if (SZ(ones) > 1) {
        cout << ones[0] + 1 << " " << ones[1] + 1 << endl;
        return 0;
    }

    loop(i, N) {
        if (idx[i] == -1)continue;
        if (idx[p[i]] == -1)continue;
        int a = idx[i], b = idx[p[i]];
        if (a == b)continue;
        cout << a + 1 << " " << b + 1 << endl;
        return 0;
    }

    cout << "impossible" << endl;

    return 0;
}
