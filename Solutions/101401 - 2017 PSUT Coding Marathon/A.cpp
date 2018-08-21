// 101401 - 2017 PSUT Coding Marathon
// 101401A

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
const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, 1, 0, -1 };
const ll MOD = 1e9 + 7;
const ll INF = 1e11;
const double EPS = 1e-11;
#define mp make_pair
#define all(x) x.begin(),x.end()

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int a, b, c; cin >> a >> b >> c;
	int r = 0;
	r += min(b, c);
	c -= r;
	r += min(c, a / 2);
	cout << r << endl;
}
