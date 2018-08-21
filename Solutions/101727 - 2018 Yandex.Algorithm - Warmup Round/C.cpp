// 101727 - 2018 Yandex.Algorithm - Warmup Round
// 101727C

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

typedef pair<double, double> pdd;
#define x first
#define y second

inline bool collinear(pdd a, pdd b, pdd c) {
	return abs(a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y)) <= EPS;
}

int main() {
	//ios::sync_with_stdio(false), cin.tie(0);
	int n; scanf("%d", &n);
	vector<pdd> pt;
	for (int i = 0; i < n; i++) {
		int t; scanf("%d", &t);
		pdd p;
		if (t == 0) {
			int r; scanf("%d%lf%lf", &r, &p.x, &p.y);
		}
		else {
			double cx[4], cy[4];
			for (int j = 0; j < 4; j++) {
				scanf("%lf%lf", &cx[j], &cy[j]);
			}

			p.x = (cx[0] + cx[1]) / 2.0;
			cx[2] = (cx[2] + cx[3]) / 2.0;
			p.x = (p.x + cx[2]) / 2.0;

			p.y = (cy[0] + cy[1]) / 2.0;
			cy[2] = (cy[2] + cy[3]) / 2.0;
			p.y = (p.y + cy[2]) / 2.0;
		}

		pt.push_back(p);
	}

	for (int i = 2; i < n; i++) {
		if (!collinear(pt[i - 2], pt[i - 1], pt[i])) {
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	cin.ignore(), cin.get();
}
