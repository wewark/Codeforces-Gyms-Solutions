// 101606 - 2017 United Kingdom and Ireland Programming Contest (UKIEPC 2017)
// 101606C

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

	map<string, ll> val;
	val["red"] = 1;
	val["yellow"] = 2;
	val["green"] = 3;
	val["brown"] = 4;
	val["blue"] = 5;
	val["pink"] = 6;
	val["black"] = 7;

	ll cnt = 0, mx = 0, r = 0;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		if (s == "red") cnt++;
		else {
			r += val[s];
			mx = max(mx, val[s]);
		}
	}
	if (mx == 0) r = 1;
	else r += (mx + 1) * cnt;
	cout << r << endl;
	cin.ignore(), cin.get();
}
