// ACM International Collegiate Programming Contest Arabella Collegiate Programming Contest (2018)
// 101972K

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
#define all(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define fr first
#define sc second


int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		string a, b; cin >> a >> b;

		vector<pair<int, char>> w;
		for (int i = 0; i < n; ++i)
			if (a[i] != b[i])
				w.emplace_back(i, b[i]);
		for (int i = 0; i < w.size(); ++i)
			b[w[(i + 1) % w.size()].first] = w[i].second;
		if (b == a)
			cout << "YES\n";
		else
			cout << "NO\n";
	}


}