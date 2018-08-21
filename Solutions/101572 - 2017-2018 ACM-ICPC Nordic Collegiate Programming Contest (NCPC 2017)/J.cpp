// 101572 - 2017-2018 ACM-ICPC Nordic Collegiate Programming Contest (NCPC 2017)
// 101572J

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
const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, 1, 0, -1 };
const ll MOD = 1e9 + 7;
const ll INF = 1e14;
const double EPS = 1e-5;
#define mp make_pair
#define all(x) x.begin(),x.end()

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int a, b; cin >> a >> b;
	if (a + b == 0) cout << "Not a moose\n";
	else if (a == b) cout << "Even " << a + b << endl;
	else cout << "Odd " << max(a, b) * 2 << endl;
	cin.ignore(), cin.get();
}
