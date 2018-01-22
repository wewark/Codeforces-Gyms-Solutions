#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
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
#define mp make_pair
#define all(x) x.begin(),x.end()

int n;
string s;

vll mem(1e5 + 5, -1);
ll solve(int idx) {
	if (idx == n) return 1;
	ll& r = mem[idx];
	if (~r) return r;
	r = 0;

	if (s[idx] == 'N' || s[idx] == 'E' || s[idx] == 'W' || s[idx] == 'S') {
		r += solve(idx + 1);
		r %= MOD;
	}
	if (idx < n - 1 &&
		(s[idx] == 'N' || s[idx] == 'S') &&
		(s[idx + 1] == 'W' || s[idx + 1] == 'E')) {
		r += solve(idx + 1);
		r %= MOD;
	}
	return r;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	cin >> s;
	n = s.length();
	cout << solve(0) << endl;
	cin.ignore(), cin.get();
}
