// 101755 - 2018, XI Samara Regional Intercollegiate Programming Contest
// 101755M

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
const int di[] = { -1, 0, 1, 0, -1, 1, 1, -1 };
const int dj[] = { 0, 1, 0, -1, -1, 1, -1, 1 };
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const long double EPS = 1e-10;
#define all(n) n.begin(),n.end()

int n;
string a, b, c;

int mem[200005][10];
int solve(int idx, int msk) {
	if (idx == n) return 1;
	int& ret = mem[idx][msk];
	if (~ret) return ret;
	ret = 0;

	if (a[idx] != b[idx] && a[idx] != c[idx] && b[idx] != c[idx]) {
		if (msk == 0) {
			ret = solve(idx + 1, 7);
			if (ret) ret = 2;
		}

		if (!(msk & 6)) // 00x
			ret += solve(idx + 1, msk | 6);
		if (!(msk & 3)) // x00
			ret += solve(idx + 1, msk | 3);
		if (!(msk & 5)) // 0x0
			ret += solve(idx + 1, msk | 5);
	}
	if (a[idx] == b[idx] && a[idx] == c[idx]) { // 111
		ret += solve(idx + 1, msk);
		if (msk == 0)
			ret += solve(idx + 1, 7);
	}
	else if (a[idx] == b[idx] && a[idx] != c[idx]) { // 001
		if (!(msk & 1)) // xx0
			ret += solve(idx + 1, msk | 1);
		if (!(msk & 6)) // 00x
			ret += solve(idx + 1, msk | 6);
	}
	else if (b[idx] == c[idx] && c[idx] != a[idx]) { // 011
		if (!(msk & 3)) // x00
			ret += solve(idx + 1, msk | 3);
		if (!(msk & 4)) // 0xx
			ret += solve(idx + 1, msk | 4);
	}
	else if (a[idx] == c[idx] && a[idx] != b[idx]) { // 010
		if (!(msk & 5)) // 0x0
			ret += solve(idx + 1, msk | 5);
		if (!(msk & 2)) // x0x
			ret += solve(idx + 1, msk | 2);
	}

	ret = min(2, ret);
	return ret;
}

string s = "";
void build(int idx, int msk) {
	if (idx == n) return;
	int ret = 0, nxtmsk = -1;
	char nxtc = '-';

	if (a[idx] != b[idx] && a[idx] != c[idx] && b[idx] != c[idx]) {
		if (!(msk & 6)) {// 00x
			if (!ret) nxtmsk = 6, nxtc = c[idx];
			ret += solve(idx + 1, msk | 6);
		}
		if (!(msk & 3)) {// x00
			if (!ret) nxtmsk = 3, nxtc = a[idx];
			ret += solve(idx + 1, msk | 3);
		}
		if (!(msk & 5)) {// 0x0
			if (!ret) nxtmsk = 5, nxtc = b[idx];
			ret += solve(idx + 1, msk | 5);
		}
	}
	if (a[idx] == b[idx] && a[idx] == c[idx]) { // 111
		if (!ret) nxtmsk = 0, nxtc = a[idx];
		ret += solve(idx + 1, msk);
		if (!ret) nxtmsk = 7, nxtc = a[idx];
		ret += solve(idx + 1, 7);
	}
	else if (a[idx] == b[idx] && a[idx] != c[idx]) { // 001
		if (!(msk & 1)) { // xx0
			if (!ret) nxtmsk = 1, nxtc = a[idx];
			ret += solve(idx + 1, msk | 1);
		}
		if (!(msk & 6)) { // 00x
			if (!ret) nxtmsk = 6, nxtc = c[idx];
			ret += solve(idx + 1, msk | 6);
		}
	}
	else if (b[idx] == c[idx] && c[idx] != a[idx]) { // 011
		if (!(msk & 3)) {// x00
			if (!ret) nxtmsk = 3, nxtc = a[idx];
			ret += solve(idx + 1, msk | 3);
		}
		if (!(msk & 4)) {// 0xx
			if (!ret) nxtmsk = 4, nxtc = b[idx];
			ret += solve(idx + 1, msk | 4);
		}
	}
	else if (a[idx] == c[idx] && a[idx] != b[idx]) { // 010
		if (!(msk & 5)) {// 0x0
			if (!ret) nxtmsk = 5, nxtc = b[idx];
			ret += solve(idx + 1, msk | 5);
		}
		if (!(msk & 2)) {// x0x
			if (!ret) nxtmsk = 2, nxtc = a[idx];
			ret += solve(idx + 1, msk | 2);
		}
	}

	s[idx] = nxtc;
	build(idx + 1, msk | nxtmsk);
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	memset(mem, -1, sizeof mem);
	cin >> a >> b >> c;
	n = a.length();

	if (solve(0, 0) == 1) {
		s = string(n, '-');
		build(0, 0);
		cout << s << endl;
	}
	else if (solve(0, 0) > 1)
		cout << "Ambiguous\n";
	else
		cout << "Impossible\n";
	cin.ignore(), cin.get();
}
