// CCPC 2016-2017 Finals
// 101206D

#ifndef Local
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/STACK:1024000000,1024000000")
#endif

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int t;
  cin >> t;

  for (int cs = 1; cs <= t; ++cs) {
    cout << "Case #" << cs << ": ";
    int n, m, r;
    cin >> n >> m >> r;
    --r;
    vector<int> c(n);
    for (int& x : c) {
      cin >> x;
    }
    vector<vector<int>> adj(n);
    while (m--) {
      int x, y;
      cin >> x >> y;
      --x, --y;
      adj[x].push_back(y);
      adj[y].push_back(x);
    }
    for (int i = 0; i < n; ++i) {
      adj[i].push_back(i);
      adj[i].push_back(r);
      adj[r].push_back(i);
    }
    vector<bool> vis(n, false);
    Long curr = 0;
    for (int i = 0; i < n; ++i) {
      int cnt_fr = 0;
      for (int v : adj[i]) {
        if (v >= i && !vis[v]) {
          vis[v] = true;
          ++cnt_fr;
        }
      }
      cnt_fr = min(cnt_fr, c[i]);
      curr += c[i] - cnt_fr;
      if (!vis[i] && curr > 0) {
        vis[i] = true;
        --curr;
      }
    }
    cout << curr << endl;
  }
}
