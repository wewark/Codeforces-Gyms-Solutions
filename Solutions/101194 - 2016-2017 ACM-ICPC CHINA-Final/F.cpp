// 2016-2017 ACM-ICPC CHINA-Final
// 101194F

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<bool> vb;
typedef vector<string> vs;
const ll MOD = 1e9 + 7;
const long double EPS = 1e-5;
#define all(x) x.begin(),x.end()
#define SZ(x) (int)(x).size()

#include <ext/hash_set>
#include <ext/numeric>

#define  fr first
#define  sc second

class SparseTable
{
private:
	vi A;
	vvi st; // Sparse Table (N * log(N))

public:
	SparseTable() {}
	SparseTable(const vi& _A) {
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

SparseTable sparseTable;
const int siz = 4e6 + 3;
char s[siz];
// idx -> suffix position in the sorted order according to the current
// val -> start position of suffix inside the string
int suff[siz];
// idx -> start position of suffix inside the string
// val -> suffix order in the list of sorted suffixes according to the
int order[siz];
// idx -> position of suffix in the current "suff" array
// val -> suffix order in the list of sorted suffixes according to the
int newOrder[siz];
// idx -> value from "order"
// val -> idx in "suff"
int groupStart[siz];
// copy of "suff" but sorted 3la 2 * len
int newSuff[siz];
// meen el suffixes elli btebda2 bel 7arf da
int head[128], nxt[siz];
struct cmp {
	int len;
	cmp(int len) :
			len(len) { // Initialization list
	}
	bool operator ()(const int &a, const int &b) const {
		return order[a] < order[b]
		       || (order[a] == order[b] && order[a + len] < order[b + len]);
	}
};
void print(int *arr = { 0 }) {
	for (int i = 0; !i || s[i - 1]; i++)
		cout << (char*) (s + newSuff[i]) << endl;
	cout << endl;
}
int suffixArrays() {
	memset(head, -1, sizeof(head));
	int len = 0;
	for (; !len || s[len - 1]; len++) {
		nxt[len] = head[s[len]];
		head[s[len]] = len;
	}
	int ng = -1;
	for (int i = 0, j = 0; i < 128; i++) {
		int cur = head[i];
// combo loop
		for (cur != -1 && (groupStart[++ng] = j); cur != -1; cur =
				                                                     nxt[cur]) {
			suff[j++] = cur;
			order[cur] = ng;
		}
	}
	newSuff[0] = suff[0];
	newOrder[len - 1] = -1;
	for (int cur = 1; newOrder[len - 1] != len - 1; cur <<= 1) {
		cmp c(cur);
		for (int i = 0; i < len; i++) {
			int j = suff[i] - cur;
			if (j < 0)
				continue;
			newSuff[groupStart[order[j]]++] = j;
		}
		for (int i = 1; i < len; i++) {
			bool ngroup = c(newSuff[i - 1], newSuff[i]);
			newOrder[i] = newOrder[i - 1] + ngroup;
			if (ngroup)
				groupStart[newOrder[i]] = i;
		}
		for (int i = 0; i < len; i++)
			suff[i] = newSuff[i], order[suff[i]] = newOrder[i];
	}
	return len;
}

int lcp[siz];
void buildLCP(int n) {
	int cnt = 0;
	for (int i = 0; s[i]; i++) {
		int j = suff[order[i] - 1];
		while (s[i + cnt] == s[j + cnt])
			cnt++;
		lcp[order[i]] = cnt;
		if (cnt)
			cnt--;
	}
	vi v(lcp,lcp+n);
	sparseTable.build(v);
}


int LEN;
char in[siz];


void read() {
	int idx = 0 , N;
	scanf("%d", &N);
	scanf("%s", s);
//	for (int i = 0; i < 125000; ++i) {
//		s[i]='a';
//}
//	s[125000]=0;

	LEN = strlen(s);
	idx = LEN;
	for (int i = 1; i < N; i++) {
		scanf(" %s", in);
		int tmp = strlen(in);
		s[idx++] = '#';
		for (int j = 0; j < tmp; j++)
			s[idx++] = in[j];
	}
	s[idx] = 0;
}

int NXT[siz], prv[siz];
int idxInSuffix[siz];

pair<int, int> solve(int n) {
	prv[0] = -1;
	for (int i = 1; i < n; i++) {
		prv[i] = i - 1;
		while (prv[i] != -1 && suff[prv[i]] < LEN)
			prv[i] = prv[prv[i]];
	}

	NXT[n - 1] = n;
	for (int i = n - 2; ~i; i--) {
		NXT[i] = i + 1;
		while (NXT[i] != n && suff[NXT[i]] < LEN)
			NXT[i] = NXT[NXT[i]];
	}

	for (int i = 0; i < n; i++) {
		idxInSuffix[suff[i]] = i;
	}

	int idx = -1, len = INT_MAX;
	for (int i = 0; i < n; i++) {
		int mn1 = INT_MIN, mn2 = INT_MIN;
		if (suff[i] >= LEN)continue;
		int myidx = i;
		if (prv[myidx] != -1) {
			mn1 = sparseTable.rmq(prv[myidx] + 1, myidx);
//			cout << prv[myidx] + 1 << " " << myidx << " " << mn1 << endl;
		}
		if (NXT[myidx] != n)mn2 = sparseTable.rmq(myidx + 1, NXT[myidx]);
		int lengthSuffix = LEN - suff[i];
		int can = max(mn1, mn2) + 1;
//		cout << i << " " << myidx << " " << can << " " << lengthSuffix << " " << mn1 << " " << mn2 << endl;
		if (can > lengthSuffix)continue;
		if (can < len) {
			len = can;
			idx = suff[i];
		}
	}

	return {idx, len};
}


int main() {
//	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int t, cases = 1;

	scanf("%d", &t);
	while (t--) {
		read();
//		cout << str << endl;
		int n = suffixArrays();
		buildLCP(n);
//		for (int i = 0; i < n; i++)
//			cout << s + suff[i] << endl;
//		for (int i = 0; i < n; i++)
//			cout << lcp[i] << " ";
//		cout << endl;

		pii ans = solve(n);
//		cout << ans.first << "=============" << ans.second << endl;
		printf("Case #%d: ", cases++);
		if (ans.first == -1)puts("Impossible");
		else {
			for (int i = 0; i < ans.second; i++)
				putchar(s[ans.first + i]);
			putchar('\n');
		}
	}
	return 0;
}