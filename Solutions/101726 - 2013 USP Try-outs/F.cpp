// 101726 - 2013 USP Try-outs
// 101726F

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

const double PI = 3.14159265359;

inline double ang(double h, double w) {
	return atan(h / w);
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; double w, s;
		cin >> n >> w >> s;
		vector<double> h(n);
		int gi = -1;
		for (int i = 0; i < n; i++) {
			cin >> h[i];
			if (h[i] == 0) gi = i;
		}

		double l = 0, r = 0;
		for (int i = 0; i < gi; i++) {
			l = max(l, ang(h[i], (w + s) * (gi - i)));
		}
		for (int i = gi + 1; i < n; i++) {
			r = max(r, ang(h[i], (w + s) * (i - gi)));
		}

		double ta = PI - l - r;
		double minPerAng = 16.0 * 60.0 / PI;

		cout << fixed << setprecision(10) << ta * minPerAng << endl;
	}
	cin.ignore(), cin.get();
}
