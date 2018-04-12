#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const double EPS = 1e-7, PI = 3.14159265358979323846;

void pow2(int n, double *arr, double *Narr) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			Narr[i + j] += arr[i] * arr[j];
}

double power(double num, int p) {
	double ans = 1;
	while (p--)
		ans *= num;
	return ans;
}

double intg(int n, double mn, double mx, double *Narr) {
	double ans = 0;
	for (int i = 0; i < 2 * n; i++)
		ans += Narr[i] * power(mx, i + 1) / (i + 1)
		- Narr[i] * power(mn, i + 1) / (i + 1);
	return PI * ans;
}

int main() {
	cout << fixed << setprecision(2);
	int n;
	for (int T = 1; cin >> n; T++) {
		int inc;
		vector<double> marks;

		n++;
		double arr[n], Narr[2 * n] = { 0 }, s, e, mn, mx;
		for (int i = 0; i < n; i++)
			cin >> arr[i];

		pow2(n, arr, Narr);
		cin >> mn >> mx >> inc;
		cout << "Case " << T << ": " << intg(n, mn, mx, Narr) << '\n';

		s = mn, e = mx;
		while (intg(n, s, e, Narr) > inc && marks.size() < 8) {
			double st = s, ed = e, mid, ans;
			while (ed - st >= EPS) {
				mid = (st + ed) / 2;
				if (intg(n, s, mid, Narr) >= inc)
					ed = mid, ans = mid;
				else
					st = mid;
			}
			marks.push_back(ans);
			s = ans;
		}

		if (marks.size()) {
			for (int i = 0; i < marks.size(); i++)
				cout << marks[i] - mn << (i != marks.size() - 1 ? ' ' : '\n');
		}
		else
			cout << "insufficient volume\n";
	}
	return 0;
}
