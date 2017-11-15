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
const ll INF = 1e9;
const double EPS = 1e-5;
#define mp make_pair
#define all(x) x.begin(),x.end()

ll n, d;
vll num;

bool valid(ll x) {
	vll tmp = num;
	tmp[0] += x * d;
	int a = 1;
	for (; a < n; a++) {
		ll diff = tmp[a - 1] - tmp[a];
		if (diff <= 0) {
			diff = -diff;
			ll steps = min(x, diff / d + 1);
			steps += (x - steps) % 2;
			tmp[a] -= steps * d;
		}
		else {
			diff--;
			ll steps = min(x, diff / d);
			steps -= (x - steps) % 2;
			tmp[a] += steps * d;
		}
	}

	//int b = n - 2;
	//if (a < n - 1)
	//	tmp.back() -= x * d;
	//for (; b >= 0 && b > a; b--) {

	//	ll diff = tmp[b] - tmp[b + 1];
	//	diff--;
	//	if (diff < 0) break;
	//	ll steps = min(x, diff / d);
	//	steps -= (x - steps) % 2;
	//	tmp[b] -= steps * d;
	//}

	for (int i = 0; i < n - 1; i++)
		if (tmp[i] <= tmp[i + 1])
			return false;
	return true;
}

ll bs() {
	ll a = 0, b = (LLONG_MAX - 1e9) / 1e9, mid = (a + b) / 2;
	while (a < b) {
		if (valid(mid))
			b = mid;
		else
			a = mid + 1;
		mid = (a + b) / 2;
	}
	return mid;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> d;
	num.resize(n);
	for (int i = 0; i < n; i++)
		cin >> num[i];
	cout << bs() << endl;
	cin.ignore(), cin.get();
}