// 2014-2015 Northwestern European Regional Contest (NWERC 2014)
// 101482E

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
const int di[] = { 0, 0, 1, -1 };
const int dj[] = { 1, -1, 0, 0 };
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const long double EPS = 1e-6;
#define all(x) x.begin(),x.end()
#define fr first
#define sc second

typedef long double ld;

ld n, p, s, v;

ld f(ld c) {
	return n * pow(log2(n), c * sqrt(2)) / (p * 1e9) + s * (1.0 + 1.0 / c) / v;
}

ld TS() {
	ld a = EPS, b = 200;
	ld c = a + (b - a) / 3.0;
	ld d = b - (b - a) / 3.0;
	for (int i = 0; i < 200; i++) {
		if (f(c) > f(d))
			a = c;
		else
			b = d;
		c = a + (b - a) / 3.0;
		d = b - (b - a) / 3.0;
	}
	return (a + b) / 2.0;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> p >> s >> v;
	ld r = TS();
	cout << fixed << setprecision(10) << f(r) << " " << r << endl;
}
