// III (XIV) Volga Region Open Team Student Programming Contest
// 100186I

#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ll;
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

const int N = 55;
char str[N];

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n , m;
	scanf("%d%d%s",&n,&m,str);

	int one = 0, zero = 0, ans = 0;
	for (int i = 0; i < m; ++i) {
		if (one == n - 1 && i != m - 1) {
			zero++;
			continue;
		}

		if (zero == n - 1 && i != m - 1) {
			one++;
			continue;
		}

		if (i == m - 1) {
			ans += (one == n - 1 && zero == n - 1);
			continue;
		}

		int L = m - i;
		if (one + L == n && zero + L < n) break;
		if (one + L < n && zero + L == n) break;
		ans++;
		one += (str[i] == '1');
		zero += (str[i] == '0');
	}

	printf("%d\n",ans);

	return 0;
}