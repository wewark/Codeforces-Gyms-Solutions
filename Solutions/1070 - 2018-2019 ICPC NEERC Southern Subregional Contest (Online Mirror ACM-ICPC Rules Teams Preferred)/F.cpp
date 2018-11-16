// 2018-2019 ICPC NEERC Southern Subregional Contest (Online Mirror ACM-ICPC Rules Teams Preferred)
// 1070F

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
const ll MOD = 1e9 + 7;
const long double EPS = 1e-5;
#define all(x) x.begin(),x.end()
#define SZ(x) (int)(x).size()

#include <ext/hash_set>
#include <ext/numeric>

#define  fr first
#define  sc second


int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int n; cin >> n;
	vi num[3];
	ll r = 0, a = 0, b = 0, tot = 0;
	for (int i = 0; i < n; ++i) {
		string s; cin >> s;
		int x; cin >> x;
		if (s == "00") num[0].push_back(x);
		else if (s == "01") num[1].push_back(x);
		else if (s == "10") num[2].push_back(x);
		else r += x, a++, b++, tot++;
	}

	sort(all(num[1]));
	sort(all(num[2]));

	while (!num[1].empty() && !num[2].empty()) {
		tot += 2;
		a++, b++;
		r += num[1].back();
		r += num[2].back();
		num[1].pop_back();
		num[2].pop_back();
	}

	if (!num[1].empty()) {
		num[0].insert(num[0].end(), all(num[1]));
		sort(num[0].rbegin(), num[0].rend());
		for (int i = 0; i < num[0].size() && 2 * b >= tot + 1; ++i) {
			tot++;
			r += num[0][i];
		}
	}
	else {
		num[0].insert(num[0].end(), all(num[2]));
		sort(num[0].rbegin(), num[0].rend());
		for (int i = 0; i < num[0].size() && 2 * a >= tot + 1; ++i) {
			tot++;
			r += num[0][i];
		}
	}

	cout << r << endl;

	return 0;
}