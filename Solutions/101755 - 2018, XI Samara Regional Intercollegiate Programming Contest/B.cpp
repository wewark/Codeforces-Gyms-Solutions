// 101755 - 2018, XI Samara Regional Intercollegiate Programming Contest
// 101755B

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
const long double EPS = 1e-10;
#define all(n) n.begin(),n.end()

bool cmpy(pii a, pii b) {
	if (a.second != b.second)
		return a.second < b.second;
	return a.first < b.first;
}

ll area(pii a, pii b, pii c) {
	return abs((a.first - c.first) * (b.second - a.second)
		- (a.first - b.first) * (c.second - a.second));
}

int n;
vii x, y;

ll solve(pii p) {
	set<pii> st = { p };
	auto it = upper_bound(all(x), p);
	if (it != x.end()) {
		st.insert(*it);
		it++;
		if (it != x.end()) {
			st.insert(*it);
		}
		it--;
	}
	it--;

	if (it != x.begin()) {
		it--;
		st.insert(*it);
	}
	if (it != x.begin()) {
		it--;
		st.insert(*it);
	}

	it = upper_bound(all(y), p, cmpy);
	if (it != y.end()) {
		st.insert(*it);
		it++;
		if (it != y.end()) {
			st.insert(*it);
		}
		it--;
	}
	it--;

	if (it != y.begin()) {
		it--;
		st.insert(*it);
	}
	if (it != y.begin()) {
		it--;
		st.insert(*it);
	}

	vii v;
	for (auto& i : st)
		v.push_back(i);

	ll ret = LLONG_MAX;
	for (int i = 0; i < v.size(); i++) {
		for (int j = i + 1; j < v.size(); j++) {
			for (int k = j + 1; k < v.size(); k++) {
				ret = min(ret, area(v[i], v[j], v[k]));
			}
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n;
	x.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> x[i].first >> x[i].second;
	}
	y = x;
	sort(all(x));
	sort(all(y), cmpy);

	ll r = LLONG_MAX;
	for (int i = 0; i < n; i++) {
		r = min(r, solve(x[i]));
	}
	cout << r << endl;
	cin.ignore(), cin.get();
}
