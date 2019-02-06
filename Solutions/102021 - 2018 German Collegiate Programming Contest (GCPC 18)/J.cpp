// 2018 German Collegiate Programming Contest (GCPC 18)
// 102021J

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

const int N = 3e5 + 5;
const int M = 4 * N;
int up[N], lft[N], fz[N], down[N];
bool used[N];
vi zeros[6];
vi adj[M], row[N];
int arr[N][4];
int n;

void rotate(int idx) {
    int x = arr[idx][0];
    loop(i, 3)arr[idx][i] = arr[idx][(i + 1)];
    arr[idx][3] = x;
}

bool solveRow(int cur, int condtion, int r) {
    int Break = 0;
    while (true) {
        Break += (fz[cur] == condtion);
        int cnt = 0;
        while (cnt < 5) {
            if (arr[cur][0] == lft[SZ(row[r])] && arr[cur][1] == up[SZ(row[r])] &&
                (down[SZ(row[r])] == -1 || arr[cur][3] == down[SZ(row[r])]))
                break;
            rotate(cur);
            cnt++;
        }

        if (cnt == 5) return 0;

        up[SZ(row[r])] = arr[cur][3];
        row[r].push_back(cur);
        lft[SZ(row[r])] = arr[cur][2];
        if (Break == 2)break;
        cur = (adj[lft[SZ(row[r])]][0] != cur) ? adj[lft[SZ(row[r])]][0] : adj[lft[SZ(row[r])]][1];
        if (used[cur])return 0;
    }
    return true;
}

bool solve() {
    memset(down, -1, sizeof(down));
    if (SZ(zeros[2]) != 4)return 0;

    //solving first row
    int cur = zeros[2][0];
    used[cur] = true;
    if (!solveRow(cur, 2, 0))return 0;
    if (n % SZ(row[0])) return 0;

    int rows = n / SZ(row[0]), cols = SZ(row[0]);

    //solving mid rows
    range(k, 1, rows - 2) {
        cur = used[adj[up[0]][0]] ? adj[up[0]][1] : adj[up[0]][0];
        if (used[cur])return 0;
        used[cur] = true;
        if (!solveRow(cur, 1, k))return 0;
        if (SZ(row[k]) != cols)return 0;
    }

    loop(i, cols + 3)down[i] = 0;
    cur = used[adj[up[0]][0]] ? adj[up[0]][1] : adj[up[0]][0];
    if (used[cur])return 0;
    used[cur] = true;
    if (!solveRow(cur, 2, rows - 1))return 0;
    if (SZ(row[rows - 1]) != cols)return 0;
    return 1;
}

bool solve3() {
    return solveRow(zeros[3][0], 3, 0) && SZ(row[0]) == n;
}

void print() {
    int r = 0;
    while (SZ(row[r]))r++;
    cout << SZ(row[0]) << " " << r << "\n";
    loop(i, SZ(row[0])) {
        loop(j, r) {
            if (j)cout << " ";
            cout << row[j][i] + 1;
        }
        cout << "\n";
    }
}

int main() {

#ifndef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;

    loop(i, n) {
        loop(j, 4) {
            cin >> arr[i][j];
            if (arr[i][j] == 0)
                fz[i]++;
            else
                adj[arr[i][j]].pb(i);
        }
        zeros[fz[i]].pb(i);
    }

    if (SZ(zeros[4]) && n == 1) {
        cout << "1 1" << endl;
        cout << "1" << endl;
        return 0;
    }

    if (SZ(zeros[4]) || n == 1) {
        cout << "impossible\n";
        return 0;
    }

    if (SZ(zeros[3])) {
        bool flag = true;
        flag &= SZ(zeros[3]) == 2;
        flag &= SZ(zeros[2]) == n - 2;
        if (!flag || !solve3()) {
            cout << "impossible\n";
        } else {
            print();
        }
        return 0;
    }


    if (!solve()) {
        cout << "impossible\n";
    } else {
        print();
    }

    return 0;
}
