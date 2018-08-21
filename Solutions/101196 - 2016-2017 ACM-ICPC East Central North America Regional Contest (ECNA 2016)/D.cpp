// 101196 - 2016-2017 ACM-ICPC East Central North America Regional Contest (ECNA 2016)
// 101196D

#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

const int N = 105;
long long dist[N], len[N];
vector<pair<int, long long> > adj[N];
int n, m;
string name[N];
map<string, int> mp;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
//     freopen("in.txt", "rt", stdin);
    cin >> n >> m;
    int id = 1;
    mp["English"] = id++;
    for (int i = 0; i < n; i++) {
        cin >> name[i];
        mp[name[i]] = id++;
    }

    string a, b;
    long long c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        int v = mp[a], u = mp[b];
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }

    for (int i = 0; i < N; i++) {
        len[i] = dist[i] = LLONG_MAX;
    }
    
   len[1] = 0;
    dist[1] = 0;

    long long ans = 0;
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto nxt : adj[u]) {
            if (len[u] + 1 <= len[nxt.first]) {
                if (len[nxt.first] == LLONG_MAX)q.push(nxt.first);
                len[nxt.first] = min(len[nxt.first], len[u] + 1);
                dist[nxt.first] = min(dist[nxt.first], nxt.second);
            }
        }
    }

    for(int i = 2 ; i < id ; ++i){
        if(len[i] == LLONG_MAX){
            puts("Impossible");
            return  0;
        }
        ans += dist[i];
    }

    cout << ans << "\n";


    return 0;
}
