// 2011-2012 ACM-ICPC Southwestern European Regional Programming Contest (SWERC 2011)
// 101561H

#include <bits/stdc++.h>

#

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
#define sfi1(v) scanf("%d",&v)
#define sfi2(v1, v2) scanf("%d %d",&v1,&v2)
#define sfi3(v1, v2, v3) scanf("%d %d %d",&v1,&v2,&v3)
#define sfll1(v) scanf("%I64d",&v);
#define sfll2(v1, v2) scanf("%I64d %I64d",&v1,&v2)
#define sfll3(v1, v2, v3) scanf("%I64d %I64d %I64d",&v1,&v2,&v3)

typedef vector<int> vi;
typedef vector<pair<int, int> > vii;
typedef long long ll;
typedef pair<int, int> pii;


int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("out.in", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int n, k;
    while (cin >> k >> n && k && n) {
        vector<string> name(n);
        vector<vector<int>> rv(n, vector<int>(k));
        for (int i = 0; i < n; ++i) {
            cin >> name[i];
            for (int j = 0; j < k; ++j) {
                cin >> rv[i][j];
                rv[i][j]--;
            }
        }

        vector<bool> w(n);
        vi cnt(n);
        vector<vector<bool>> vis(n, vector<bool>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < k; ++j) {
                if (name[rv[i][j]] == name[i] ||
                        vis[i][rv[i][j]])
                    w[rv[i][j]] = true;
                cnt[rv[i][j]]++;
                vis[i][rv[i][j]] = true;
            }
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (w[i] || cnt[i] != k)
                ans++;
        }

        if (ans == 0) cout << "NO ";
        else cout << ans << " ";
        cout << "PROBLEM" << (ans == 1 ? "" : "S");
        cout << " FOUND" << endl;
    }
}
