#include <bits/stdc++.h>

using namespace std;
string arr[15];

int ts[15][15], id = 0;
int tf[15][15], tid[15][15];
bool vis[15][15];
int mx = 0;

struct game {
    int wd, wo, bd, bo, bs, ws, bf, wf;

    int blackwin(int nx) {

        int a = wd, b = wo;
        if (wf == b)
            swap(a, b);

        // cout<<a<<" "<<b<<" "<<ws;
        if (ts[a][b] < ws) {
            ts[a][b] = ws;
        }

        swap(bd, bo);
        swap(wd, wo);
        int rt = wo;
        wo = nx;
        bs++;
        mx = max(mx, bs);
        ws = 0;
        wf = wd;
        a = wd, b = wo;

        if (tid[a][b] == -1) {
            tid[a][b] = id++;
            tf[a][b] = wf;
        }
        return rt;
    }

    int whitewin(int nx) {

        int a = bd, b = bo;
        if (bf == b)
            swap(a, b);
        //	cout<<a<<" "<<b<<" "<<bs<<"\n";
        if (ts[a][b] < bs) {
            ts[a][b] = bs;
        }

        swap(bd, bo);
        swap(wd, wo);
        int rt = bo;
        bo = nx;
        ws++;
        mx = max(mx, ws);
        bs = 0;
        bf = bd;
        a = bd, b = bo;

        if (tid[a][b] == -1) {
            tid[a][b] = id++;
            tf[a][b] = bf;
        }
        return rt;
    }

};

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    //freopen("in.txt", "rt", stdin);

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
    string g;
    cin >> g;
    memset(tid, -1, sizeof tid);

    game ga;

    queue<int> q;
    ga.wo = 1;
    ga.bo = 2;
    ga.wf = 1;
    ga.wd = 3;
    ga.bd = 4;
    ga.bf = 2;
    ga.ws=ga.bs=0;
    tid[1][3] = id++;
    tid[2][4] = id++;
    tf[1][3] = 1;
    tf[2][4] = 2;
    for (int i = 5; i <= n; ++i)
        q.push(i);
    mx = 0;
    for (auto c : g) {
        if (c == 'W') {
            int ls = ga.whitewin(q.front());
            q.pop();
            q.push(ls);
        } else {
            int ls = ga.blackwin(q.front());
            q.pop();
            q.push(ls);
        }
    }
    if (g.back() == 'B') {
        int ls = ga.whitewin(q.front());
        q.pop();
        q.push(ls);
    } else {
        int ls = ga.blackwin(q.front());
        q.pop();
        q.push(ls);
    }

    while(q.size()) q.pop();
    
    ga.wo = 1;
    ga.bo = 2;
    ga.wf = 1;
    ga.wd = 3;
    ga.bd = 4;
    ga.bf = 2;
    ga.ws=ga.bs=0;
    
    tf[1][3] = 1;
    tf[2][4] = 2;
    for (int i = 5; i <= n; ++i)
        q.push(i);
    
    for (auto c : g) {
        if (c == 'W') {
            int ls = ga.whitewin(q.front());
            q.pop();
            q.push(ls);
            if(ga.ws==mx){
                int a=ga.wd,b=ga.wo;
                if(ga.wf==b) swap(a,b);
                cout<<arr[a]<<" "<<arr[b]<<"\n";
            }
        } else {
            int ls = ga.blackwin(q.front());
            q.pop();
            q.push(ls);
            if(ga.bs==mx){
            int a=ga.bd,b=ga.bo;
            if(ga.bf==b) swap(a,b);
            cout<<arr[a]<<" "<<arr[b]<<"\n";
            }
        }
    }
    

    return 0;
}