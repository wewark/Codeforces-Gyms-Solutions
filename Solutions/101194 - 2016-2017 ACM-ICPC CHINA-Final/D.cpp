// 2016-2017 ACM-ICPC CHINA-Final
// 101194D

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
const ll MOD = 1e9 + 7;
const long double EPS = 1e-5;
#define all(x) x.begin(),x.end()
#define SZ(x) (int)(x).size()

#include <ext/hash_set>
#include <ext/numeric>

#define  fr first
#define  sc second

const int N = 3e5 + 5;
ll arr[N], cur[N];
int cnt[N];
int n, k;

bool valid(int x) {
	int idx = 0;
	for (int i = 0; i < x; i++) {
		cur[i] = arr[i];
		cnt[i] = 1;
	}

	for (int i = x; i < n; ++i) {
		if (arr[i] >= cur[idx] * 2) {
			cur[idx] = arr[i];
			cnt[idx]++;
			idx++;
			if (idx == x)idx = 0;
		}
	}
//	cout << x << " " << (cnt[x-1] >= k) << endl;
	return cnt[x-1] >= k;
}

int bs(int s, int e) {
	while (s < e) {
		int mid = s + (e - s + 1) / 2;
		if (valid(mid))
			s = mid;
		else
			e = mid - 1;
	}
	return s;
}

int main() {
//	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int t, cases = 1;

	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &k);
		for (int i = 0; i < n; i++) {
			scanf("%lld", &arr[i]);
		}
		sort(arr, arr + n);
		printf("Case #%d: %d\n", cases++, bs(0, n));
	}
	return 0;
}