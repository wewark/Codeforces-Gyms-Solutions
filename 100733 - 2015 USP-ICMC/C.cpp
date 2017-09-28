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

ll gcd(ll a, ll b) {
	return b == 0 ? a : gcd(b, a % b);
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	string n; cin >> n;
	long long t = 100;
	if (stoll(n) == 0) {
		cout << 0 << endl; return 0;
	}

	int c = 0;
	while (c < n.length() && n[c] != '.') c++;
	if (c < n.length()) n.erase(n.begin() + c);

	for (int i = c; i < n.length(); i++)
		t *= 10;
	cout << t / gcd(stoll(n), t) << endl;
	cin.ignore(), cin.get();
}
