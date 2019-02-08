// 2018-2019 ACM-ICPC Asia Seoul Regional Contest
// 101987F

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

const string oo = "+-*/%";

string t, s, p;
int n, a;

bool isop(char c) {
	return oo.find(c) != -1;
}

bool validPar() {
	int cnt = 0;
	for (char c : p) {
		if (c == ')') {
			if (!cnt)
				return 0;
			cnt--;
		} else {
			cnt++;
		}
	}
	return cnt == 0;
}

int main() {
//	ios::sync_with_stdio(false), cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	getline(cin, t);
	for (char c : t) {
		if (c == ' ') continue;
		n++;
		s += c;
		if (c == '(' || c == ')')
			p += c;
		if (isalpha(c))
			a++;
	}
	if (!validPar()) {
		puts("error");
		return 0;
	}
	for (int i = 0; i < n; i++) {
		if (isop(s[i])) {
			if (i == 0 || i == n - 1) {
				puts("error");
				return 0;
			}
			if (!isalpha(s[i - 1]) && s[i - 1] != ')') {
				puts("error");
				return 0;
			}
			if (!isalpha(s[i + 1]) && s[i + 1] != '(') {
				puts("error");
				return 0;
			}
		} else if (s[i] == '(') {
			if (i && isalpha(s[i - 1])) {
				puts("error");
				return 0;
			}
		} else if (s[i] == ')') {
			if (i < n - 1 && isalpha(s[i + 1])) {
				puts("error");
				return 0;
			}
		} else {
			if (i && s[i - 1] != '(' && !isop(s[i - 1])) {
				puts("error");
				return 0;
			}
			if (i < n - 1 && s[i + 1] != ')' && !isop(s[i + 1])) {
				puts("error");
				return 0;
			}
		}
	}
	if (s.find("()") != -1) {
		puts("error");
		return 0;
	}
	if (sz(p) / 2 != a - 2) {
		puts("improper");
		return 0;
	}
	string stk;
	for (auto c : s) {
		stk += c;
		int sz = sz(stk);
		if (stk.back() == ')') {
			if (sz > 4 && isalpha(stk[sz - 2]) && isop(stk[sz - 3]) && isalpha(stk[sz - 4]) && stk[sz - 5] == '(') {
				for (int i = 0; i < 5; i++)
					stk.pop_back();
				stk += 'z';
			} else {
				puts("improper");
				return 0;
			}
		}
	}
	if (sz(stk) == 3) {
		puts("proper");
		return 0;
	} else {
		assert(0);
	}
	return 0;
}
