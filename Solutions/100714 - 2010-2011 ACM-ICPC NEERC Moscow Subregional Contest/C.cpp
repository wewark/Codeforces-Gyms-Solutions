// 2010-2011 ACM-ICPC NEERC Moscow Subregional Contest
// 100714C

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
const int di[] = {0, 0, 1, -1};
const int dj[] = {1, -1, 0, 0};
const ll MOD = 1e9 + 7;
const long double EPS = 1e-3;
#define all(x) x.begin(),x.end()
#include <ext/hash_set>
#include <ext/numeric>

int n;
vi num;

inline bool valid(int x) {
	unordered_set<int> st;
	for (int i = 0; i <= x; ++i)
		st.insert(round((i * 100.0) / double(x)));
	for (int i = 0; i < n; ++i)
		if (st.find(num[i]) == st.end())
			return false;
	return true;
}

int BS() {
	for (int i = 1; i < 10000; i++) {
		if (valid(i))
			return i;
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	cin >> n;
	num.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> num[i];
	}
	cout << BS() << endl;
}