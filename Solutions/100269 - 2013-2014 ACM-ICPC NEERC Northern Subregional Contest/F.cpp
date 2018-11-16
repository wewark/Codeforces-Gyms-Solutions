// 2013-2014 ACM-ICPC NEERC Northern Subregional Contest
// 100269F

#include <bits/stdc++.h>

using namespace std;

#define SZ(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define LSOne(S) (S & (-S))

typedef long long ll;
typedef pair<int, int> pii;

class BIT {
private:
    vector<int> ft;

public:
    BIT() {}
    BIT(int n) { ft.assign(n + 1, 0); }

    int rsq(int b) {
        int sum = 0; for (; b; b -= LSOne(b)) sum += ft[b];
        return sum;
    }

    int rsq(int a, int b) {
        return rsq(b) - (a == 1 ? 0 : rsq(a - 1));
    }

    void adjust(int k, int v) {
        for (; k < (int)ft.size(); k += LSOne(k)) ft[k] += v;
    }
};


const ll INF = 1e17;
const int N = 1005;
const int K = 52;
vector<int> adj[N];
long long dp[N][K];
long long C[N][N];
int arr[N];
int n, s, k;

ll solve(int idx, int k) {
    if (k == -1)return INF;
    if (idx == 0) return 0;
    ll &ret = dp[idx][k];
    if (~ret)return ret;
    ret = INF;
    for (int i = idx; i; i--) {
        ret = min(ret, solve(i - 1, k - 1) + C[i][idx]);
    }
    return ret;
}

BIT bit;

void clear() {
    bit = BIT(n + 5);
}

void add(int rw) {
    for (auto& i : adj[rw]) {
        bit.adjust(i, 1);
    }
}

int query(int rw) {
    int ret = 0;
    for(auto &i : adj[rw]){
        if(i != 1)ret += bit.rsq(i-1);
    }
    return ret;
}

void precompute() {
    clear();
    for (int i = 1; i <= s; i++) {
        C[i][i] = 0;
        add(i);
        for (int j = i + 1; j <= s; ++j) {
            C[i][j] = C[i][j - 1] + query(j);
//            cout << i << " " << j << " " << C[i][j] << endl;
            add(j);
        }
        clear();
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//    freopen("input.in", "r", stdin);
    freopen("flight.in", "r", stdin);
    freopen("flight.out", "w", stdout);

    memset(dp, -1, sizeof(dp));
    cin >> n >> s >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        adj[arr[i]].push_back(i + 1);
    }

    precompute();
    cout << solve(s, k) << endl;


}