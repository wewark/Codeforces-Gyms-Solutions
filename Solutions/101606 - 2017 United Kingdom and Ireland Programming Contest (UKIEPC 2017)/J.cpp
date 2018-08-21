// 101606 - 2017 United Kingdom and Ireland Programming Contest (UKIEPC 2017)
// 101606J

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
	int n; cin >> n;
	vi num(n);

	map<int, double> cnv;
	cnv[0] = 2, cnv[1] = 1, cnv[2] = 0.5, cnv[4] = 0.25;
	cnv[8] = 1 / 8.0, cnv[16] = 1 / 16.0;

	double r = 0;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
		r += cnv[num[i]];
	}
	cout << fixed << setprecision(10) << r << endl;
	cin.ignore(), cin.get();
}
