// 2018-2019 ACM-ICPC Asia Seoul Regional Contest
// 101987K

#include <bits/stdc++.h>
#include <ext/hash_set>
#include <ext/numeric>

using namespace __gnu_cxx;
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;
using vb = vector<bool>;
using vs = vector<string>;
const int MOD = int(1e9 + 7);
const long double EPS = 1e-4;
const double PI = 3.1415926535897932384626433;
const ll INF = ll(1e9);
int di[] = {0, 0, 0, 1, -1, 1, -1, 1, -1};
int dj[] = {0, 1, -1, 0, 0, 1, -1, -1, 1};
#define all(x) x.begin(),x.end()

#define FOR(i, a, b) for(int i=(a);i<(b);i++)
#define pb push_back
#define sz(v) (int)v.size()
#define all(c) (c).begin(),(c).end()
#define mem(s, v) memset(s,v,sizeof(s))
typedef vector<int> vi;

const int MAX = 2e4 + 4, MAXE = 3e6 + 6;
int n;
int head[MAX], nxt[MAXE], to[MAXE];
int edgeCount;

void init() {
	edgeCount = 0;
	memset(head, -1, sizeof(head));
}

void addEdge(int f, int t) {
//	cout << f << " " << t << endl;
	nxt[edgeCount] = head[f];
	head[f] = edgeCount;
	to[edgeCount++] = t;
}

int low[MAX], tim[MAX], curtime;
int stk[MAX], stksz;
int compId[MAX], compnum;

void tarjanDFS(int cur) {
	low[cur] = tim[cur] = curtime++;
	stk[stksz++] = cur;
	for (int i = head[cur]; i != -1; i = nxt[i]) {
		int j = to[i];
		if (compId[j] == -1) {
			if (tim[j] == -1)
				tarjanDFS(j);
			low[cur] = min(low[cur], low[j]);
		}
	}
	if (low[cur] == tim[cur]) {
		do {
			compId[stk[stksz - 1]] = compnum;
		} while (stk[--stksz] != cur);
		compnum++;
	}
}

void SCC() {
	compnum = 0;
	curtime = 0;
	memset(compId, -1, sizeof(compId));
	memset(tim, -1, sizeof(tim));
	for (int i = 0; i < n; i++) {
		if (tim[i] == -1)
			tarjanDFS(i);
	}
}

int nodeID(int cur) {
	return 2 * cur;
}

int NOT(int cur) {
	return cur ^ 1;
}

void addOR(int i, int j) {
	addEdge(NOT(i), j);
	addEdge(NOT(j), i);
}

int invComp[MAX], sortedOrder[MAX], in[MAX], sorSize;
vector<vi> adjComp;
int compres[MAX], visComp[MAX];

void dfs(int u) {
	if (visComp[u])return;
	visComp[u] = true;
	for (int nxt : adjComp[u]) {
		dfs(nxt);
	}

	if (compres[u] == -1) {
		compres[u] = 1;
		int invID = invComp[u];
		compres[invID] = 0;
	}
}

void assign() {
	mem(compres, -1);
	mem(in, 0), sorSize = 0;
	FOR (i, 0, sz(adjComp)) FOR (k, 0, sz(adjComp[i])) in[adjComp[i][k]]++;
//	queue<int> q;
	FOR (i, 0, sz(adjComp)) if (!in[i])
			dfs(i);
}


bool _2sat() {
	SCC();
	FOR (i, 0, ::n / 2) {
		if (compId[nodeID(i)] == compId[NOT(nodeID(i))])
			return false;
		invComp[compId[nodeID(i)]] = compId[NOT(nodeID(i))];
		invComp[compId[NOT(nodeID(i))]] = compId[nodeID(i)];
	}
	adjComp.clear(), adjComp.resize(compnum);
	FOR (ii, 0, ::n) {
		for (int kk = head[ii]; kk != -1; kk = nxt[kk]) {
			int jj = to[kk];
			int i = compId[ii], j = compId[jj];
			if (i == j)
				continue;
			adjComp[i].pb(j);
		}
	}

	assign();
//	FOR (i, 0, sorSize) {
//		int id = sortedOrder[i];
//		if (compres[id] != -1)
//			continue;
//		int invID = invComp[id];
//		compres[id] = 0, compres[invID] = 1;
//	}
	return true;
}

string ans;
pair<int, char> arr[MAX][3];

bool check() {
	for (int i = 0; i < n; i++) {
		int c = 0;
		for (int j = 0; j < 3; j++) {
			c += (ans[arr[i][j].first] == arr[i][j].second);
		}
		if (c <= 1)return false;
	}
	return true;
}


int main() {
//	ios::sync_with_stdio(false), cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	init();
	int stu;
	scanf("%d%d", &n, &stu);
	for (int i = 0; i < stu; i++) {
		for (int j = 0; j < 3; j++) {
			scanf(" %d %c", &arr[i][j].first, &arr[i][j].second);
			arr[i][j].first--;
			for (int k = 0; k < j; k++) {
				int a = nodeID(arr[i][j].first);
				if (arr[i][j].second == 'B') a = NOT(a);
				int b = nodeID(arr[i][k].first);
				if (arr[i][k].second == 'B') b = NOT(b);
				addOR(a, b);
			}
		}
	}

	n <<= 1;

	if (!_2sat()) {
		cout << -1 << "\n";
	}
	else {
		n >>= 1;
		for (int i = 0; i < n; i++) {
			int ii = compId[nodeID(i)];
			bool flag = compres[ii];
			if (flag)ans += 'R';
			else ans += 'B';
			printf("%c", flag ? 'R' : 'B');
		}
		printf("\n");
//		assert(check());
	}

	return 0;
}
