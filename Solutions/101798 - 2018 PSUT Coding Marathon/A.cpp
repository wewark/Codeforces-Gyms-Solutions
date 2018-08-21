// 101798 - 2018 PSUT Coding Marathon
// 101798A

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
	int d, w, m; cin >> d >> w >> m;
	if (d >= w + m || d < w)
		cout << "good luck\n";
	else
		cout << "see you next semester\n";
	cin.ignore(), cin.get();
}
