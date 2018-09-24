// 2016-2017 CT S03E01 Codeforces Trainings Season 3 Episode 1 - 2010 Benelux Algorithm Programming Contest (BAPC 10)
// 101078L

#include <bits/stdc++.h>
#include <ext/hash_map>
#include <ext/numeric>

using namespace std;
using namespace __gnu_cxx;

typedef long long ll;

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
//  freopen("in.txt", "rt", stdin);
//  freopen("out.txt", "wt", stdout);
#endif
	string s;
	cin >> s;
	double res = 0;
	int n = s.size();
	for (int i = 0; i < n; i++) {
		if (s[i] == '1') {
			for (int j = n - 1; j > i; j--) {
				if (s[j] == '0') {
					res += sqrt(j - i);
					swap(s[i], s[j]);
					break;
				}
			}
		}
	}
	cout << fixed << setprecision(9) << res << endl;
	return 0;
}
