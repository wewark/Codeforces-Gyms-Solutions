#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int nz, nr;
vector<vector<int> > adj, dist;
vector<int> vis(1e4); int vf = 0;
vector<int> stv;
int mnstr = INT_MAX, mnctr = -1;

void bfs(int ct) {
  queue<pair<int, int> > q; q.push(make_pair(stv[ct], 1));
  vf++;

  while (!q.empty()) {
    int cur = q.front().first, d = q.front().second;
    q.pop();
    vis[cur] = vf;

    dist[ct][cur] = d;

    for (int i = 0; i < adj[cur].size(); ++i)
      if (vis[adj[cur][i]] != vf) {
        vis[adj[cur][i]] = vf;
        q.push(make_pair(adj[cur][i], d + 1));
      }
  }
}

int main() {
  int t; cin >> t;
  while (t--) {
    cin >> nz >> nr;
    adj.assign(1e4, vector<int>());

    mnstr = INT_MAX, mnctr = -1;

    for (int i = 0; i < nz; ++i) {
      int id, mz; cin >> id >> mz;
      for (int j = 0; j < mz; ++j) {
        int v; cin >> v;
        adj[id].push_back(v);
      }
    }

    set<int> st;
    stv.clear();
    for (int i = 0; i < nr; ++i) {
       int mr; cin >> mr;
       for (int j = 0; j < mr; ++j) {
        int x; cin >> x;
        st.insert(x);
      }
    }

    dist.assign(st.size(), vector<int>(1e4, 1e9));
    for (auto i = st.begin(); i != st.end(); i++)
      stv.push_back(*i);
    for (int i = 0; i < stv.size(); ++i)
      bfs(i);


    for (int i = 1; i < 1e4; ++i) {
      if (!adj[i].empty()) {
        int mx = 0;
        for (int j = 0; j < dist.size(); ++j)
          mx = max(mx, dist[j][i]);

        if (mx < mnstr)
            mnstr = mx, mnctr = i;
      }
    }

    cout << mnstr << " " << mnctr << endl;
  }
}
