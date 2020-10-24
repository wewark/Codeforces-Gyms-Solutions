// 2020 Lenovo Cup USST Campus Online Invitational Contest
// 102623B

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <deque>
#include <cstring>
#include <map>
#include <cmath>
#include <iomanip>

using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vb = vector<bool>;
using pii = pair<int, int>;
using vii = vector<pii>;
using vs = vector<string>;
#define all(x) x.begin(),x.end()
int di[] = {0, 1, 0, -1};
int dj[] = {1, 0, -1, 0};
const ll MOD = 1e9 + 7;
const ll INF = 1e9;


int main(int argc, char **argv) {
    ios::sync_with_stdio(false), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
#endif

    int n; cin >> n;
    int ans = INF;
    for (int i = 0; i < n; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        ans = min(ans, x * x + y * y + z * z);
    }
    cout << fixed << setprecision(3) << sqrt(ans) << endl;
}