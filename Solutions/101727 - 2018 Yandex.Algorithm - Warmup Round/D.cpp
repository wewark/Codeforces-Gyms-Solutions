// 101727 - 2018 Yandex.Algorithm - Warmup Round
// 101727D

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
const int di[] = { -1, 0, 1, 0, -1, 1, 1, -1 };
const int dj[] = { 0, 1, 0, -1, -1, 1, -1, 1 };
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const long double EPS = 1e-9;
#define all(x) x.begin(),x.end()

ll phi(ll n) {
	ll ret = n;
	if (n % 2 == 0) {
		while (n % 2 == 0)
			n /= 2;
		ret -= ret / 2;
	}

	for (ll p = 3; p * p <= n; p += 2) {
		if (n % p == 0) {
			while (n % p == 0)
				n /= p;
			ret -= ret / p;
		}
	}

	if (n > 1) ret -= ret / n;
	return ret;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	ll n; cin >> n;
	cout << (n == 1 ? 2 : phi(n)) << endl;

	//vi v = { 1,1 };
	//for (int i = 0; i < 30; i++) {
	//	vi tmp;
	//	for (int j = 0; j < v.size() - 1; j++) {
	//		tmp.push_back(v[j]);
	//		tmp.push_back(v[j] + v[j + 1]);
	//	}
	//	tmp.push_back(v.back());
	//	v = tmp;
	//	cout << count(all(v), i + 2) << ",";
	//	//for (int i = 0; i < v.size(); i++) {
	//	//	cout << v[i] << " \n"[i == v.size() - 1];
	//	//}
	//}
	cin.ignore(), cin.get();
}
