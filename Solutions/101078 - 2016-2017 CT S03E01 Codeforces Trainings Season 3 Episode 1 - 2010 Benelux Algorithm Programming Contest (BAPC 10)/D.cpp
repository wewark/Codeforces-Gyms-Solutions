// 2016-2017 CT S03E01 Codeforces Trainings Season 3 Episode 1 - 2010 Benelux Algorithm Programming Contest (BAPC 10)
// 101078D

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
const int di[] = { 0,0,1,-1 };
const int dj[] = { 1,-1,0,0 };
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const long double EPS = 1e-9;
#define all(x) x.begin(),x.end()

inline int odd(int a, int b) {
	return (b - a + 1 + (a % 2)) / 2;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		cout << n - n / 2 + odd((n - 1) / 3 + 1, n) << endl;
	}
}
