// 2017-2018 CTU Open Contest
// 101670J

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
int di[] = {0, 0, 1, -1, 1, -1, 1, -1};
int dj[] = {1, -1, 0, 0, 1, -1, -1, 1};
#define all(x) x.begin(),x.end()
#define x first
#define y second

bool findMatch(int i, const vector<vb>& w, vi& mr, vi& mc, vi& seen) {
	for (int j = 0; j < w[i].size(); ++j) {
		if (w[i][j] && !seen[j]) {
			seen[j] = true;
			if (mc[j] < 0 || findMatch(mc[j], w, mr, mc, seen)) {
				mr[i] = j;
				mc[j] = i;
				return true;
			}
		}
	}
	return false;
}

int bipartiteMatching(const vector<vb>& w) {
	vi mr(w.size(), -1), mc(w[0].size(), -1);

	int ct = 0;
	for (int i = 0; i < w.size(); ++i) {
		vi seen(w[0].size());
		if (findMatch(i, w, mr, mc, seen))
			ct++;
	}
	return ct;
}

int n;
vector<vb>  w;
set<pair<pii, pii>> vis;
map<pii, int> idx;

void dfs(pii node, bool right) {

	for (int i = 0; i < 4; ++i) {
		pii v(node.x + di[i], node.y + dj[i]);
		if (idx.find(v) != idx.end() &&
			vis.find({node, v}) == vis.end()) {
			vis.insert({node, v});
			if (right)
				w[idx[node]][idx[v]] = true;
			else
				w[idx[v]][idx[node]] = true;
			dfs(v, !right);
		}
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	while (cin >> n) {
		idx.clear();
		vis.clear();
		w.assign(n, vb(n, false));
		int cx, cy;
		for (int i = 0; i < n; ++i) {
			cin >> cx >> cy;
			idx[pii(cx, cy)] = i;
		}

		dfs(pii(cx, cy), true);
		cout << n - bipartiteMatching(w) << endl;
	}
}
