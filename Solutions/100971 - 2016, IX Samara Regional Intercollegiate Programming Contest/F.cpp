#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
typedef vector<unsigned long long> vi;
typedef vector<vi> vvi;
typedef pair<unsigned long long, unsigned long long> pii;
typedef vector<pii> vii;
typedef vector<bool> vb;
typedef vector<string> vs;

int x[3],y[3],vx[3],vy[3];
double dist(double t) {
	return sqrt((x[1] + t * vx[1] - x[2] - t * vx[2]) * (x[1] + t * vx[1] - x[2] - t * vx[2]) +
			(y[1] + t * vy[1] - y[2] - t * vy[2]) * (y[1] + t * vy[1] - y[2] - t * vy[2]));
}

int main() {
	ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> x[1] >> y[1] >> x[2] >> y[2];
	cin >> vx[1] >> vy[1] >> vx[2] >> vy[2];
	double a = 0, b = 1000000000, m1 = (2 * a + b) / 3.0, m2 = (a + 2 * b) / 3.0;
	int c = 1000;
	while (c--)
	{
		if (dist(m1) > dist(m2))
			a = m1;
		else
			b = m2;
		m1 = (2 * a + b) / 3.0, m2 = (a + 2 * b) / 3.0;
	}
	cout << fixed << setprecision(15) << dist(m1) << endl;
}
