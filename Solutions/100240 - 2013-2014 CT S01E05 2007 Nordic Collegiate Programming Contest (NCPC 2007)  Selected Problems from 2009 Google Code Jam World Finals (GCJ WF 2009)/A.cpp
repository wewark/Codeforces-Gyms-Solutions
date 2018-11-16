// 2013-2014 CT S01E05 2007 Nordic Collegiate Programming Contest (NCPC 2007)  Selected Problems from 2009 Google Code Jam World Finals (GCJ WF 2009)
// 100240A

#include <bits/stdc++.h>
#include <ext/hash_set>
#include <ext/numeric>

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
#define SZ(x) (int)x.size()

const int N = 2e5 + 5;

int trie[N][10];
bool isEnd[N];
char s[11];
int nodeCnt;

void init() {
	memset(trie, -1, sizeof trie);
	memset(isEnd, 0, sizeof isEnd);
	nodeCnt = 1;
}

bool ok;

void insert(const char *s) {
	int cur = 0;
	for (; *s; s++) {
		int &nxt = trie[cur][*s - '0'];
		if (nxt == -1)
			nxt = nodeCnt++;
		if (isEnd[nxt]) {
			ok = 1;
		}
		cur = nxt;
	}
	isEnd[cur] = 1;
}

string a[N];

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int t , n;
	cin >> t;
	while(t--){
		cin >> n;
		init();
		ok = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a, a + n, [](const string &x, const string &y) {
			return SZ(x) < SZ(y);
		});
		for (int i = 0; i < n; i++) {
			insert(a[i].c_str());
		}
		!ok ? puts("YES") : puts("NO");
	}
}