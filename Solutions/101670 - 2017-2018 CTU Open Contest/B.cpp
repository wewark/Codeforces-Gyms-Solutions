// 2017-2018 CTU Open Contest
// 101670B

#include <bits/stdc++.h>
#include <ext/hash_set>
#include <ext/numeric>

using namespace __gnu_cxx;
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;
using vb = vector<bool>;
using vs = vector<string>;
const int MOD = int(1e9 + 7);
const long double EPS = 1e-8;
const double PI = 3.1415926535897932384626433;
const ll INF = ll(1e9);
int di[] = {0, 0, 0, 1, -1, 1, -1, 1, -1};
int dj[] = {0, 1, -1, 0, 0, 1, -1, -1, 1};
#define all(x) x.begin(),x.end()

int n, f;
vi cap;

inline bool valid(double t, int type) {
	vector<double> v(n);
	bool allFill = true, overflow = false;
	for (int i = 0; i < n; ++i) {
		v[i] += t * f;
		if (v[i] >= cap[i]) {
			if (i == n - 1) {
				overflow = true;
				break;
			}
			v[i + 1] += v[i] - cap[i];
		} else {
			allFill = false;
		}
	}
	return type == 0 ? overflow : allFill;
}

double BS(int type) {
	double a = 0, b = 1e9 + 9, mid = (a + b) / 2.0;
	for (int i = 0; i < 200; ++i) {
		if (b - a < EPS)
			break;
		if (valid(mid, type))
			b = mid;
		else
			a = mid;
		mid = (a + b) / 2.0;
	}
	return mid;
}

int main() {
//	ios::sync_with_stdio(false), cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	while (~scanf("%d %d", &n, &f)) {
		cap.resize(n);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &cap[i]);
		}

		printf("%.9lf %.9lf\n", BS(0), BS(1));
	}
}
