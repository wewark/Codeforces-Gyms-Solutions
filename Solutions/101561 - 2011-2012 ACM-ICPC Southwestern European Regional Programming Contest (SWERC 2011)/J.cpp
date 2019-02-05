// 2011-2012 ACM-ICPC Southwestern European Regional Programming Contest (SWERC 2011)
// 101561J

#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
#include <ext/numeric>


using namespace std;
using namespace __gnu_cxx;

#define loop(i, n) for(int i = 0;i < int(n);i++)
#define rloop(i, n) for(int i = int(n);i >= 0;i--)
#define range(i, a, b) for(int i = int(a);i <= int(b);i++)
#define SZ(c) int(c.size())
#define ALL(c) c.begin(), c.end()
#define RALL(c) c.rbegin(), c.rend()
#define PI acos(-1)
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define sfi1(v) scanf("%d",&v)
#define sfi2(v1, v2) scanf("%d %d",&v1,&v2)
#define sfi3(v1, v2, v3) scanf("%d %d %d",&v1,&v2,&v3)
#define sfll1(v) scanf("%I64d",&v);
#define sfll2(v1, v2) scanf("%I64d %I64d",&v1,&v2)
#define sfll3(v1, v2, v3) scanf("%I64d %I64d %I64d",&v1,&v2,&v3)

typedef vector<int> vi;
typedef vector<pair<int, int> > vii;
typedef long long ll;
typedef pair<int, int> pii;

vector<bool> isprime(1e7 + 7, 1);
const int MOD = 1e9 + 7;
vi primes;

void sieve(int n) {
    for (int i = 2; i <= n; ++i) {
        if (isprime[i]) {
            primes.pb(i);
            if (1LL * i * i <= n) {
                for (int j = i * i; j <= n; j += i) {
                    isprime[j] = false;
                }
            }
        }
    }
}

struct mul {
    ll operator()(const ll &n1, const ll &n2) const {
        return (n1 * n2) % MOD;
    }
};

ll identity_element(const mul &m) {
    return 1LL;
}

int MUL(int x, int y) {
    ll ret = x;
    ret *= y;
    if (ret >= MOD)ret %= MOD;
    return ret;
}


int solve(int n, int p) {
    int ret = 0;
    while (n >= p) {
        ret += n / p;
        n /= p;
    }
    if (ret & 1)ret--;
    return ret;
}

//int power(int a, int b) {
//    int x = 1, y = a;
//    while (b > 0) {
//        if (b & 1) {
//            x = MUL(x, y);
////            x = 1LL * x * y % MOD;
//        }
//        y = MUL(y, y);
////        y = 1LL * y * y % MOD;
//        b >>= 1;
//    }
//    return x;
//}

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("out.in", "w", stdout);
#endif

//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);

    sieve(1e7 + 1);
    int N;
    while (scanf("%d", &N)) {
        if (!N)return 0;
        int ans = 1;
        for (int p : primes) {
            if (p > N)break;
            ans = MUL(ans, power(p, solve(N, p), mul()));
//            ans = 1LL * ans * power(p, solve(N, p)) % MOD;
        }
        printf("%d\n", ans);
    }

    return 0;


}
