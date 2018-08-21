// 101239 - 2015 ACM-ICPC World Finals
// 101239A

#include < bits/stdc++.h >
using namespace std;

int main() {
	int p, a, b, c, d, n;
	double price, mx = 0, mn;

	cin >> p >> a >> b >> c >> d >> n;

	for (int i = n; i; i--) {
		price = p * (sin(a * i + b) + cos(c * i + d) + 2);

		if (i == n)
			mn = price;
		else {
			mx = max(mx, price - mn);
			mn = min(mn, price);
		}
	}

	cout << fixed << setprecision(11) << mx;
}
