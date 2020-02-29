// 2019-2020 ACM-ICPC Latin American Regional Programming Contest
// 102428G

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vs = vector<string>;
const int INF = 1e9;
const ll MOD = 1e9 + 7;
#define all(x) x.begin(),x.end()

typedef pair<int, int> ii;

#define MAX_N 800000                         // second approach: O(n log n)
char T[MAX_N];                   // the input string, up to 100K characters
int n;                                        // the length of input string
int RA[MAX_N], tempRA[MAX_N];        // rank array and temporary rank array
int SA[MAX_N], tempSA[MAX_N];    // suffix array and temporary suffix array
int c[MAX_N];                                    // for counting/radix sort

char P[MAX_N];                  // the pattern string (for string matching)
int m;                                      // the length of pattern string

int Phi[MAX_N];                      // for computing longest common prefix
int PLCP[MAX_N];
int LCP[MAX_N];  // LCP[i] stores the LCP between previous suffix T+SA[i-1]
// and current suffix T+SA[i]

void countingSort(int k) {                                          // O(n)
    int i, sum, maxi = max(300, n);   // up to 255 ASCII chars or length of n
    memset(c, 0, sizeof c);                          // clear frequency table
    for (i = 0; i < n; i++)       // count the frequency of each integer rank
        c[i + k < n ? RA[i + k] : 0]++;
    for (i = sum = 0; i < maxi; i++) {
        int t = c[i]; c[i] = sum; sum += t;
    }
    for (i = 0; i < n; i++)          // shuffle the suffix array if necessary
        tempSA[c[SA[i]+k < n ? RA[SA[i]+k] : 0]++] = SA[i];
    for (i = 0; i < n; i++)                     // update the suffix array SA
        SA[i] = tempSA[i];
}

void constructSA() {         // this version can go up to 100000 characters
    int i, k, r;
    for (i = 0; i < n; i++) RA[i] = T[i];                 // initial rankings
    for (i = 0; i < n; i++) SA[i] = i;     // initial SA: {0, 1, 2, ..., n-1}
    for (k = 1; k < n; k <<= 1) {       // repeat sorting process log n times
        countingSort(k);  // actually radix sort: sort based on the second item
        countingSort(0);          // then (stable) sort based on the first item
        tempRA[SA[0]] = r = 0;             // re-ranking; start from rank r = 0
        for (i = 1; i < n; i++)                    // compare adjacent suffixes
            tempRA[SA[i]] = // if same pair => same rank r; otherwise, increase r
                    (RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+k] == RA[SA[i-1]+k]) ? r : ++r;
        for (i = 0; i < n; i++)                     // update the rank array RA
            RA[i] = tempRA[i];
        if (RA[SA[n-1]] == n-1) break;               // nice optimization trick
    } }

void computeLCP() {
    int i, L;
    Phi[SA[0]] = -1;                                         // default value
    for (i = 1; i < n; i++)                            // compute Phi in O(n)
        Phi[SA[i]] = SA[i-1];    // remember which suffix is behind this suffix
    for (i = L = 0; i < n; i++) {             // compute Permuted LCP in O(n)
        if (Phi[i] == -1) { PLCP[i] = 0; continue; }            // special case
        while (T[i + L] == T[Phi[i] + L]) L++;       // L increased max n times
        PLCP[i] = L;
        L = max(L-1, 0);                             // L decreased max n times
    }
    for (i = 0; i < n; i++)                            // compute LCP in O(n)
        LCP[i] = PLCP[SA[i]];   // put the permuted LCP to the correct position
}


class SparseTable
{
private:
    vi A;
    vvi st; // Sparse Table (N * log(N))

public:
    SparseTable() = default;
    explicit SparseTable(const vi& _A) {
        build(_A);
    }

    void build(const vi& _A) {
        st.assign(_A.size(), vi(log2(_A.size()) + 1));
        A = _A;

        int i, j;
        // initialize st for the intervals with length 1
        for (i = 0; i < A.size(); i++)
            st[i][0] = i;
        //compute values from smaller to bigger intervals
        for (j = 1; (1 << j) <= A.size(); j++)
            for (i = 0; i + (1 << j) - 1 < A.size(); i++)
                if (A[st[i][j - 1]] < A[st[i + (1 << (j - 1))][j - 1]])
                    st[i][j] = st[i][j - 1];
                else
                    st[i][j] = st[i + (1 << (j - 1))][j - 1];
    }

    int rmq(int i, int j) {
        int k = log2(j - i + 1);
        if (A[st[i][k]] <= A[st[j - (1 << k) + 1][k]])
            return A[st[i][k]];
        else
            return A[st[j - (1 << k) + 1][k]];
    }
};



int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    string s; cin >> s;
    int sl = s.length();
    int m; cin >> m;
    vs w(m);
    for (int i = 0; i < m; ++i) {
        cin >> w[i];
        s += "$" + w[i];
    }

    strcpy(T, s.c_str());
    n = s.length();
    constructSA();
    computeLCP();

//    cout << s << endl;
//    for (int i = 0; i < n; ++i) {
//        cout << LCP[i] << " " << s.substr(SA[i]) << endl;
//    }

    vi idxSA(n), nxt(n), prv(n);
    int cprv = -1;
    for (int i = 0; i < n; ++i) {
        idxSA[SA[i]] = i;
        if (SA[i] < sl)
            cprv = i;
        prv[i] = cprv;
    }
    int cnxt = -1;
    for (int i = n - 1; i >= 0; --i) {
        if (SA[i] < sl)
            cnxt = i;
        nxt[i] = cnxt;
    }


    vi LCPv;
    LCPv.insert(LCPv.begin(), LCP, LCP + n);
    SparseTable spt(LCPv);

    int bf = sl + 1;
    vi ans(m);
    for (int i = 0; i < m; ++i) {
        int a = bf;
        while (a < bf + w[i].length()) {
            int sz = 0;
            int ai = idxSA[a];
            if (prv[ai] != -1)
                sz = spt.rmq(prv[ai] + 1, ai);
            if (nxt[ai] != -1)
                sz = max(sz, spt.rmq(ai + 1, nxt[ai]));
            ans[i]++;
            a += sz;
            if (sz == 0) {
                ans[i] = -1;
                break;
            }
        }
        bf += w[i].length() + 1;

        cout << ans[i] << endl;
    }
}
