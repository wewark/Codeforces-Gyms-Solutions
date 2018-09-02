// 2014-2015 Northwestern European Regional Contest (NWERC 2014)
// 101482F

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
const int di[] = { 0, 0, 1, -1 };
const int dj[] = { 1, -1, 0, 0 };
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const long double EPS = 1e-6;
#define all(x) x.begin(),x.end()
#define x first
#define y second

typedef pair<ll, ll> pdd;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	srand(time(NULL));
	ll n; double p;
	cin >> n >> p;

	vector<pdd> pt(n);
	for (int i = 0; i < n; i++) {
		cin >> pt[i].x >> pt[i].y;
	}

	if (n == 1) {
		cout << "possible" << endl;
		return 0;
	}

	for (int i = 0; i < 1000; i++) {
		int a = (rand() * rand()) % n;
		int b = (rand() * rand()) % n;
		while (b == a) b = (rand() * rand()) % n;
		int cnt = 1;
		for (int j = 0; j < n; j++) {
			if (j != a &&
				(pt[a].y - pt[j].y) * (pt[a].x - pt[b].x) ==
				(pt[a].y - pt[b].y)  * (pt[a].x - pt[j].x)) // slope == slope
				cnt++;
		}
		if (cnt * 100 >= p * n) { // cnt / n == p / 100
			cout << "possible" << endl;
			return 0;
		}
	}
	cout << "impossible" << endl;
}
