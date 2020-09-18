// CCPC 2016-2017 Finals
// 101206E

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

// gp_hash_table<int, int> table;

int solve(const vector<pair<int, int>>& supply, const vector<int>& demand) {
  int res = 0;
  int s_ind = 0;
  multiset<int> ms;
  for (int x : demand) {
    while (s_ind < supply.size() && supply[s_ind].first <= x) {
      ms.insert(supply[s_ind].second);
      ++s_ind;
    }
    while (!ms.empty() && *ms.begin() < x) {
      ms.erase(ms.begin());
    }
    res = max(res, (int) supply.size() - (int) ms.size() + 1);
    if (!ms.empty()) {
      ms.erase(ms.begin());
    }
  }
  return res;
}

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
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> supply(n);
    vector<int> demand(m);
    for (auto& pr : supply) {
      cin >> pr.first >> pr.second;
    }
    for (auto& c : demand) {
      cin >> c;
    }
    sort(supply.begin(), supply.end());
    sort(demand.begin(), demand.end());

    int res = solve(supply, demand);
    if (res == n + 1) {
      cout << "IMPOSSIBLE!" << endl;
    } else {
      cout << res << endl;
    }

  }
}
