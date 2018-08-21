// 101201 - 2016-2017 ACM-ICPC Pacific Northwest Regional Contest (Div. 1)
// 101201C

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
const ll INF = 1e10;
const double EPS = 1e-10;
#define mp make_pair
#define all(x) x.begin(),x.end()

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int n, k, r; cin >> n >> k >> r;
	vb h(n);
	for (int i = 0; i < k; i++) {
		int x; cin >> x;
		h[x] = true;
	}

	int cur = 0;
	for (int i = 0; i < r; i++)
		cur += h[i];

	int rs = 0;
	if (cur < 2) {
		if (!h[r - 1]) h[r - 1] = true;
		else h[r - 2] = true;
		cur++, rs++;
	}
	if (cur < 2) {
		if (!h[r - 1]) h[r - 1] = true;
		else h[r - 2] = true;
		cur++, rs++;
	}

	for (int i = r; i < n; i++) {
		cur += h[i];
		cur -= h[i - r];
		if (cur < 2) {
			if (!h[i]) h[i] = true;
			else h[i - 1] = true;
			cur++, rs++;
		}
	}
	cout << rs << endl;
	cin.ignore(), cin.get();
}
