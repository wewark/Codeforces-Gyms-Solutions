// 2019 USP Try-outs
// 102299H

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
const int INF = 1e9;

const int N = 100;

struct Student {
    vi courses;

    Student() : courses(N, -1) {}
};

int n, m;

inline double euclideanDistance(Student& a, Student& b) {
    double ret = 0;
    bool share = false;
    for (int i = 0; i < m; ++i) {
        if (~a.courses[i] && ~b.courses[i]) {
            share = true;
            ret += (a.courses[i] - b.courses[i]) * (a.courses[i] - b.courses[i]);
        }
    }
    return share ? sqrt(ret) : INF;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    cin >> n >> m;
    vector<Student> st(n);
    for (int i = 0; i < n; ++i) {
        int sz; cin >> sz;
        for (int j = 0; j < sz; ++j) {
            int c, g; cin >> c >> g;
            c--;
            st[i].courses[c] = g;
        }
    }

    for (int i = 0; i < n; ++i) {
        double mn = INF;
        int mni = -1;
        for (int j = 0; j < n; ++j) {
            if (j == i) continue;
            double ed = euclideanDistance(st[i], st[j]);
            if (ed < mn) {
                mn = ed;
                mni = j;
            }
        }

        int mx = -1, mxi = -2;
        for (int j = 0; j < m; ++j) {
            if (st[i].courses[j] == -1 && st[mni].courses[j] > mx) {
                mx = st[mni].courses[j];
                mxi = j;
            }
        }

        cout << mxi + 1 << endl;
    }

}
