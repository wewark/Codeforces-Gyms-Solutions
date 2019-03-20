// 2016-2017 7th BSUIR Open Programming Contest. Semifinal
// 102134B

#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace std;
//using namespace  __gnu_pbds;

#define SZ(x) (int)x.size()

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

pair<ll, ll> get(ll a, ll b) {
    ll g = __gcd(a, b);
    return make_pair(a / g, b / g);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ll a, b;
    cin >> a >> b;
    b =  (1LL << b);

    map<pair<ll, ll>, bool> vis;
    map<pair<ll, ll>, pair<ll, ll> > par;
    queue<pair<ll, ll> > q;
    vis[{a, b}] = 0;
    q.push({a, b});
    while (!q.empty() && vis.find(make_pair(1, 2)) == vis.end()) {
        pair<ll, ll> p = q.front();
        q.pop();
        pair<ll, ll> cur = get(p.first * 2, p.second);
        if (cur.first < cur.second && vis.find(cur) == vis.end()) {
            vis[cur] = 0;
            par[cur] = p;
            q.push(cur);
        }

        cur = get(p.second - p.first, p.second);
        if (cur.first < cur.second && vis.find(cur) == vis.end()) {
            vis[cur] = 1;
            par[cur] = p;
            q.push(cur);
        }
    }

    pair<ll, ll> p = {1, 2};
    pair<ll, ll> END = {a, b};
    cout << '0';
    while (p != END) {
        cout << vis[p];
        p = par[p];
    }


    return 0;
}

