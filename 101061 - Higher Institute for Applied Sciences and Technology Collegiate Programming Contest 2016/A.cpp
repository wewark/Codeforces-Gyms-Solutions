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
const ll INF = 1e10;
const double EPS = 1e-10;
#define mp make_pair
#define all(x) x.begin(),x.end()

int box(ll n) {
	if (n % 2 == 1) return 1;
	if (box(n / 2) == 1) return 2;
	else return 1;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int t; cin >> t;
	while (t--) {
		ll n; cin >> n;
		cout << (box(n) == 1 ? "First Box" : "Second Box") << endl;
	}
	cin.ignore(), cin.get();
}
