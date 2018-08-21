// 100694 - 2015, VIII Samara Regional Intercollegiate Programming Contest
// 100694H

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
const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, 1, 0, -1 };
const ll MOD = 998244353;
const ll INF = 1e9;
const double EPS = 1e-5;
#define mp make_pair
#define all(x) x.begin(),x.end()

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int n; cin >> n;
	int mx = -1;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		mx = max(mx, x);
	}
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
	}

	int k; cin >> k;
	int r = 0;
	for (int i = 0; i < k; i++) {
		int x; cin >> x;
		r += x + mx;
	}
	cout << r << endl;
	cin.ignore(), cin.get();
}
