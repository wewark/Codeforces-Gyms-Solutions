#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
//     freopen("in.txt", "rt", stdin);

    string ciper;
    string key;
    string message;
    cin >> ciper >> key;
    for (int i = 0; i < ciper.size(); i++) {
        message += (ciper[i] - (key[i] - 'A'));
        if (message.back() < 'A') {
            int dif = 'A' - message.back();
            message[message.size() - 1] = ('Z' - dif) + 1;
        }
        key += message.back();
    }

    cout << message << "\n";
    return 0;
}
