// 2018-2019 ACM-ICPC Asia Seoul Regional Contest
// 101987D

#include <bits/stdc++.h>
using namespace std;

string s;

map<string, string> M;


int main()
{
    M["a"] = "as";
M["i"] = "ios";
M["y"] = "ios";
M["l"] = "les";
M["n"] = "anes";
M["ne"] = "anes";
M["o"] = "os";
M["r"] = "res";
M["t"] = "tas";
M["u"] = "us";
M["v"] = "ves";
M["w"] = "was";

    int t;
    cin >> t;
    while (t--) {
        cin >> s;
        int sz = s.size();
        string lst;
        lst += s[sz - 1];
        if (M.find(lst) != M.end()) {
            s.pop_back();
            s += M[lst];
        } else if (sz > 1) {
            lst = "";
            lst += s[sz - 2];
            lst += s[sz - 1];
            if (M.find(lst) != M.end()) {
                s.pop_back();
                s.pop_back();
                s += M[lst];
            } else {
                s += "us";
            }
        } else {
            s += "us";
        }
        cout << s << "\n";
    }
    return 0;
}
