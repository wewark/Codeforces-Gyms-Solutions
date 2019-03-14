// 2009-2010 Winter Petrozavodsk Camp Andrew Stankevich Contest 37 (ASC 37)
// 100431D

#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
typedef long long ll;
typedef pair<int, int> pii;

const int N = 202;

int n, x;
vector<int> v[N];
vector<int> net[N];

int main() {
	std::ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	freopen("bubble.in", "rt", stdin);
	freopen("bubble.out", "wt", stdout);

	cin >> n;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			cin >> x;
			v[i].push_back(x);
			net[i].push_back(x);
		}
		reverse(net[i].begin(), net[i].end());
	}
	vector<int> a(n + 1);
	iota(a.begin(), a.end(), 1);
	for (int i = 1; i < n; i++) {
		for (int j = n - 1; j >= i; j--) {
			if (v[j].back()) {
				swap(a[j], a[j - 1]);
			}
			v[j].pop_back();
		}
	}
	vector<int> res = a;
//	for (int i = 0; i < n; i++)
//		cout << res[i] << " \n"[i == n - 1];
	for (int i = 1; i < n; i++) {
		for (int j = n - 1; j >= i; j--) {
			if (net[j].back()) {
				if (a[j] > a[j - 1]) {
					cout << "NO\n";
					return 0;
				}
				swap(a[j], a[j - 1]);
			} else {
				if (a[j] < a[j - 1]) {
					cout << "NO\n";
					return 0;
				}
			}
			net[j].pop_back();
		}
	}
	cout << "YES\n";
	for (int i = 0; i < n; i++)
		cout << res[i] << " \n"[i == n - 1];
	return 0;
}
