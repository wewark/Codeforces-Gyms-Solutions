// 2016-2017 CT S03E01 Codeforces Trainings Season 3 Episode 1 - 2010 Benelux Algorithm Programming Contest (BAPC 10)
// 101078C

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

const int N = 5005;
const int MOD = 10007;
const int MSK = (1<<9)+3;
short dp[N][MSK][9];
vi adj[9];
int visid , n;

pii numToPair(int x){
    return mp(x/3,x%3);
}

int pairToNum(pii p){
    return p.fr*3+p.sc;
}

bool valid(int x){
    return x >= 0 && x < 3;
}

void pre(){
    loop(i,3){
        loop(j,3){
            range(dx,-1,1){
                range(dy,-1,1){
                    int nxti = i + dx , nxtj = j + dy;
                    if(nxti == i && nxtj == j)continue;
                    if(!valid(nxti) || !valid(nxtj))continue;
                    if(abs(dx)+abs(dy) != 1)continue;
                    int a = pairToNum(mp(i,j));
                    int b = pairToNum(mp(nxti,nxtj));
                    if( a > b )continue;
                    adj[a].pb(b);
                }
            }
        }
    }
}

int rev(int msk){
    int all = (1<<9)-1;
    return all&(~msk);
}

short solve(int idx = 0, int msk = 0 , int b = 0){
    if(idx == 0)return msk == 0;
    short &ret = dp[idx][msk][b];
    if(~ret)return ret;
    ret = solve(idx-1,rev(msk));
    range(i,b,8){
        if(msk &(1<<i))continue;
        for(int nxt : adj[i]){
            if(msk & (1<<nxt))continue;
            int m = msk;
            m |= (1<<i);
            m |= (1<<nxt);
            ret += solve(idx,m,i);
            if(ret >= MOD)ret -= MOD;
        }
    }
    return ret;
}

int main()
{
    pre();
    /*
    loop(i,9){
        cout << i << " ==> ";
        for(int nxt : adj[i])cout << nxt << " ";
        cout << endl;
    }
    */
    int t;
    sfi1(t);
    memset(dp,-1,sizeof dp);
    while(t--){
        sfi1(n);
        printf("%d\n",solve(n));
    }


    return 0;
}


