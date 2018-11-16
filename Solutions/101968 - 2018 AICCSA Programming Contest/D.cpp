// 2018 AICCSA Programming Contest
// 101968D

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
const ll MOD = 1e9 + 7;
const long double EPS = 1e-5;
#define all(x) x.begin(),x.end()

#include <ext/hash_set>
#include <ext/numeric>



int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		multiset<int> a, b;

		for (int i = 0; i < n; ++i) {
			int x; cin >> x;
			a.insert(x);
		}
		for (int i = 0; i < n; ++i) {
			int x; cin >> x;
			if (a.find(x) != a.end())
				a.erase(a.find(x));
			else
				b.insert(x);
		}

		if (b.size() > 1)
			cout << "NO\n";
		else if (b.size() == 1)
			cout << (abs(*b.begin() - *a.begin()) <= k ? "YES" : "NO") << "\n";
		else
			cout << "YES\n";//
	}


	return 0;
}