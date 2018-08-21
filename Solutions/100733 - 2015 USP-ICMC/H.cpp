// 100733 - 2015 USP-ICMC
// 100733H

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<pair<int, int>, int> pii;
typedef vector<pii> vii;
typedef vector<bool> vb;
typedef vector<string> vs;
const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, 1, 0, -1 };
const ll MOD = 1e9 + 7;
const ll INF = 1e10;
const double EPS = 1e-5;
#define mp make_pair
#define all(x) x.begin(),x.end()

string s;
int dist[26][26];

void floyd() {
	for (int k = 0; k < 26; k++)
		for (int i = 0; i < 26; i++)
			for (int j = 0; j < 26; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
	for (int i = 0; i < 26; i++)
		dist[i][i] = 0;
}

vll mem(1e6 + 1, -1);
ll solve(int idx) {
	int other = (int)s.length() - 1 - idx;
	if (idx >= other) return 0;
	if (mem[idx] != -1) return mem[idx];

	int ret = 1e6;
	for (int i = 0; i < 26; i++)
		ret = min(ret, dist[s[idx] - 'a'][i] + dist[s[other] - 'a'][i]);

	return mem[idx] = ret + solve(idx + 1);
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	for (int i = 0; i < 26; i++)
		for (int j = 0; j < 26; j++)
			cin >> dist[i][j];
	cin >> s;
	floyd();
	cout << solve(0) << endl;
	cin.ignore(), cin.get();
}
