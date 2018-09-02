// 2014-2015 Northwestern European Regional Contest (NWERC 2014)
// 101482K

#include <bits/stdc++.h>
using namespace std;

const int M = 1e7 + 7;
const int N = 2005;
int arr[N];
int nxt[M] , dx[M];
long long ans[N];
int n , s , t;


void solve(int idx){
    multiset<int> SET;
    ans[idx] = 1LL*t * n;
    for(int i = 0 ; i < n ; i++)
        SET.insert(arr[i]);
    int cur = arr[idx];
    while(SET.size()){
        auto it = SET.lower_bound(cur);
        if(it == SET.end()){
            ans[idx] += s - cur;
            cur = 0;
            continue;
        }

        ans[idx] += *it - cur;
        cur = (*it + t) % s;
        SET.erase(it);
    }

}

int main() {
    scanf("%d%d%d",&n,&s,&t);
    for(int i = 0 ; i < n ; i++){
        scanf("%d",&arr[i]);
    }


    sort(arr,arr+n);
    for(int i = 0 ; i < n ; i++){
        solve(i);
    }


    nxt[s] = arr[0]+s;
    memset(nxt,-1,sizeof nxt);
    for(int i = 0 ;i < n ; i++){
        nxt[arr[i]] = arr[i];
        dx[arr[i]] = i;
    }

    nxt[s] = arr[0] + s;
    for(int i = 0 ; i <= s ; i++){
        if(nxt[i] == -1)continue;
        int idx = i;
        while(idx && nxt[idx-1] == -1){
                nxt[idx-1] = nxt[i];
                dx[--idx] = dx[i];
        }
    }

    long long mx = 0;
    long long sum = 0;

    for(int i = 0 ; i < s ; i++){
        long long val = nxt[i] - i + ans[dx[i]];
        sum += val;
        mx = max(mx , val);
    }

    int g = __gcd(sum,s*1LL);
    printf("%lld\n",*min_element(ans,ans+n));
    printf("%lld\n",mx);
    printf("%lld/%d\n",sum/g,s/g);

    return 0;
}
