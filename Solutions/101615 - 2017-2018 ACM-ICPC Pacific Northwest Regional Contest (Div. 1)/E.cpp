// 101615 - 2017-2018 ACM-ICPC Pacific Northwest Regional Contest (Div. 1)
// 101615E

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
const double EPS = 1e-7;
#define mp make_pair
#define all(x) x.begin(),x.end()

int n;
double X, v;
const double PI = 3.14159265359;

struct Range {
	double dx, dy;
	double length;
};

vector<Range> rng;

double calcTime(double ang) {
	return X / cos(ang * PI / 180.0) / v;

	//double dx = 1.0 * v * cos(ang * PI / 180.0);
	//double dy = 1.0 * v * sin(ang * PI / 180.0);
	//double cx = 0, cy = 0;

	//double ret = 0;

	//double speed = sqrt(1 + dy / dx * dy / dx) / v;

	//for (int i = 0; i < rng.size(); i++) {
	//	double cdx = dx + rng[i].dx;
	//	double cdy = dy + rng[i].dy;

	//	//ret += rng[i].length * speed;
	//	double h = rng[i].length * sqrt(1 + dy / dx * dy / cdx);
	//	ret += h / v;
	//	cx += rng[i].length;
	//	cy += cdy / cdx * rng[i].length;
	//}
	//return ret;
}

double endY(double ang) {
	double dx = 1.0 * v * cos(ang * PI / 180.0);
	double dy = 1.0 * v * sin(ang * PI / 180.0);
	double cx = 0, cy = 0;

	for (int i = 0; i < rng.size(); i++) {
		double cdx = dx + rng[i].dx;
		double cdy = dy + rng[i].dy;

		cx += rng[i].length;
		cy += cdy / cdx * rng[i].length;
	}

	return cy;
}

double ternary() {
	double a = -89.9999, b = 89.9999, mid = (a + b) / 2.0;
	//double c = (2.0 * a + b) / 3.0, d = (a + 2.0 * b) / 3.0;
	while (b - a > EPS) {
		//cout<< fixed << setprecision(3) << endY(c) << " " << endY(d) << endl;
		if (endY(mid) >= 0)
			b = mid;
		else
			a = mid;
		mid = (a + b) / 2.0;
		//c = (2 * a + b) / 3.0, d = (a + 2 * b) / 3.0;
	}
	return (a + b) / 2.0;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> X >> v;
	double prvr = 0;
	for (int i = 0; i < n; i++) {
		double l, r, cv;
		cin >> l >> r >> cv;
		rng.push_back(Range{ 0,0,l - prvr });
		rng.push_back(Range{ 0,cv, r - l });
		prvr = r;
	}
	rng.push_back(Range{ 0,0,X - prvr });

	//cout << calcTime(0) << endl;

	double ang = ternary();
	//cout << ternary() << endl;
	double tme = calcTime(ang);
	//cout << tme << endl;
	//cout << 2.0 * X / v + EPS << endl;
	if (tme > 2.0 * X / v + EPS)
		cout << "Too hard\n";
	else
		cout << fixed << setprecision(3) << tme << endl;
	cin.ignore(), cin.get();
}
