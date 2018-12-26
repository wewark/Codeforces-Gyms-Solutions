// 2003-2004 Summer Petrozavodsk Camp Andrew Stankevich Contest 3 (ASC 3)
// 100198B

#include <bits/stdc++.h>
#include <ext/hash_set>
#include <ext/numeric>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<bool> vb;
typedef vector<string> vs;
const ll MOD = 1e9 + 7;
const long double EPS = 1e-5;
const ll INF = 1e9;
int di[] = { 0, 0, 1, -1 };
int dj[] = { 1, -1, 0, 0 };
#define all(x) x.begin(),x.end()

struct BipartiteMatcher {
	vector<vector<int>> G;
	vector<int> L, R, Viz;

	BipartiteMatcher(int n, int m) :
			G(n), L(n, -1), R(m, -1), Viz(n) {}

	void AddEdge(int a, int b) {
		G[a].push_back(b);
	}

	bool Match(int node) {
		if (Viz[node])
			return false;
		Viz[node] = true;

		for (auto vec : G[node]) {
			if (R[vec] == -1) {
				L[node] = vec;
				R[vec] = node;
				return true;
			}
		}

		for (auto vec : G[node]) {
			if (Match(R[vec])) {
				L[node] = vec;
				R[vec] = node;
				return true;
			}
		}

		return false;
	}

	int Solve() {
		int ok = true;
//		while (ok--) {
			for (int i = 0; i < (int)L.size(); ++i) {
				fill(Viz.begin(), Viz.end(), 0);
				if (L[i] == -1)
					ok |= Match(i);
			}
//		}

		int ret = 0;
		for (int i = 0; i < L.size(); ++i)
			ret += (L[i] != -1);
		return ret;
	}
};

vi A;

int main() {
//	ios::sync_with_stdio(0), cin.tie(0);
//#ifndef ONLINE_JUDGE
//	freopen("input.txt", "r", stdin);
	freopen("beloved.in", "r", stdin);
	freopen("beloved.out", "w", stdout);
//#endif

	int n; scanf("%d", &n);
	A.resize(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &A[i]);
	}

	BipartiteMatcher bm(1000, 1000);
	vector<pair<int, vi>> prf(n);
	for (int i = 0; i < n; ++i) {
		int sz; scanf("%d", &sz);
		prf[i].first = i;
		prf[i].second.resize(sz);
		for (int j = 0; j < sz; ++j) {
			cin >> prf[i].second[j]; prf[i].second[j]--;
		}
	}
	sort(prf.begin(), prf.end(), [](pair<int, vi>& a, pair<int, vi>& b) {
		return A[a.first] > A[b.first];
	});
	for (int i = 0; i < n; ++i) {
		for (int& j : prf[i].second)
			bm.AddEdge(i, j);
	}

	bm.Solve();
	vi ans(n);
	for (int i = 0; i < n; ++i)
		ans[prf[i].first] = bm.L[i];
	for (int i = 0; i < n; ++i) {
		printf("%d%c", ans[i] + 1, " \n"[i == n - 1]);
	}

}
