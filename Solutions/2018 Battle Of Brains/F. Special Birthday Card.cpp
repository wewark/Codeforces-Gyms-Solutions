#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define ub upper_bound
#define lb lower_bound
#define sz(s) (int)s.size()
#define pii pair<int,int>
#define piii pair< int,pair<int,int> >
#define ff first
#define ss second
#define all(a) a.begin(),a.end()
#define rall(v) v.rbegin(),v.rend()
#define endl '\n'
#define matrix vector<vector<int> >
#define boost ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define NAYAN freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define N 1000005
#define mod 1000000007
#define inf 1e17
 
int  a[N];
vector <int> f[N];
int mp[N];
 
int cnt[N];
void sieve()
{
    a[0]=1;
    a[1]=1;
    int i,j;
    int n=sqrt(N)+2;
    for(i=2;i<N;i++)
    {
        if(mp[i]==0)
        {
            for(j=i*i;j<N;j+=i)
            {
                if(mp[j]==0)
                    mp[j]=i;
            }
        }
    }
    for(i=1;i<N;i++)
    {
        if(mp[i]==0)
            mp[i]=i;
    }
}
 
void factorize()
{
    int i;
    for(i=1;i<N;i++)
    {
        //f[i].pb(1);
        int n=i;
        while(n!=1)
        {
            f[i].pb(mp[n]);
            n/=mp[n];
        }
        int l=sz(f[i]);
        if(l<=2)
            cnt[i]=1;
    }
 
    
 
    for(i=1;i<N;i++)
    {
        cnt[i]=cnt[i]+cnt[i-1];
    }
}
 
 
int32_t main()  
{
    boost
    #ifndef ONLINE_JUDGE 
    NAYAN
    #endif
    sieve();
    factorize();
    int t;
    cin >> t;
    int cn=1;
    while(t--)
    {
        int n;
        cin >> n;
        int p,q;
        p=cnt[n];
        q=n;
        int g=__gcd(p,q);
        p/=g;
        q/=g;
        cout << "Case " << cn++ << ": " << p << "/" << q << endl;
 
    }
 
}