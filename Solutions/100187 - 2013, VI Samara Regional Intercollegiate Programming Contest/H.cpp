// 100187 - 2013, VI Samara Regional Intercollegiate Programming Contest
// 100187H

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<short, int> pii;
typedef vector<pii> vii;
typedef vector<bool> vb;
typedef vector<string> vs;
const int di[] = { -1,0,1,0 };
const int dj[] = { 0,1,0,-1 };
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
#define mp make_pair
#define all(x) x.begin(),x.end()
#define x first
#define y second

double dis(pair<double, double> a, pair<double, double> b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

bool equal(double a, double b) {
	return abs(a - b) < 0.000001;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	vector<pair<double, double>> p1(3), p2(3);
	for (int i = 0; i < 3; i++)
		cin >> p1[i].x >> p1[i].y;
	for (int i = 0; i < 3; i++)
		cin >> p2[i].x >> p2[i].y;

	vector<double> d1(3), d2(3);
	for (int i = 0; i < 2; i++) {
		d1[i] = dis(p1[i], p1[i + 1]);
		d2[i] = dis(p2[i], p2[i + 1]);
	}
	d1[2] = dis(p1[2], p1[0]);
	d2[2] = dis(p2[2], p2[0]);

	if (equal(d1[0] / d2[0], d1[1] / d2[1]) && equal(d1[1] / d2[1], d1[2] / d2[2]) ||
		equal(d1[0] / d2[1], d1[1] / d2[2]) && equal(d1[1] / d2[2], d1[2] / d2[0]) ||
		equal(d1[0] / d2[2], d1[1] / d2[0]) && equal(d1[1] / d2[0], d1[2] / d2[1]) ||

		equal(d1[0] / d2[2], d1[1] / d2[1]) && equal(d1[1] / d2[1], d1[2] / d2[0]) ||
		equal(d1[0] / d2[1], d1[1] / d2[0]) && equal(d1[1] / d2[0], d1[2] / d2[2]) ||
		equal(d1[0] / d2[0], d1[1] / d2[2]) && equal(d1[1] / d2[2], d1[2] / d2[1]))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	cin.ignore(), cin.get();
}
