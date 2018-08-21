// 101503 - 2007-2008 ACM-ICPC, NEERC, Southern Subregional Contest
// 101503H

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
const double EPS = 1e-5;
#define mp make_pair
#define all(x) x.begin(),x.end()

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int n, k1, k2, p1, p2, p3;
	cin >> n >> k1 >> k2 >> p1 >> p2 >> p3;

	int r = 0;
	bool ed = false;
	if (n >= p1)
		r += k1, n -= p1;
	else
		ed = true;
	for (int i = 0; i < k2 && !ed && n > 0; i++) {
		r++, n -= p2;
		if (n <= 0)
			ed = true;
	}
	if (!ed && n > 0)
		r += ceil(n / (double)p3);
	cout << r << endl;
	//cin.ignore(), cin.get();
}
