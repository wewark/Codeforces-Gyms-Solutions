// 101512 - 2014 Benelux Algorithm Programming Contest (BAPC 14)
// 101512J

#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
#endif

    int t; cin >> t; cout << t << endl;
    while (t--) {
        string s; cin >> s;
        vector<string> g(300, string(110, '#'));
        pair<int, int> c(150, 0);
        g[c.x][c.y] = '.';
        int cd = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == 'R')
                cd = (cd + 1) % 4;
            else if (s[i] == 'L')
                cd = (cd - 1 + 4) % 4;
            else if (s[i] == 'B')
                cd = (cd + 2) % 4;
            c.x += dx[cd];
            c.y += dy[cd];
            g[c.x][c.y] = '.';
        }

        int w = 0;
        vector<string> r;
        for (int i = 0; i < g.size(); ++i) {
            if (find(g[i].begin(), g[i].end(), '.') != g[i].end()) {
                r.push_back(g[i]);
                int cw = r.back().size() - 1;
                while (r.back()[cw] == '#') cw--;
                w = max(w, cw);
            }
        }

        cout << r.size() + 2 << " " << w + 2 << endl;
        cout << string(w + 2, '#') << endl;
        for (int i = 0; i < r.size(); ++i) {
            cout << r[i].substr(0, w + 2) << endl;
        }
        cout << string(w + 2, '#') << endl;


    }

    return 0;
}