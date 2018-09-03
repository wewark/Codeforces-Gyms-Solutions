// 2015-2016 ACM-ICPC Nordic Collegiate Programming Contest (NCPC 2015)
// 100781F

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

int f;
vi t, n;
vvi rng;

int mem[10005][105][12];
bool solve(int cur, int rngi, int ti) {
	if (rngi == n[ti])
		return true;

	int& ret = mem[cur][rngi][ti];
	if (~ret) return ret;
	ret = false;

	if (cur + rng[ti][rngi] <= t[ti])
		ret = ret || solve(cur + rng[ti][rngi], rngi + 1, ti);
	if (cur - rng[ti][rngi] >= 0)
		ret = ret || solve(cur - rng[ti][rngi], rngi + 1, ti);
	return ret;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	memset(mem, -1, sizeof mem);
	cin >> f;
	t.resize(f);
	n.resize(f);
	rng.resize(f);
	for (int i = 0; i < f; i++) {
		cin >> t[i] >> n[i];
		rng[i].resize(n[i]);
		for (int j = 0; j < n[i]; j++) {
			int a, b; cin >> a >> b;
			rng[i][j] = b - a;
		}
	}

	for (int i = 0; i < f; i++) {
		bool good = false;
		for (int j = 0; j <= t[i]; j++)
			if (solve(j, 0, i)) {
				good = true;
				break;
			}
		if (!good) {
			cout << "impossible" << endl;
			return 0;
		}
	}
	cout << "possible" << endl;
}
