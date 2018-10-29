// 2013-2014 ACM-ICPC NEERC Northern Subregional Contest
// 100269E

#include <bits/stdc++.h>

using namespace std;

#define SZ(x) (int)x.size()
#define all(x) x.begin(),x.end()

typedef long long ll;
typedef pair<int, int> pii;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//    freopen("input.in", "r", stdin);
    freopen("energy.in", "r", stdin);
    freopen("energy.out", "w", stdout);
    int n;string s;
    cin >> n >> s;
    int one = 0 , two = 0;
    long long ans = 0;
    for(char c : s){
        if(c == '1')one++;
        else two++;
        if(two * 2 + one > n){
            if(two)two--;
            else one--;
        }
        ans += (one + two);
    }

    cout << ans << endl;


    return  0;
}