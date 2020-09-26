// 2009-2010 VI International Zhautykov Olympiad
// 100143C - Dynamic programming, Path building

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vb = vector<bool>;
using pii = pair<int, int>;
using vii = vector<pii>;
using vs = vector<string>;
#define all(x) x.begin(), x.end()
// int di[] = {0, 1, 0, -1};
// int dj[] = {1, 0, -1, 0};
const ll MOD = 998244353;
const ll INF = 1e9;

const int N = 18;
int n, c, k;
int s[N], cost[N], req[102];

int mem[102][1 << N];
int solve(int idx, int msk) {
	if (idx == k) return 0;

	int& ret = mem[idx][msk];
	if (~ret) return ret;
	ret = INF;

	if (msk & (1 << req[idx]))
		ret = solve(idx + 1, msk);
	else {
		int used = 0;
		for (int i = 0; i < n; ++i) {
			if (msk & (1 << i))
				used += s[i];
		}

		if (c - used >= s[req[idx]])
			ret = cost[req[idx]] + solve(idx + 1, msk | (1 << req[idx]));
		else {
			for (int i = 0; i < n; ++i) {
				if (msk & (1 << i))
					ret = min(ret, solve(idx, msk & ~(1 << i)));
			}
		}
	}
	return ret;
}

vvi ans;
void build(int idx, int msk) {
	if (idx == k) return;

	int ret = INF, nxtMsk = -1, nxtIdx = idx + 1;
	int deleted = -1;

	if (msk & (1 << req[idx])) {
		ret = solve(idx + 1, msk);
		nxtMsk = msk;
	} else {
		int used = 0;
		for (int i = 0; i < n; ++i) {
			if (msk & (1 << i))
				used += s[i];
		}

		if (c - used >= s[req[idx]]) {
			ret = cost[req[idx]] + solve(idx + 1, msk | (1 << req[idx]));
			nxtMsk = msk | (1 << req[idx]);
		} else {
			for (int i = 0; i < n; ++i) {
				if (msk & (1 << i)) {
					int x = solve(idx, msk & ~(1 << i));
					if (x < ret) {
						ret = x;
						nxtMsk = msk & ~(1 << i);
						deleted = i;
						nxtIdx = idx;
					}
				}
			}
		}
	}

	if (~deleted)
		ans[idx].push_back(deleted);
	build(nxtIdx, nxtMsk);
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#else
	freopen("cache.in", "r", stdin);
	freopen("cache.out", "w", stdout);
#endif

	memset(mem, -1, sizeof(mem));

	cin >> n >> c >> k;
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> cost[i];
	}
	for (int i = 0; i < k; ++i) {
		cin >> req[i]; req[i]--;
	}

	cout << solve(0, 0) << endl;
	ans.assign(k, vi());
	build(0, 0);
	for (int i = 0; i < k; ++i) {
		cout << ans[i].size();
		for (int j : ans[i]) {
			cout << " " << j + 1;
		}
		cout << endl;
	}
}
