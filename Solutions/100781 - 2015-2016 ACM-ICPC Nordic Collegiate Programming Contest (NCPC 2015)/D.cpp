// 2015-2016 ACM-ICPC Nordic Collegiate Programming Contest (NCPC 2015)
// 100781D

#include <bits/stdc++.h>
#include <ext/hash_map>
#include <ext/hash_set>

#define fr first
#define sc second

using namespace __gnu_cxx;
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<ll, ll> pii;
const int MOD = 1e9 + 7;



int main() {
	ios::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
#endif
	int n, k; cin >> n >> k;
	queue<int> q;
	int r = 0;
	for (int i = 0; i < n; ++i) {
		int cur; cin >> cur;
		while (!q.empty() && cur - q.front() >= 1000)
			q.pop();
		q.push(cur);
		r = max(r, ((int)q.size() + k - 1) / k);
	}
	cout << r << endl;
}