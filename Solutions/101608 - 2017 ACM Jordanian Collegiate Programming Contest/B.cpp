// 2017 ACM Jordanian Collegiate Programming Contest
// 101608B

#include <bits/stdc++.h>
using namespace std;

const int N = 5005;
int arr[N];
int  t , n , ans;

int main()
{
    freopen("overcode.in","r",stdin);
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i = 0 ;i < n ; i++){
            scanf("%d",&arr[i]);
        }

        sort(arr,arr+n);
        ans = 0;
        for(int i = 0 ; i < n ; i++){
            if(i+5 < n && arr[i+5] - arr[i] <= 1000){
                ans++;
                i = i+5;
            }
        }
        printf("%d\n",ans);
    }

    return 0;
}
