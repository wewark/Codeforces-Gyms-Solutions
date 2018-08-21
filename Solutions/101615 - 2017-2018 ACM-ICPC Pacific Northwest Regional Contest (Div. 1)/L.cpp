// 101615 - 2017-2018 ACM-ICPC Pacific Northwest Regional Contest (Div. 1)
// 101615L

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
const double EPS = 1e-4;
#define mp make_pair
#define all(x) x.begin(),x.end()

double k, p, x;

inline double f(double m) {
	return k * p / m + m * x;
}

//double bs() {
//	double a = 0, b = 1e5, mid = (a + b) / 2.0;
//	while (b - a > EPS) {
//		if (f(mid))
//	}
//}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> k >> p >> x;
	double r = INT_MAX;
	for (int i = 1; i < 1e6; i++) {
		r = min(r, f(i));
	}
	cout << fixed << setprecision(3) << r << endl;
	cin.ignore(), cin.get();
}
