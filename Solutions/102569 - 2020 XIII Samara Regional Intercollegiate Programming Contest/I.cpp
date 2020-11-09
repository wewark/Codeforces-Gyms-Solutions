// 2020 XIII Samara Regional Intercollegiate Programming Contest
// 102569I

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vb = vector<bool>;
using pii = pair<int, int>;
using vii = vector<pii>;
using vs = vector<string>;
#define all(x) x.begin(), x.end()
// int di[] = {0, 1, 0, -1};
// int dj[] = {1, 0, -1, 0};
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const double PI = 3.14159265359;



int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#else
	//	freopen("document.in", "r", stdin);
//	freopen("document.out", "w", stdout);
#endif

	int n; cin >> n;
	map<int, vi> m;
	for (int i = 0; i < n; ++i) {
		int a, c; cin >> a >> c;
		m[c].push_back(a);
	}

	for (auto& i : m) {
		if (!is_sorted(all(i.second))) {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
}
