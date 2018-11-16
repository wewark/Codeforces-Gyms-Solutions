// 2013-2014 CT S01E07 Codeforces Trainings Season 1 Episode 7
// 100254L


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
#define SZ(x) (int)(x).size()

#include <ext/hash_set>
#include <ext/numeric>

#define  fr first
#define  sc second
typedef pair<int, pair<int, int>> piii;

ll r, c;
vi a, b; int idx; bool down;

ll solve() {
	ll ret = (c / 4) * 14;
	if (down) {
		for (int i = 0; i < c % 4; ++i)
			ret += a[(idx + i) % 4];
		idx = (idx + c - 1) % 4;
	}
	else {
		for (int i = 0; i < c % 4; ++i)
			ret += a[(idx - i + 4) % 4];
		idx = (idx - c + 1) % 4;
		idx += 4; idx %= 4;
	}

	vi an, bn;
	if (idx == 0) {
		an = { b[1],a[1],b[0],a[3] };
		bn = { a[0],a[2] };
	}
	else if (idx == 1) {
		an = { a[0],b[1],a[2],b[0] };
		bn = { a[1],a[3] };
	}
	else if (idx == 2) {
		an = { b[0],a[1],b[1],a[3] };
		bn = { a[2],a[0] };
	}
	else if (idx == 3) {
		an = { a[0],b[0],a[2],b[1] };
		bn = { a[3],a[1] };
	}

	a = an;
	b = bn;
	down = !down;
	return ret;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	cin >> r >> c;
	idx = 0, down = true;
	a = { 1,4,6,3 };
	b = { 2,5 };
	ll ans = 0;
	for (int i = 0; i < r; ++i) {
		ans += solve();
	}
	cout << ans << endl;
	return 0;
}

