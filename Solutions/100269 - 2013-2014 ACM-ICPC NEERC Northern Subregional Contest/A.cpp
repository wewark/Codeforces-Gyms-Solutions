// 2013-2014 ACM-ICPC NEERC Northern Subregional Contest
// 100269A

#include <bits/stdc++.h>
using namespace std;


int main() {
    freopen("arrange.in", "r", stdin);
    freopen("arrange.out", "w", stdout);

    int n; cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    sort(s.begin(), s.end());

    int c = 'A';
    for (int i = 0; i < n && c <= 'Z'; ++i) {
        if (s[i][0] == c)
            c++;
    }

    cout << int(c - 'A') << endl;

}