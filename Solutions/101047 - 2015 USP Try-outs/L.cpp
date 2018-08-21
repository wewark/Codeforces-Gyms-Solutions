// 101047 - 2015 USP Try-outs
// 101047L

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
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};
const ll MOD = 1e9 + 7;
const ll INF = 1e8;
const long double EPS = 1e-10;

#define all(x) x.begin(),x.end()

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
//	freopen("input.txt", "r", stdin);
//	freopen("cube.in", "r", stdin);
//	freopen("cube.out", "w", stdout);

	int t; cin >> t;
	while (t--) {
		int a, b; cin >> a >> b;
		if (!a && !b) {
			cout << 0 << endl;
			continue;
		}
		ll r = 1;
		while (a--) r *= 26;
		while (b--) r *= 10;
		cout << r << endl;
	}

}