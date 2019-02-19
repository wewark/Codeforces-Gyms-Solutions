// 2017-2018 CTU Open Contest
// 101670D

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
#define x first
#define y second


int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int n;
	while (cin >> n) {
		vii p(n);
		set<pii> st;
		unordered_map<int, vi> xl, yl;
		for (int i = 0; i < n; ++i) {
			cin >> p[i].x >> p[i].y;
			xl[p[i].x].push_back(p[i].y);
			yl[p[i].y].push_back(p[i].x);
			st.emplace(p[i].x, p[i].y);
		}

		for (auto &i : xl)
			sort(all(i.second));
		for (auto &i : yl)
			sort(all(i.second));

		int ans = 0;
		for (auto &p1 : p) {
			if (xl[p1.x].size() < yl[p1.y].size()) {
				auto it = upper_bound(all(xl[p1.x]), p1.y);
				auto endIt = xl[p1.x].end();
				for (auto p2y = it; p2y != endIt; p2y++) {
					int side = (*p2y - p1.y);
					if ((st.find({p1.x + side, p1.y}) != st.end() &&
					     st.find({p1.x + side, *p2y}) != st.end()) ||
					    (st.find({p1.x - side, p1.y}) != st.end() &&
					     st.find({p1.x - side, *p2y}) != st.end())) {
						ans = max(ans, side);
					}
				}
			}
			else {
				auto it = upper_bound(all(yl[p1.y]), p1.x);
				auto endIt = yl[p1.y].end();
				for (auto p2x = it; p2x != endIt; p2x++) {
					int side = (*p2x - p1.x);
					if ((st.find({p1.x, p1.y + side}) != st.end() &&
					     st.find({*p2x, p1.y + side}) != st.end()) ||
					    (st.find({p1.x, p1.y - side}) != st.end() &&
					     st.find({*p2x, p1.y - side}) != st.end())) {
						ans = max(ans, side);
					}
				}
			}
		}
		cout << ans << endl;
	}
}
