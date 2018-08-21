// 101243 - 2016-2017 ACM-ICPC, NEERC, Central Subregional Contest
// 101243H

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

vll mem(105, -1);
ll solve(int idx) {
	if (idx == min(9, n)) return 1;
	ll& ret = mem[idx];
	if (~ret) return ret;
	ret = solve(idx + 1) * (9 - (idx == 0));
	return ret;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	cin >> n;
	ll r = solve(0);
	string s = to_string(r);
	if (n > 9)
		s += string(n - 9, '0');
	cout << s << endl;
	//cin.ignore(), cin.get();
}
