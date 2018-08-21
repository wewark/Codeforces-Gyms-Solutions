// 101047 - 2015 USP Try-outs
// 101047G

#include <bits/stdc++.h>
#include <ext/numeric>

using namespace std;
using namespace __gnu_cxx;

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
const ll INF = 1e9;
const long double EPS = 1e-10;

#ifndef M_PI
#define M_PI 3.1415926535897932384626433832795
#endif

#define FOR(i, a, b) for(int i=(a);i<(b);i++)
#define pb push_back
#define sz(v) (int)v.size()
#define all(c) (c).begin(),(c).end()


const int N = 3e3 + 3;
pair<int, int> arr[N];
int n, k, cur;
long long h;

void f(priority_queue<pair<int, pair<int, int> > > &pq) {
	while (cur < n && h > arr[cur].first) {
		int x = arr[cur].first, y = arr[cur].second;
		pq.push({y - x, {x, y}});
		cur++;
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
//	freopen("cube.in", "r", stdin);
//	freopen("cube.out", "w", stdout);

	int t;
	cin >> t;
	while (t--) {
		ll n, k; cin >> n >> k;
//		if (!k) {
//			cout << "Y\n"; continue;
//		}
		for (int i = 0; i < k; ++i) {
			ll x; cin >> x;
			ll g;
			while ((g = __gcd(x, n)) != 1)
				n /= g;
		}
		cout << (n == 1 ? "Y" : "N") << endl;
	}

	return 0;
}