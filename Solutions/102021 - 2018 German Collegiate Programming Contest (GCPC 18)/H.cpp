// 2018 German Collegiate Programming Contest (GCPC 18)
// 102021H

#include <bits/stdc++.h>
#include <ext/numeric>
using namespace std;
using namespace __gnu_cxx;
#define SZ(x) ((int)(x).size())
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1003;

int main() {
	std::ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	ll cnt;
	cin >> cnt;
	if (cnt == 1) {
		cout << "3 1\n";
		return 0;
	}
	for (ll i = 2; power(2LL, i) < cnt; i++) {
		ll res = 1;
		ll stp = 2;
		while (res < cnt) {
			res += power(stp, i);
			stp++;
		}
		if (res == cnt) {
			cout << i + 1 << " " << stp - 1 << "\n";
			return 0;
		}
	}
	cout << "impossible\n";
	return 0;
}
