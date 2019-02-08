// 2018-2019 ACM-ICPC Asia Seoul Regional Contest
// 101987L

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
const long double EPS = 1e-4;
const double PI = 3.1415926535897932384626433;
const ll INF = ll(1e9);
int di[] = {0, 0, 0, 1, -1, 1, -1, 1, -1};
int dj[] = {0, 1, -1, 0, 0, 1, -1, -1, 1};
#define all(x) x.begin(),x.end()

#define FOR(i, a, b) for(int i=(a);i<(b);i++)
#define pb push_back
#define sz(v) (int)v.size()
#define all(c) (c).begin(),(c).end()
#define mem(s, v) memset(s,v,sizeof(s))
typedef vector<int> vi;


int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int m, n, W, h; cin >> m >> n >> W >> h;
	vi w(m), d(n);
	set<pii> st;
	for (int i = 0; i < m; ++i) {
		cin >> w[i];
		st.emplace(w[i], i);
	}
	for (int i = 0; i < n; ++i) {
		cin >> d[i];
	}

	bool wr = false;
	vector<vii> qr(2 * n);
	vvi ans(m);
	for (int i = 0; i < n; ++i) {
		for (auto& j : qr[i]) {
			st.insert(j);
		}
		while (d[i] > 0 && !st.empty()) {
			pii p = *st.rbegin();
			st.erase(p);
			for (int j = 0; j < W; ++j) {
				d[i + j]--;
			}
			ans[p.second].push_back(i);
			p.first -= W;
			if (p.first)
				qr[i + W + h].push_back(p);
		}
		if (d[i] != 0) {
			wr = true; break;
		}
	}

	if (wr || !st.empty()) cout << -1 << endl;
	else {
		cout << 1 << endl;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < ans[i].size(); ++j) {
				cout << ans[i][j] + 1 << " \n"[j == ans[i].size() - 1];
			}
		}
	}
}
