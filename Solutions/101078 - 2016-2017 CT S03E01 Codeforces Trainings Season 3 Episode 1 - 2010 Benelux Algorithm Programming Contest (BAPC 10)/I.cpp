// 2016-2017 CT S03E01 Codeforces Trainings Season 3 Episode 1 - 2010 Benelux Algorithm Programming Contest (BAPC 10)
// 101078I

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

const int N = 1e6 + 6;
char str[N];

void print(list<char> &L){
    auto it = L.begin();
    while(it != L.end()){
        printf("%c",*it);
        it++;
    }
    puts("");
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
        scanf("%s",str);
        list<char> L;
        auto it = L.begin();
        int n = strlen(str);
        loop(i,n){
            if(str[i] == '<'){
                if(it != L.begin())it--;
            }else if(str[i] == '>'){
                if(it != L.end())it++;
            }else if(str[i] == '-'){
                if(it != L.begin()){
                    it--;
                    auto tmp = it;
                    tmp++;
                    L.erase(it);
                    it = tmp;
                }
            }else{
                L.insert(it,str[i]);
            }
        }
        print(L);
    }


    return 0;
}


