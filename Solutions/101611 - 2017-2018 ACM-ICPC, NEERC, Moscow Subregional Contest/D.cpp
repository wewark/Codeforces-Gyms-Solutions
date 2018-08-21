// 101611 - 2017-2018 ACM-ICPC, NEERC, Moscow Subregional Contest
// 101611D

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<ll, ll> pii;
typedef vector<pii> vii;
typedef vector<bool> vb;
typedef vector<string> vs;
const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, 1, 0, -1 };
const ll MOD = 5e6;
const ll INF = 1e8;
const long double EPS = 1e-6;
#define mp make_pair
#define all(x) x.begin(),x.end()

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int n; cin >> n;
	vector<unsigned long long> num;
	for (int i = 0; i < n;) {
		unsigned long long x = 0, c = 0, xx;
		num.push_back(0);
		do {
			cin >> x;
			xx = x;
			if (xx >= 128) xx -= 128;
			num.back() += (xx << (c * 7));
			c++, i++;
		} while (x >= 128 && i < n);
	}

	for (int i = 0; i < num.size(); i++) {
		if (num[i] % 2 == 0)
			cout << num[i] / 2 << endl;
		else {
			ll r = num[i] / 2 + 1;
			cout << -r << endl;
		}
	}

	cin.ignore(), cin.get();
}
