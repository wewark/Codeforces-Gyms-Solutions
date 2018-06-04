#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<short, int> pii;
typedef vector<pii> vii;
typedef vector<bool> vb;
typedef vector<string> vs;
const int di[] = { -1,0,1,0 };
const int dj[] = { 0,1,0,-1 };
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
#define mp make_pair
#define all(x) x.begin(),x.end()

ll n, k;

int bs(int to) {
	int a = 0, b = to, mid = (a + b) / 2;
	while (a < b) {
		if (mid <= k)
			a = mid;
		else
			b = mid - 1;
		mid = ceil((a + b) / 2.0);
	}
	return mid;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> k;

	vi r(n, -1); vb vis(n);
	for (int i = 0; i < n; i++) {
		if (k <= n - i - 1) {
			int x = bs(n - i - 1);
			r[i++] = x;
			vis[x] = true;

			int a = 0;
			while (i < n) {
				while (vis[a]) a++;
				vis[a] = true;
				r[i++] = a;
			}
			break;
		}
		r[i] = n - i - 1;
		k -= n - i - 1;
	}
	for (int i = 0; i < n; i++)
		cout << r[i] + 1 << " \n"[i == n - 1];
	cin.ignore(), cin.get();
}
