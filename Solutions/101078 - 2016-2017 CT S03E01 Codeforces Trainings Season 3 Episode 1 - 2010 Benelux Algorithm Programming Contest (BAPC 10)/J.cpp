// 2016-2017 CT S03E01 Codeforces Trainings Season 3 Episode 1 - 2010 Benelux Algorithm Programming Contest (BAPC 10)
// 101078J

#include <bits/stdc++.h>
using namespace std;

#define loop(i,n) for(int i = 0;i < int(n);i++)
#define rloop(i,n) for(int i = int(n);i >= 0;i--)
#define range(i,a,b) for(int i = int(a);i <= int(b);i++)
#define SZ(c) int(c.size())
#define ALL(c) c.begin(), c.end()
#define RALL(c) c.rbegin(), c.rend()
#define PI acos(-1)
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define sfi1(v) scanf("%d",&v)
#define sfi2(v1,v2) scanf("%d %d",&v1,&v2)
#define sfi3(v1,v2,v3) scanf("%d %d %d",&v1,&v2,&v3)
#define sfll1(v) scanf("%I64d",&v);
#define sfll2(v1,v2) scanf("%I64d %I64d",&v1,&v2)
#define sfll3(v1,v2,v3) scanf("%I64d %I64d %I64d",&v1,&v2,&v3)

typedef vector<int> vi;
typedef vector<pair<int,int> > vii;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 3005;
vi adj[N+N];
char tmp[N];
char str[N][N];
int ID[N][N];
int vis[N][N];
int done[N+N];
int l[N] , r[N] ,Vis[N];
int n , m , visid , j , i , ones , two;

void FillRow(int id){
    adj[id].clear();
    int len = strlen(tmp);
    loop(k,len){
        str[i][j+k] = tmp[k];
        vis[i][j+k] = visid;
        ID[i][j+k] = id;
    }
}

bool match(int i){
    for(int j = 0 ; j < adj[i].size() ; j++){
        if(Vis[adj[i][j]] == visid)continue;
        Vis[adj[i][j]] = visid;
        if(l[adj[i][j]] == -1 || match(l[adj[i][j]])){
            l[adj[i][j]] = i;
            r[i] = adj[i][j];
            return true;
        }
    }
    return false;
}

int runMatching(){
    int cc = 0;
    memset(r,-1,sizeof r);
    memset(l,-1,sizeof l);
    for(int i = 0 ; i < n ; i++){
        visid++;
        if(match(i))
            cc++;
    }
    return cc;
}


int main()
{

#ifndef ONLINE_JUDGE
	//freopen("in.in", "r", stdin);
	//freopen("out.in", "w", stdout);
	//ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#endif

    int t;
    sfi1(t);
    while(t--){
        visid++;
        sfi2(n,m);
        loop(k,n){
            sfi2(j,i);
            scanf("%s",tmp);
            FillRow(k);
        }

        loop(c,m){
            sfi2(j,i);
            scanf("%s",tmp);
            int len = strlen(tmp);
            adj[n+c].clear();
            loop(k,len){
                if(vis[i+k][j] == visid && str[i+k][j] != tmp[k]){
                    adj[n+c].pb(ID[i+k][j]);
                    adj[ID[i+k][j]].pb(n+c);
                }
            }
        }

        printf("%d\n",n+m-runMatching());
    }


    return 0;
}

