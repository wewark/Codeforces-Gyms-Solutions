// 101606 - 2017 United Kingdom and Ireland Programming Contest (UKIEPC 2017)
// 101606F

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

int n, k;

vector<vb> vis(405, vb(405, false));
vector<vector<double>> mem(405, vector<double>(405, -1e4));
double solve(int cur, int cnt) {
	if (cnt == k) return 0;
	if (mem[cur][cnt] > -1e3) return mem[cur][cnt];

	double ret = 0;
	if (cur == n) {
		cur--;
		ret = 0.5 * (-1 + solve(cur, cnt + 1));
		ret += 0.5 * solve(cur + 1, cnt + 1);
		cur++;
	}
	else {
		ret = 0.5 * (1 + solve(cur + 1, cnt + 1));
		ret += 0.5 * solve(cur, cnt + 1);
	}
	return mem[cur][cnt] = ret;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> k;
	cout << fixed << setprecision(10) << solve(0, 0) << endl;
	cin.ignore(), cin.get();
}
