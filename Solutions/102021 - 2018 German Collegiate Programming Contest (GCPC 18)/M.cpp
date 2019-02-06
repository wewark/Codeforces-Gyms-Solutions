// 2018 German Collegiate Programming Contest (GCPC 18)
// 102021M

#include <bits/stdc++.h>

using namespace std;

#define loop(i, n) for(int i = 0;i < int(n);i++)
#define rloop(i, n) for(int i = int(n);i >= 0;i--)
#define range(i, a, b) for(int i = int(a);i <= int(b);i++)
#define SZ(c) int(c.size())
#define ALL(c) c.begin(), c.end()
#define RALL(c) c.rbegin(), c.rend()
#define PI acos(-1)
#define pb push_back
#define mp make_pair
#define fr first
#define sc second


typedef vector<int> vi;
typedef vector<pair<int, int> > vii;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 502;
const int M = N * N;
const int Q = 1e5 + 2;
int p[M], w[M];
set<int> adj[M];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int arr[N][N], id[N][N], ID;
bool done[M];
int ans[Q];
int n, m, q;

bool valid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void init() {
    for (int i = 0; i < M; i++)
        p[i] = i, w[i] = 1;
}

int f(int u) {
    if (u == p[u])return u;
    return p[u] = f(p[u]);
}

void join(set<int> &A, set<int> &B, int val) {
    if (SZ(A) < SZ(B)) {
        A.swap(B);
    }

    for (int x : B) {
        if (A.find(x) == A.end()) {
            A.insert(x);
        } else {
            A.erase(x);
            ans[x] = val;
        }
    }
}

void connect(int a, int b, int val) {
    a = f(a);
    b = f(b);
    if (a == b)return;
    if (w[a] < w[b])swap(a, b);
    w[a] += w[b];
    p[b] = a;
    join(adj[a], adj[b], val);
}


int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    cin >> n >> m >> q;
    vector<pair<int, pii> > cells;
    loop(i, n)loop(j, m) {
            cin >> arr[i][j];
            id[i][j] = ID++;
            cells.push_back({arr[i][j], {i, j}});
        }

    int x1, y1, x2, y2;
    sort(ALL(cells));
    loop(i, q) {
        cin >> x1 >> y1 >> x2 >> y2;
        x1--, y1--;
        x2--, y2--;
        if (x1 == x2 && y1 == y2) {
            ans[i] = arr[x1][y1];
        } else {
            adj[id[x1][y1]].insert(i);
            adj[id[x2][y2]].insert(i);
        }
    }

    for (auto cell : cells) {
        int x = cell.sc.fr, y = cell.sc.sc, val = cell.fr;
        loop(i, 4) {
            int nxtx = x + dx[i];
            int nxty = y + dy[i];
            if (!valid(nxtx, nxty) || !done[id[nxtx][nxty]])continue;
            connect(id[x][y], id[nxtx][nxty], val);
        }
        done[id[x][y]] = true;
    }

    loop(i, q)cout << ans[i] << "\n";


    return 0;
}
