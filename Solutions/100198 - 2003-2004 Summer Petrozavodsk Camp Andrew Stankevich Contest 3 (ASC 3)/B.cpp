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

bool FindMatch(int i, const vvi &w, vi &mr, vi &mc, vi &seen) {
	for (int j = 0; j < w[i].size(); j++) {
		if (w[i][j] && !seen[j]) {
			seen[j] = true;
			if (mc[j] < 0 || FindMatch(mc[j], w, mr, mc, seen)) {
				mr[i] = j;
				mc[j] = i;
				return true;
			}
		}
	}
	return false;
}

int BipartiteMatching(const vvi &w, vi &mr, vi &mc) {
	mr = vi(w.size(), -1);
	mc = vi(w[0].size(), -1);

	int ct = 0;
	for (int i = 0; i < w.size(); i++) {
		vi seen(w[0].size());
		if (FindMatch(i, w, mr, mc, seen)) ct++;
	}
	return ct;
}

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

	vvi w(400, vi(400));
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
		for (int& j : prf[i].second) {
			w[i][j] = true;
		}
	}

	vi mr, mc;
	BipartiteMatching(w, mr, mc);
	vi ans(n);
	for (int i = 0; i < n; ++i) {
		ans[prf[i].first] = mr[i];
	}
	for (int i = 0; i < n; ++i) {
		printf("%d%c", ans[i] + 1, " \n"[i == n - 1]);
	}

}
