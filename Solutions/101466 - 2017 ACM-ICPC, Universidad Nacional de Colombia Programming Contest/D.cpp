// 101466 - 2017 ACM-ICPC, Universidad Nacional de Colombia Programming Contest
// 101466D

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<char> r;
    while (n) {
        if (n % 2 == 0) {
            r.push_back('B');
            n = (n - 2) / 2;
        }
        else {
            r.push_back('A');
            n = (n - 1) / 2;
        }
    }

    for (int i = r.size() - 1; i >= 0; i--)
        cout << r[i];
    cout << endl;
    return 0;
}
