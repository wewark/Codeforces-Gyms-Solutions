// 2014-2015 Northwestern European Regional Contest (NWERC 2014)
// 101482H

#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 4;
vector<int> adj[N];
int x[N] , y[N];
int n , id;

void dfs(int u , int par = -1){
    y[u] = ++id;
    bool flag = (par != -1);
    for(int nxt : adj[u]){
        if(nxt == par)continue;
        if(!flag){
            x[nxt] = x[u];
            dfs(nxt,u);
            flag = true;
        }else{
            x[nxt] = y[u];
            dfs(nxt,u);
        }
    }
}


int main()
{
    int a , b;
    scanf("%d",&n);
    if(n == 2){
        puts("1 2");
        puts("1 2");
        return 0;
    }

    for(int i = 1 ; i < n ; i++){
        scanf("%d%d",&a,&b);
        --a,--b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i = 0 ; i < n ; i++){
        if(adj[i].size() > 1){
            x[i] = ++id;
            y[i] = ++id;
            dfs(i,-1);
            break;
        }
    }

    for(int i = 0 ; i < n ; i++){
        printf("%d %d\n",x[i],y[i]);
    }

    return 0;
}
