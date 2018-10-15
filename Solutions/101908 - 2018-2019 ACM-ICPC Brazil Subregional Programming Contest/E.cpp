// 2018-2019 ACM-ICPC Brazil Subregional Programming Contest
// 101908E

#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 4;
char s[N] , k[N];
int vis[N];

int main()
{
    scanf("%s%s",k,s);
    int szS = strlen(s);
    int szK = strlen(k);


    for(int i = 0 ; i < szS ; i++){
        for(int j = i ; j < szK ; j++){
            if(s[i] == k[j])vis[j-i] = true;
        }
    }

    int ans = 0;
    for(int i = 0 ; i < szK-szS+1 ; ++i)
        ans += !vis[i];

    printf("%d\n",ans);

    return 0;
}
