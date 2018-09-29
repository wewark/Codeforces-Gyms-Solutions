// 2018-2019 ACM-ICPC Brazil Subregional Programming Contest
// 101908C

#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<bool> vb;
typedef vector<string> vs;
const int di[] = {0, 0, 1, -1};
const int dj[] = {1, -1, 0, 0};
const ll MOD = 1e9 + 7;
const long double EPS = 1e-5;
#define all(x) x.begin(),x.end()

#include <ext/hash_set>
#include <ext/numeric>

#define LSOne(S) (S & (-S))

class BIT {
private:
	vi ft;
public:
	BIT() {}
	BIT(int n) { ft.assign(n + 1, 0); }

	int rsq(int b) {
		int sum = 0; for (; b; b -= LSOne(b)) sum += ft[b];
		return sum;
	}

	void adjust(int k, int v) {
		for (; k < (int)ft.size(); k += LSOne(k)) ft[k] += v;
	}
};

ll inversions(vi& v) {
	BIT bit(1e5 + 5);
	ll ret = 0;
	for (int i = v.size() - 1; i >= 0; i--) {
		ret += bit.rsq(v[i]);
		bit.adjust(v[i], 1);
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int x, y; cin >> x >> y;
	ll h, v; cin >> h >> v;
	ll ans = h * v + 1;

	vii num(h);
	for (int i = 0; i < h; ++i) {
		cin >> num[i].first >> num[i].second;
	}
	sort(all(num));
	map<int, int> m;
	for (int i = 0; i < h; ++i) {
		m[num[i].second] = i + 1;
	}
	vi vec;
	for (auto& i : m)
		vec.push_back(i.second);
	ans += h + inversions(vec);


	num.resize(v);
	for (int i = 0; i < v; ++i) {
		cin >> num[i].first >> num[i].second;
	}
	sort(all(num));
	m.clear();
	for (int i = 0; i < v; ++i) {
		m[num[i].second] = i + 1;
	}
	vec.clear();
	for (auto& i : m)
		vec.push_back(i.second);
	ans += v + inversions(vec);

	cout << ans << endl;
	return 0;
}
