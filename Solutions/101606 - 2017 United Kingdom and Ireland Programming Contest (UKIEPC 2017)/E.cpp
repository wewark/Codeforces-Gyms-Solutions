// 101606 - 2017 United Kingdom and Ireland Programming Contest (UKIEPC 2017)
// 101606E

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
	int n, m; cin >> n >> m;
	vii s(n); vi p(m), r(m); vb vis(m);
	for (int i = 0; i < n; i++)
		cin >> s[i].first, s[i].second = i;
	for (int i = 0; i < m; i++)
		cin >> p[i];
	for (int i = 0; i < m; i++)
		cin >> r[i];

	sort(s.rbegin(), s.rend());
	vii rs(n);
	ll sum = 0; bool w = false;
	for (int i = 0; i < n; i++) {
		int mn = INF, mni = -1;
		for (int j = 0; j < m; j++)
			if (!vis[j] && p[j] >= s[i].first && r[j] < mn)
				mn = r[j], mni = j;
		if (mni == -1) {
			w = true; break;
		}
		vis[mni] = true;
		rs[i].first = s[i].second;
		rs[i].second = mni;
	}

	sort(all(rs));
	if (w) cout << "impossible\n";
	else for (int i = 0; i < n; i++)
		cout << rs[i].second + 1 << " \n"[i == n - 1];
	cin.ignore(), cin.get();
}
