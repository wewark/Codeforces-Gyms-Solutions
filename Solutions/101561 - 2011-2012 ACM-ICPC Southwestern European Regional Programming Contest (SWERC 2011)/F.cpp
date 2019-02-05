// 2011-2012 ACM-ICPC Southwestern European Regional Programming Contest (SWERC 2011)
// 101561F

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
#define sfi1(v) scanf("%d",&v)
#define sfi2(v1, v2) scanf("%d %d",&v1,&v2)
#define sfi3(v1, v2, v3) scanf("%d %d %d",&v1,&v2,&v3)
#define sfll1(v) scanf("%I64d",&v);
#define sfll2(v1, v2) scanf("%I64d %I64d",&v1,&v2)
#define sfll3(v1, v2, v3) scanf("%I64d %I64d %I64d",&v1,&v2,&v3)

typedef vector<int> vi;
typedef vector<pair<int, int> > vii;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1000;
int arr[N];
int opp[N];
map<char, int> m;
int n, res, id;
string str;

int solve(int s, int e) {
    if (s == e) return arr[m[str[s]]];
    vi v;
    vector<char> op, op2;
    while (s <= e) {
        int cur;
        if (str[s] == '(') {
            cur = solve(s + 1, opp[s] - 1);
            v.push_back(cur);
            s = opp[s] + 1;
        } else if (isalpha(str[s])) {
            cur = arr[m[str[s]]];
            v.push_back(cur);
            s++;
        } else {
            op.push_back(str[s]);
            s++;
        }
    }

    vi add;
    add.pb(v.front());
    range(i, 1, SZ(v) - 1) {
        if (op[i - 1] == '*') {
            int cur = add.back();
            add.pop_back();
            cur *= v[i];
            add.push_back(cur);
        } else {
            add.push_back(v[i]);
            op2.push_back(op[i - 1]);
        }
    }

    int ret = add.front();
    range(i, 1, SZ(add) - 1) {
        if (op[i - 1] == '+') {
            ret += add[i];
        } else {
            ret -= add[i];
        }
    }

    return ret;
}

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("out.in", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while (cin >> n) {
        if (!n)return 0;
        m.clear();
        id = 0;

        loop(i, n)cin >> arr[i];
        cin >> res >> str;

        stack<int> st;
        loop(i, SZ(str)) {
            if (str[i] == '(') {
                st.push(i);
            } else if (str[i] == ')') {
                opp[st.top()] = i;
                opp[i] = st.top();
                st.pop();
            } else if (str[i] == '*' || str[i] == '+' || str[i] == '-') {

            } else {
                m[str[i]] = id++;
            }
        }


        sort(arr, arr + n);

        bool flag = false;
        do {
            if (solve(0, SZ(str) - 1) == res) {
                flag = true;
                break;
            }
        } while (next_permutation(arr, arr + n));

        if (flag)
            cout << "YES\n";
        else
            cout << "NO\n";

    }
    return 0;
}
