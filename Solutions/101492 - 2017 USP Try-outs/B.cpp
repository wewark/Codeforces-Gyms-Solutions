// 101492 - 2017 USP Try-outs
// 101492B

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<ll, ll> pii;
typedef vector<pii> vii;
typedef vector<bool> vb;
typedef vector<string> vs;
const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, 1, 0, -1 };
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const double EPS = 1e-5;
#define mp make_pair
#define all(pt) pt.begin(),pt.end()

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	ll n; cin >> n;
	ll sum = n * (n + 1) / 2;

	if (sum % 2 == 1) {
		cout << -1 << endl; return 0;
	}
	sum /= 2;

	vector<char> r(n, '-');
	for (int i = n; i > 0; i--)
		if (sum >= i) {
			sum -= i;
			r[i - 1] = '+';
		}

	for (int i = 0; i < n; i++)
		cout << r[i];
	cout << endl;
	//cin.ignore(), cin.get();
}
