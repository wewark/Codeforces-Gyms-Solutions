// III (XIV) Volga Region Open Team Student Programming Contest
// 100186D

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
const int di[] = {0, 0, 1, -1};
const int dj[] = {1, -1, 0, 0};
const ll MOD = 1e9 + 7;
const long double EPS = 1e-5;
#define all(x) x.begin(),x.end()

#include <ext/hash_set>
#include <ext/numeric>

const int N = 1003;

int d, n, m;
ll a[N][N];
ll s[N][N];

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> d >> n >> m;
	for (int i = 0; i < d; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			s[i][j + 1] = s[i][j] + a[i][j];
		}
	}
	ll ans = -1;
	int idx = -1;
	for (int j = 0; j <= n - m; j++) {
		ll cur = 0;
		for (int i = 0; i < d; i++) {
			cur += s[i][j + m] - s[i][j];
		}
//		cout << j + 1 << " " << cur << endl;
		if (cur > ans) {
			ans = cur;
			idx = j + 1;
		}
	}
	cout << idx << " " << ans << endl;
	return 0;
}
