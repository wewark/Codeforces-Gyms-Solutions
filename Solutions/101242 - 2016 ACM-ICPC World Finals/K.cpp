// 101242 - 2016 ACM-ICPC World Finals
// 101242K

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, sum;
vector<int> num;

bool valid(int k) {
    vector<int> tmp = num;
    int cur = k, cs = sum;
    int i;
    for (i = 0; i < n && cur;) {
        if (tmp[i] < cur) return false;
        tmp[i] -= cur;
        cs -= cur--;
        if (tmp[i] == 0) i++;
    }
    if (cur) return false;

    cur = k;
    int j;
    for (j = n - 1; j >= i && cur;) {
        if (tmp[j] < cur) return false;
        tmp[j] -= cur;
        cs -= cur--;
        if (tmp[j] == 0) j--;
    }
    if (cur) return false;

    return cs % 2 == 0;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    num.resize(n);
    sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
        sum += num[i];
    }
    for (int i = num[0]; i >= 1; --i) {
        if (valid(i)) {
            if (i == 1 && sum != 2) continue;
            cout << i << endl;
            return 0;
        }
    }
    cout << "no quotation" << endl;
    return 0;
}
