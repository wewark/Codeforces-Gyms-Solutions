// 2016-2017 7th BSUIR Open Programming Contest. Semifinal
// 102134E

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<
        pair<int, int>,
        null_type,
        less<pair<int, int> >,
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;

#define SZ(x) (int)x.size()

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int N = 1e5 + 5;

vi adj[N];
vector<pair<int, int> > queries[N];
bool good[N];
int par[N];
int subtree[N];
int ans[N];
int n, q, mxL, sqrRoot;
ordered_set X;
int ID;

void calc(int u, int p, int l) {
    subtree[u] = 1;
    mxL = max(mxL, l);
    for (int nxt : adj[u]) {
        if (nxt == p)continue;
        calc(nxt, u, l + 1);
        subtree[u] += subtree[nxt];
    }
}

int get_root(int u, int p) {
    int mx = 0;
    int best = -1;
    if (~p)mx = n - subtree[u];
    for (int nxt : adj[u]) {
        if (nxt == p)continue;
        mx = max(mx, subtree[nxt]);
        if (best == -1 || subtree[nxt] > subtree[best])best = nxt;
    }

    if (mx * 2 <= n)return u;
    return get_root(best, u);
}

void getGood(int u, int p, int l) {
    par[u] = p;
    good[u] = (l % sqrRoot == 0);
    for (int nxt : adj[u]) {
        if (nxt == p)continue;
        getGood(nxt, u, l + 1);
    }
}

vector<int> nodes;
pair<int, int> values[N];

void solve(int u, int p, int current) {
    if (u != current && good[u])return;

    vector<pair<int, int> > toDelete;
    vector<pair<int, int> > toAdd;
    nodes.push_back(u);
    for (int i = max(0, (int)nodes.size() - 2); i < nodes.size() - 1; i++) {
        X.erase(values[nodes[i]]);
        toAdd.push_back(values[nodes[i]]);
        X.insert({n - subtree[nodes[i + 1]], ID});
        toDelete.push_back({n - subtree[nodes[i + 1]], ID});
        ID++;
    }

    X.erase(values[u]);
    X.insert({n, ID});

//    cout << "AT " << u + 1 << endl;
//    for (auto p : X)cout << p.first << " ";;
//    cout << endl;

    for (auto query : queries[u]) {
        ans[query.second] = X.find_by_order(query.first)->first;
    }

    X.insert(values[u]);
    X.erase({n, ID});
    ID++;


    for (int nxt : adj[u]) {
        if (nxt == p)continue;
        solve(nxt, u, current);
    }

    for (auto p : toAdd)
        X.insert(p);

    for (auto p : toDelete)
        X.erase(p);
    
    nodes.pop_back();


}


int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
#endif

    cin >> n >> q;
    int a, b;
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int x, k;
    for (int i = 0; i < q; i++) {
        cin >> x >> k;
        --x, --k;
        queries[x].push_back({k, i});
    }

    calc(0, -1, 0);
    int root = get_root(0, -1);
    mxL = -1;
    calc(root, -1, 0);
//    sqrRoot = sqrt(mxL) + 1;
//    getGood(root, -1, 0);
    const int K = 1;
    good[0] = 1;
    // for (int i = 0; i < K; i++) {
    //     good[rand() % n] = true;
    // }


    for (int i = 0; i < n; i++) {
        if (good[i]) {
            calc(i, -1, 0);
            X.clear();
//            cout << "good" << i + 1 << endl;
            for (int i = 0; i < n; i++) {
                X.insert({subtree[i], ID});
//                cout << i + 1 << " " << subtree[i] << endl;
                values[i] = {subtree[i], ID};
                ID++;
            }
            solve(i, par[i], i);
        }
    }

    for (int i = 0; i < q; i++) {
        printf("%d\n", ans[i]);
    }


    return 0;
}