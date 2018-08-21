#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<ll, ll> pii;
typedef vector<pii> vii;
typedef vector<bool> vb;
typedef vector<string> vs;
const int di[] = { 0, 0, 1, -1 };
const int dj[] = { 1, -1, 0, 0 };
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const long double EPS = 1e-6;
#define all(x) x.begin(),x.end()

int n;
vi num;

vll mem(4e5, -1);
ll solve(int idx) {
	if (idx >= n) return 0;
	ll& ret = mem[idx];
	if (~ret) return ret;
	ret = 0;

	ll a = -2, b = -2;
	if (idx + 1 < n && num[idx + 1] - num[idx] < 2000 &&
		(idx + 2 >= n || num[idx + 2] - num[idx + 1] > 1000))
		a = solve(idx + 2);

	if (idx + 2 < n && num[idx + 1] - num[idx] < 2000 &&
		num[idx + 2] - num[idx + 1] < 2000 &&
		(idx + 3 >= n || num[idx + 3] - num[idx + 2] > 1000))
		b = solve(idx + 3);

	if (a == -3 || b == -3) ret = -3;
	else if (a == -2 && b == -2) ret = -2;
	else if (a == -2) ret = b + 1;
	else if (b == -2) ret = a;
	else if (a == b + 1) ret = a;
	else ret = -3;

	return ret;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n;
	num.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	ll tr = solve(0);
	if (tr == -3)
		cout << "Ambiguous" << endl;
	else if (tr == -2)
		cout << "Impossible" << endl;
	else {
		cout << "Cars without trailers: " << (n - tr * 3) / 2 << endl;
		cout << "Cars with trailers: " << tr << endl;
	}
	cin.ignore(), cin.get();
}