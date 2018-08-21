// 101471 - 2017 ACM-ICPC World Finals
// 101471E

#include <bits/stdc++.h>
#define fs first
#define sc second
#define pb push_back

using namespace std;

typedef long long ll;
const int N=101, mod=60;
const ll INF=1e18+7;
const double PI = 3.141592653589793238462643383279502884197, EPS=1e-9, two=2.0;

int n, T;
vector<double> d, s;

double f(double c) {
	double ret = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] + c <= EPS) return 1e9;
		ret += d[i] / (s[i] + c);
	}
	return ret;
}

double bs() {
	double a = -1e9, b = 1e9, mid = (a + b) / two;
	while (b - a > EPS) {
		if (f(mid) > T)
			a = mid;
		else
			b = mid;
		mid = (a + b) / two;
	}

	return mid;
}

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> n >> T;
	d.resize(n); s = d;
	for (int i = 0; i < n; ++i) {
		cin >> d[i] >> s[i];
	}

	cout << fixed << setprecision(9) << bs() << endl;

	return 0;
}
