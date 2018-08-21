// 101196 - 2016-2017 ACM-ICPC East Central North America Regional Contest (ECNA 2016)
// 101196E

#include <bits/stdc++.h>

using namespace std;

string s;
int n;

inline int solve(string sub) {
    int m = sub.length();
    int ret = n + m;
    for (int i = 0; i < n - m + 1; ++i) {
        if (s.substr(i, m) == sub) {
            ret -= m - 1;
            i += m - 1;
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
//     freopen("in.txt", "rt", stdin);

    cin >> s; n = s.length();
    set<string> st;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            st.insert(s.substr(i, j - i + 1));
        }
    }

    int r = n;
    for (auto& i : st) {
        r = min(r, solve(i));
//        cout << i << " " << solve(i) << endl;
    }

    cout << r << endl;
    return 0;
}
