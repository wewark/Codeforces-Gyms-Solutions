// 101798 - 2018 PSUT Coding Marathon
// 101798B

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
const int di[] = { 0, 1 };
const int dj[] = { 1, 0 };
const ll MOD = 1e9 + 9;
const ll INF = 1e9;
const long double EPS = 1e-7;
#define all(n) n.begin(),n.end()

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	string a, b; cin >> a >> b;
	int x = a.length();
	int y = b.length();

	if (x % 2 == 0 || y % 2 == 0 ||
		a[x / 2] == b[y / 2])
		cout << "YES\n";
	else
		cout << "NO\n";

	cin.ignore(), cin.get();
}
