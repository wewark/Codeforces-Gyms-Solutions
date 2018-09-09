// Arab Collegiate Programming Contest 2012
// 100155D

#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[102];

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
//	freopen("in.txt", "rt", stdin);
//	freopen("out.txt", "wt", stdout);
#endif
	int res = 0;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		res += a[i] / k;
	}
	cout << res << endl;
	return 0;
}
