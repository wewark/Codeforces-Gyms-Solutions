#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll m, n, q;
vector<ll> w;

vector<vector<ll> > mem;
ll solve(ll k, ll left) {
  if (k == 0) return left == 0;
  if (left == 0) return k == 0;
  if (mem[k][left] != -1) return mem[k][left];

  ll ret = 0;
  for (int i = 0; i < m; ++i) {
    if (w[i] <= left)
      ret += solve(k - 1, left - w[i]);
  }

  return mem[k][left] = ret;
}

int main() {
  int t; cin >> t;
  while (t--) {
    cin >> m >> n >> q;
    w.resize(m);
    mem.assign(6, vector<ll>(55, -1));
    for (int i = 0; i < m; ++i) {
      string s; cin >> s;
      w[i] = s.length();
    }

    while (q--) {
      int x; cin >> x;
      cout << solve(n, x) << endl;
    }
  }
}
