// 2018 USP Try-outs
// 101879E

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
const int di[] = { 0, 0, 1, -1 };
const int dj[] = { 1, -1, 0, 0 };
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const long double EPS = 1e-6;
#define all(x) x.begin(),x.end()
#define fr first
#define sc second

ll C[50][50];

void initC() {
	for (int i = 1; i < 50; i++) {
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; j++)
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]);
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	initC();
	int n; cin >> n;
	ll r = 0;
	for (int i = 2; i <= n; i++) {
		r += C[n][i];
	}
	cout << r << endl;
}
