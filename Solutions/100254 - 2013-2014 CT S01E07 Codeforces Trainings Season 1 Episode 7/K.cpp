// 2013-2014 CT S01E07 Codeforces Trainings Season 1 Episode 7
// 100254K

#pragma GCC optimize ("O3")
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

#define  fr first
#define  sc second
typedef pair<int, pair<int, int>> piii;

int n, k;
string s;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	cin >> n >> k >> s;
	string res;
	for (int i = 0; i < n; i++) {
		while (k && !res.empty() && s[i] > res.back()) {
			res.pop_back();
			k--;
		}
		res.push_back(s[i]);
	}
	string res2;
	for (int i = res.length() - 1; i >= 0; i--) {
		while (k && !res2.empty() && res[i] > res2.back()) {
			res2.pop_back();
			k--;
		}
		res2.push_back(res[i]);
	}
	reverse(all(res2));
	cout << res2 << endl;
	return 0;
}