
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
using namespace __gnu_pbds;
 
typedef vector <long long> vi;
typedef pair <long long, long long> pii;
#define pb push_back   
#define all(c) c.begin(), c.end()
#define For(i, a, b) for (long long i = a; i < b; ++i)
#define Forr(i, a, b) for (long long i = a; i > b; --i)
#define um unordered_map
#define F first
#define S second
#define int long long
#define inf LLONG_MAX
#define endl "\n"
#define min(a,b) (a < b ? a : b)
#define max(a,b) (a > b ? a : b)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define _CRT_SECURE_NO_WARNINGS

int modulo = 1e9 + 7;
 
int fpow(int a, int n) {
        int ans = 1;
        while (n) {
                if (n&1) ans = (ans*a)%modulo;
                a = (a*a)%modulo; n = n >> 1;
        }
        return ans;
}
 
signed main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        // #ifndef ONLINE_JUDGE
        // freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
        // #endif
        int n; cin >> n;
       	int ans[n];
       	int y = 0;
       	For(i,0,n) {
       		int num = i+1;
       		int val = 1;
       		for (int j = 1; j <= sqrt(num); ++j) {
       			if (num%j == 0 and j != num) {
       				val = max(val, ans[j-1]+1);
       				int x = num/j;
       				if (x != num)
       					val = max(val, ans[x-1]+1);
       			}
       		}
       		ans[i] = val;
       		y = max(y, ans[i]);
       	}
       	cout << y << endl;
       	printarr(ans,n);
        return 0;
}
