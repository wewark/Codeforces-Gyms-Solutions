// 101635 - 2017-2018 ACM-ICPC Southwestern European Regional Programming Contest (SWERC 2017)
// 101635E

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<ll, ll> pii;
typedef vector<pii> vii;
typedef vector<bool> vb;
typedef vector<string> vs;
const int di[] = { -1, 0, 1, 0, -1, 1, 1, -1 };
const int dj[] = { 0, 1, 0, -1, -1, 1, -1, 1 };
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const long double EPS = 1e-7;
#define all(x) x.begin(),x.end()

struct Dish {
	string name, base, ing;
	ll cost, pr;
};

int b, n;
vii dsh; // (cost, pr)

map<string, vector<Dish>> dish;
map<string, pii> rs; // (cost, pr)

pii calc(string name) {
	if (rs.find(name) != rs.end()) return rs[name];

	pii ret(INF, 0);
	for (auto& cur : dish[name]) {
		pii x = calc(cur.base);
		x.first += cur.cost;
		x.second += cur.pr;
		if (x.first < ret.first || x.first == ret.first && x.second > ret.second)
			ret = x;
	}

	if (ret.first == INF) ret.first = 0;
	rs[name] = ret;
	return ret;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> b >> n;
	for (int i = 0; i < n; i++) {
		Dish x;
		cin >> x.name >> x.base >> x.ing >> x.cost >> x.pr;
		dish[x.name].push_back(x);
	}

	for (auto& i : dish)
		dsh.push_back(calc(i.first));

	ll dp[2][10002];
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 10002; j++)
			dp[i][j] = 0;

	ll rp = 0, rc = 0;
	for (int i = 0; i <= dsh.size(); i++) {
		for (int j = 0; j <= b; j++)
			dp[(i + 1) & 1][j] = 0;
		for (int j = 0; j <= b; j++) {
			if (i < dsh.size() && j + dsh[i].first <= b)
				dp[(i + 1) & 1][j + dsh[i].first] = max(dp[(i + 1) & 1][j + dsh[i].first], dp[i & 1][j] + dsh[i].second);
			dp[(i + 1) & 1][j] = max(dp[(i + 1) & 1][j], dp[i & 1][j]);
			if (dp[i & 1][j] > rp ||
				dp[i & 1][j] == rp && j < rc)
				rp = dp[i & 1][j], rc = j;
		}
	}

	cout << rp << endl << rc << endl;
	cin.ignore(), cin.get();
}
