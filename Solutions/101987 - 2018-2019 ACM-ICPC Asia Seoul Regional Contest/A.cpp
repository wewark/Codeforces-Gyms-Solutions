// 2018-2019 ACM-ICPC Asia Seoul Regional Contest
// 101987A

#include <bits/stdc++.h>
#include <ext/hash_set>
#include <ext/numeric>

using namespace __gnu_cxx;
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;
using vb = vector<bool>;
using vs = vector<string>;
const int MOD = int(1e9 + 7);
const long double EPS = 1e-4;
const double PI = 3.1415926535897932384626433;
const ll INF = ll(1e9);
int di[] = {0, 0, 0, 1, -1, 1, -1, 1, -1};
int dj[] = {0, 1, -1, 0, 0, 1, -1, -1, 1};
#define all(x) x.begin(),x.end()

#define FOR(i, a, b) for(int i=(a);i<(b);i++)
#define pb push_back
#define sz(v) (int)v.size()
#define all(c) (c).begin(),(c).end()
#define mem(s, v) memset(s,v,sizeof(s))
typedef vector<int> vi;


const int N = 2e5 + 5;
const int M = N << 2;
int seg[M], lazy[M];
int dp[N];

void build(int id = 1, int s = 0, int e = N - 1) {
	if (s == e) {
		seg[id] = dp[s];
		return;
	}
	int mid = (s + e) / 2;
	build(id * 2, s, mid);
	build(id * 2 + 1, mid + 1, e);
	seg[id] = max(seg[id * 2], seg[id * 2 + 1]);
}

void update(int id, int val) {
	seg[id] += val;
	lazy[id] += val;
}

void shift(int id) {
	if (lazy[id]) {
		update(id * 2, lazy[id]);
		update(id * 2 + 1, lazy[id]);
		lazy[id] = 0;
	}
}


void increase(int l, int r, int id = 1, int s = 0, int e = N - 1) {
	if (l <= s && e <= r) {
		update(id, -1);
		return;
	}

	if (l > e || r < s)return;
	shift(id);
	int mid = (s + e) / 2;
	increase(l, r, id * 2, s, mid);
	increase(l, r, id * 2 + 1, mid + 1, e);
	seg[id] = max(seg[id * 2], seg[id * 2 + 1]);
}

vi adj[N];
pii arr[N];
int n;


int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	cin >> n;
	int a, b;
	vi v;
	for (int i = 0; i < n; i++) {
		cin >> a >> arr[i].second >> b >> arr[i].first;
		v.push_back(arr[i].first);
		v.push_back(arr[i].second);
	}

	sort(all(v));
	v.resize(unique(all(v)) - v.begin());
	for (int i = 0; i < n; i++) {
		arr[i].first = lower_bound(all(v), arr[i].first) - v.begin();
		arr[i].second = lower_bound(all(v), arr[i].second) - v.begin();
		adj[arr[i].first].push_back(arr[i].second);
		dp[arr[i].first]++;
		dp[arr[i].second + 1]--;
	}

	for (int i = 1; i < N; i++)
		dp[i] += dp[i - 1];

	build();
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int e : adj[i]) {
			increase(i, e);
		}
		ans = max(ans, dp[i] + seg[1]);
	}

	cout << ans << endl;


	return 0;
}
