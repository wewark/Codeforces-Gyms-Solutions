#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll n;
vector<pll> a, b;

inline bool valid(ll x) {
    ll cur = x;
    for (int i = 0; i < b.size(); ++i) {
        if (cur < b[i].first)
            return false;
        cur += b[i].second - b[i].first;
    }

    for (int i = 0; i < a.size(); ++i) {
        if (cur < a[i].first)
            return false;
        cur += a[i].second - a[i].first;
    }

    return true;
}

ll bs() {
    ll a = 0, b = 1e15 + 100, mid = (a + b) / 2;
    while (a < b) {
        if (valid(mid))
            b = mid;
        else
            a = mid + 1;
        mid = (a + b) / 2;
    }
    return mid;
}

bool cmp(pll p1, pll p2) {
    if (p1.second != p2.second)
        return p1.second > p2.second;
    return p1.first > p2.first;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        pll p; cin >> p.first >> p.second;
        if (p.second >= p.first)
            b.push_back(p);
        else
            a.push_back(p);
    }
    sort(b.begin(), b.end());
    sort(a.begin(), a.end(), cmp);

    cout << bs() << endl;
    return 0;
}
