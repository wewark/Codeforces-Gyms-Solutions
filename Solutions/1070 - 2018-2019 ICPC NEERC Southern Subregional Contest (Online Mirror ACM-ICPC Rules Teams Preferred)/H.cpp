// 2018-2019 ICPC NEERC Southern Subregional Contest (Online Mirror ACM-ICPC Rules Teams Preferred)
// 1070H

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

const int N = 10005;
char str[N][10];
char pat[10];
int n, q;
map<string, int> m[10];
map<string, int> idx[10];

int main() {
//	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", str[i]);
		string s = string(str[i]), cur;
		set<string> SET;
		for (int len = SZ(s); len; len--) {
			for (int k = 0; k + len <= SZ(s); k++) {
				cur = s.substr(k, len);
				if (SET.find(cur) != SET.end())continue;
				SET.insert(cur);
				m[len][cur]++;
				idx[len][cur] = i;
			}
		}
	}

	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		scanf("%s", pat);
		string cur = pat;
		if (m[SZ(cur)].find(cur) != m[SZ(cur)].end()) {
			printf("%d %s\n", m[SZ(cur)][cur], str[idx[SZ(cur)][cur]]);
		}
		else {
			puts("0 -");
		}
	}


	return 0;
}