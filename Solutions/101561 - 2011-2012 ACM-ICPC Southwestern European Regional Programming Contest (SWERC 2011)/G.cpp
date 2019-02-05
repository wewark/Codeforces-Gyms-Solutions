// 2011-2012 ACM-ICPC Southwestern European Regional Programming Contest (SWERC 2011)
// 101561G

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

const int N = 2e6 + 6;
ll arr[N];
int n;
deque<int> dq;

void add(int idx) {
    while (!dq.empty() && arr[dq.back()] >= arr[idx])
        dq.pop_back();
    dq.push_back(idx);
}

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("out.in", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int x;
    while (cin >> n) {
        if (!n)return 0;
        dq.clear();
        range(i, 1, n) {
            cin >> x;
            arr[i + n] = arr[i] = x;
            arr[i] += arr[i - 1];
            add(i);
        }

        range(i, n + 1, n + n) {
            arr[i] += arr[i - 1];
        }

        int ans = 0;
        loop(i, n) {
            while(dq.front() <= i)
                dq.pop_front();

            if (arr[dq.front()] >= arr[i]) {
                ans++;
            }
            
            add(n+i+1);
        }
        cout << ans << "\n";
    }

}
