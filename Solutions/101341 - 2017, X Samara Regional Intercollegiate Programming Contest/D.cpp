// 101341 - 2017, X Samara Regional Intercollegiate Programming Contest
// 101341D

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
const int di[] = { -1,0,1,0 };
const int dj[] = { 0,1,0,-1 };
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
#define mp make_pair

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int n, x; cin >> n >> x;
	vi num(n); int g;
	cin >> num[0]; g = num[0];
	for (int i = 1; i < n; i++) {
		cin >> num[i];
		g = gcd(g, num[i]);
	}
	cout << (abs(x) % g == 0 ? "YES" : "NO") << endl;
	//cin.ignore(), cin.get();
}
