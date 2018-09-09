// Arab Collegiate Programming Contest 2012
// 100155I

#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int v[N][N];
int dx[8] = {1,1,1,0,0,-1,-1,-1};
int dy[8] = {1,0,-1,1,-1,1,0,-1};
int n , m;

bool valid(int x , int y){
    return x < n && x >= 0 && y < m && y >= 0;
}


int main()
{

    scanf("%d%d",&n,&m);
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            scanf("%d",&v[i][j]);
        }
    }

    set<int> s;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(v[i][j] != -1)
            for(int k = 0 ; k < 8 ; k++){
                int nxtx = i + dx[k];
                int nxty = j + dy[k];
                if(valid(nxtx,nxty) && v[nxtx][nxty] == v[i][j]){
                    s.insert(v[i][j]);
                }
            }
        }
    }

    printf("%d\n",s.size());

    return 0;
}
