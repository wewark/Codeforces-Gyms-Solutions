// 2018-2019 ACM-ICPC Brazil Subregional Programming Contest
// 101908L

#include<bits/stdc++.h>
using namespace std;


const int N = 100010;
const int LG = 30;
vector <int> adj[N];
int depth[N], dp[N], anc[N][LG];
int tin[N], tout[N], timer;
int n;
int lvl[N];

void dfs(int u = 0 , int par = 0 , int l = 0){
    tin[u] = timer++;
    lvl[u] = l;
    anc[u][0] = par;
    for(auto nxt : adj[u])
	if(nxt != par)
            dfs(nxt , u , l+1);
    tout[u] = timer++;
}

bool ancestor(int a, int b){
    return tin[a] <= tin[b] && tout[b] <= tout[a];
}

void buildLCA() {
    int lg = ceil(log2(n));
    for(int j = 1 ; j < lg ; j++)
        for(int i = 0 ; i < n ; i++)
            anc[i][j] = anc[anc[i][j - 1]][j - 1];
}

int LCA(int i, int j){
    int lg = ceil(log2(n));
    int st = lg;
    if (lvl[i] > lvl[j])swap(i, j);
    int cur = lvl[j];
    for (; st >= 0; st--)
        if (cur - (1 << st) >= lvl[i])
            cur -= (1 << st), j = anc[j][st];
    if (i == j)return 2 * i - j;
    cur = lvl[i];
    for (st = lg; st >= 0; st--)
        if (anc[i][st] != anc[j][st])
            cur -= (1 << st), i = anc[i][st], j = anc[j][st];
    return anc[i][0];
}

int DIS(int a , int b){
    return lvl[a] + lvl[b] - 2*lvl[LCA(a,b)];
}

int main(){

    int q, f, t, a, b, c, d;
	scanf("%d %d", &n, &q);
	for (int i = 0; i < n - 1; i++) {
		scanf("%d %d", &f, &t);
		f--, t--;
		adj[f].push_back(t);
		adj[t].push_back(f);
	}
    int root = -1;
    for(int i = 0 ; i < n ; i++)
        if(adj[i].size() > 1)
            root = i;
    dfs(root);
    buildLCA();
    while (q--) {
		scanf("%d %d %d %d", &a, &b, &c, &d);
		a--, b--, c--, d--;
        int X = LCA(a,b);
        int Y = LCA(c,d);

        if(X == Y){
            int ans = max( DIS(LCA(a,c) , X) + DIS(LCA(b,d) , X) + 1 , DIS(LCA(a,d) , X) + DIS(LCA(b,c) , X) + 1);
            printf("%d\n",ans);
        }else if(!ancestor(X,Y) && !ancestor(Y,X)){
            printf("0\n");
        }else{
            if(!ancestor(X,Y)){
                swap(X,Y);
                swap(a,c);
                swap(b,d);
            }


            int ans = 0;
            for(int j = 0 ; j < 2 ; j++){
                int lcaAC = LCA(a,c) , lcaAD = LCA(a,d);
                if(ancestor(Y,lcaAC)){
                    //cout << Y+1 << "---" << lcaAC+1 << " " << a+1 << " " << c+1 << " " << root << " " << LCA(c,a)<< endl;
                    ans = max(ans , DIS(lcaAC,Y)+1);
                }


                if(ancestor(Y,lcaAD)){
                    //cout << Y+1 << " " << lcaAD+1 << endl;
                    ans = max(ans , DIS(lcaAD,Y)+1);
                }
                swap(a,b);
            }

            printf("%d\n",ans);
        }
    }

    return 0;
}

