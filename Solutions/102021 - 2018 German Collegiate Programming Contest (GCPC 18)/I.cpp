// 2018 German Collegiate Programming Contest (GCPC 18)
// 102021I

#include <bits/stdc++.h>

using namespace std;

#define loop(i, n) for(int i = 0;i < int(n);i++)
#define rloop(i, n) for(int i = int(n);i >= 0;i--)
#define range(i, a, b) for(int i = int(a);i <= int(b);i++)
#define SZ(c) int(c.size())
#define ALL(c) c.begin(), c.end()
#define RALL(c) c.rbegin(), c.rend()
#define PI acos(-1)
#define pb push_back
#define mp make_pair
#define fr first
#define sc second


typedef vector<int> vi;
typedef vector<pair<int, int> > vii;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1005;
int n;
int a[N], b[N];

bool valid(int x) {
    loop(i, n) {
        if (a[i] + x > b[i])return true;
        else if (a[i] + x < b[i])return false;
    }
    return true;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    loop(i, n)cin >> a[i];
    loop(i, n)cin >> b[i];
    loop(i, N)
        if (valid(i)) {
            cout << i << endl;
            return 0;
        }


    return 0;
}
