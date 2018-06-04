#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
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
const long double EPS = 1e-7;
#define all(x) x.begin(),x.end()

double s, m, p;

inline double total(double x) {
	double cur = s, ret = 0;
	for (int i = 0; i < m; i++) {
		double a = cur * p;
		ret += x - cur * p;
		cur -= x - cur * p;
	}
	return ret;
}

double bs() {
	double a = 0, b = 1e7, mid = (a + b) / 2.0;
	while (a < b - EPS) {
		if (total(mid) < s - EPS)
			a = mid;
		else
			b = mid;
		mid = (a + b) / 2.0;
	}
	return mid;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	cin >> s >> m >> p;
	p /= 100.0;
	cout << fixed << setprecision(6) << bs() << endl;
	cin.ignore(), cin.get();
}
