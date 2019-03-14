// 2016-2017 7th BSUIR Open Programming Contest. Final
// 102133I

#include <bits/stdc++.h>
using namespace std;

#define SZ(x) (int)x.size()

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;


int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	// freopen("input.txt", "r", stdin);
#else
	// freopen("seaport.in", "r", stdin);
	// freopen("seaport.out", "w", stdout);
#endif

	int n;
	while(cin >> n){
        if(n <= 2){
            cout << n << endl;
            return 0;
        }

        bool flag = false;
        if(n % 3 == 1)flag = true;


        while(n){
            if(flag){
                cout << 1;
                n--;
            }else{
                cout << 2;
                n-=2;
            }
            flag = !flag;
        }

        cout << endl;
	}

	return 0;
}
