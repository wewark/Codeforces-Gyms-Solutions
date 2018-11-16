// 2016-2017 ACM-ICPC CHINA-Final
// 101194L

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
const ll MOD = 1e9 + 7;
const long double EPS = 1e-5;
#define all(x) x.begin(),x.end()
#define SZ(x) (int)(x).size()

#include <ext/hash_set>
#include <ext/numeric>

#define  fr first
#define  sc second

int cnt;
vii v;
vii val;
int freq[5], arr[5];

void bk(int idx) {
	if (idx == v.size()) {
		bool flag = true;
		for (int i = 0; i < 4; i++) {
			if (freq[i] != arr[i])
				flag = false;
		}
		cnt += flag;
		return;
	}

	for (auto p : val) {
		freq[v[idx].first] += p.first;
		freq[v[idx].second] += p.second;
		bk(idx + 1);
		freq[v[idx].first] -= p.first;
		freq[v[idx].second] -= p.second;
	}
}

int main() {
//	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	for (int i = 0; i < 4; ++i) {
		for (int j = i + 1; j < 4; ++j) {
			v.push_back({i, j});
		}
	}

	val.push_back({3, 0});
	val.push_back({0, 3});
	val.push_back({1, 1});
	int t, cases = 1;

	scanf("%d", &t);
	while (t--) {
		printf("Case #%d: ",cases++);
		for (int i = 0; i < 4; ++i) {
			scanf("%d", &arr[i]);
		}
		cnt = 0;
		memset(freq, 0, sizeof freq);
		bk(0);
		if(cnt == 1)puts("Yes");
		else if(cnt > 1)puts("No");
		else puts("Wrong Scoreboard");
	}
	return 0;
}