// 2012-2013 ACM-ICPC Central Europe Regional Contest (CERC 12)
// 100624E

#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ll;
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

const int N = 505;

string res[N];
map<string, int> M;
pii eq[N];
string p;
bool ok[N];

int match(int j, int idx) {
	int cnt = 0;
	for (int i = 0; i < SZ(res[idx]) && j < SZ(p); i++) {
		if (res[idx][i] == p[j])
			j++, cnt++;
	}
	return cnt;
}

int cnt;

int get(const string &s) {
	if (M.find(s) == M.end())
		return M[s] = cnt++;
	return M[s];
}

int vis[2002][N];
int dp[2002][N];
int vid;

int solve(int idx, int sym) {
//	cout << idx << " " << sym << endl;
	if (idx >= SZ(p))
		return 0;
	int &ret = dp[idx][sym];
	if (vis[idx][sym] == vid)
		return ret;
	ret = 0;
	vis[idx][sym] = vid;
	if (ok[sym]) {
		return ret = match(idx, sym);
	}
	pii nxt = eq[sym];
	int c1 = solve(idx, nxt.first);
	int c2 = solve(idx + c1, nxt.second);
	return ret = c1 + c2;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string symbol, s1, s2;
		char ch;
		M.clear();
		cnt = 0;
		memset(ok, 0, sizeof ok);
		for (int i = 0; i < n; i++) {
			cin >> symbol >> ch >> s1;
			if (islower(s1[0])) {
				res[get(symbol)] = s1;
				ok[get(symbol)] = 1;
			} else {
				cin >> ch >> s2;
				eq[get(symbol)] = {get(s1), get(s2)};
			}
		}
		cin >> symbol >> p;
		vid++;
		if (solve(0, get(symbol)) >= SZ(p))
			puts("YES");
		else
			puts("NO");
	}

	return 0;
}
