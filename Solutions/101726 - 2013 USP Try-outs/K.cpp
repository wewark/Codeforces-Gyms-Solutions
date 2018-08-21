// 101726 - 2013 USP Try-outs
// 101726K

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
const int di[] = { -1, 0, 1, 0, -1, 1, 1, -1 };
const int dj[] = { 0, 1, 0, -1, -1, 1, -1, 1 };
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const long double EPS = 1e-9;
#define all(x) x.begin(),x.end()

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vii num(n);
		for (int i = 0; i < n; i++) {
			cin >> num[i].first >> num[i].second;
		}
		sort(all(num));

		int cur = 0;
		for (int i = 0; i < n; i++) {
			if (cur <= num[i].first)
				cur = num[i].first + num[i].second;
			else
				cur += num[i].second;
		}
		cout << cur << endl;
	}
	cin.ignore(), cin.get();
}
