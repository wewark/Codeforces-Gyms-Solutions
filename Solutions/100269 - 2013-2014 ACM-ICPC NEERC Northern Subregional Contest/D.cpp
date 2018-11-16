// 2013-2014 ACM-ICPC NEERC Northern Subregional Contest
// 100269D

#include <bits/stdc++.h>

using namespace std;

#define SZ(x) (int)x.size()

typedef long long ll;
typedef pair<int, int> pii;

const int N = 10004;

vector<pii> adj[N];

int n, m;
int c[N];
ll dp[N];
bool vis[N];
#define sc second
#define fr first

ll solve(){
    priority_queue<pair<ll,int> , vector<pair<ll,int>> , greater<pair<ll,int>>> pq;
    for(int i = 0 ; i < n ; i++)
        pq.push({c[i],i});

    while(!pq.empty()){
        pair<ll,int> p = pq.top();
        pq.pop();
        for(auto nxt : adj[p.sc]){
            if(c[nxt.sc] > c[p.sc] + c[nxt.fr]){
                c[nxt.sc] = c[p.sc] + c[nxt.fr];
                pq.push({c[nxt.sc] , nxt.sc});
            }
        }
    }
    return c[0];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//    freopen("input.in", "r", stdin);
    freopen("dwarf.in", "r", stdin);
    freopen("dwarf.out", "w", stdout);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> c[i];

    for (int i = 0; i < m; i++) {
        int a, x, y;
        cin >> a >> x >> y;
        a--, x--, y--;
        adj[x].push_back({y, a});
        adj[y].push_back({x, a});
    }

    cout << solve() << endl;

    return 0;
}