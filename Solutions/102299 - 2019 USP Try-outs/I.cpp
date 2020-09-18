// 2019 USP Try-outs
// 102299I

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
const int INF = 1e9;


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    
    int n; cin >> n;
    vector<pair<int, int>> num(n);
    for (int i = 0; i < n; ++i) {
        cin >> num[i].first >> num[i].second;
    }

    sort(num.begin(), num.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    });

    ll mx = LLONG_MIN, cur = 0;
    for (int i = 0; i < n; ++i) {
        cur += num[i].first;
        mx = max(mx, cur - num[i].second);
    }
    cout << mx << endl;
}
