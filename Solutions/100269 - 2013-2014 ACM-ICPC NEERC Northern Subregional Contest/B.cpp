// 2013-2014 ACM-ICPC NEERC Northern Subregional Contest
// 100269B

#include <bits/stdc++.h>

using namespace std;

#define SZ(x) (int)x.size()
#define all(x) x.begin(),x.end()

typedef long long ll;
typedef pair<int, int> pii;

struct Cand {
    string name;
    int votes = 0, idx;

    bool operator < (Cand& other) const {
        if (votes != other.votes)
            return votes > other.votes;
        return idx < other.idx;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("bad.in", "r", stdin);
    freopen("bad.out", "w", stdout);

    int n, m; cin >> n >> m;
    vector<Cand> cand(n);
    for (int i = 0; i < n; ++i) {
        cin >> cand[i].name;
        cand[i].idx = i;
        cand[i].votes = 0;
    }

    int inv = 0;
    for (int i = 0; i < m; ++i) {
        string s; cin >> s;
        if (count(all(s), 'X') != 1) {
            inv++;
            continue;
        }
        cand[s.find('X')].votes++;
    }

    sort(all(cand));
    for (int i = 0; i < n; ++i) {
        cout << cand[i].name << " ";
        int x = cand[i].votes / double(m) * 100000;
        if (x % 10 >= 5) x += 10;
        cout << x / 1000 << ".";
        if ((x / 10) % 100 < 10)
            cout << "0";
        cout << (x / 10) % 100 << "%" << endl;
//        cout << fixed << setprecision(2) << 100.0 * cand[i].votes / double(m) << "%" << endl;
    }
    int x = inv / double(m) * 100000;
    if (x % 10 >= 5) x += 10;
    cout << "Invalid " << x / 1000 << ".";
    if ((x / 10) % 100 < 10)
        cout << "0";
    cout << (x / 10) % 100 << "%" << endl;
//    cout << "Invalid " << fixed << setprecision(2) << 100.0 * inv / double(m) << "%" << endl;
}