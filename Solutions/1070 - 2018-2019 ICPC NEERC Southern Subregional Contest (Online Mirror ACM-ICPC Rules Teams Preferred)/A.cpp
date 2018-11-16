// 2018-2019 ICPC NEERC Southern Subregional Contest (Online Mirror ACM-ICPC Rules Teams Preferred)
// 1070A

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

struct _hash {
	int operator()(const pii &key) const {
		return key.first * 31 + key.second;
	}
};

int n, s;
unordered_map<pii, pii, _hash> P;
unordered_map<pii, int, _hash> ans;

void build(pii cur) {
	string res;
	while (cur.first != -1) {
		res += char(ans[cur] + '0');
		cur = P[cur];
	}
	reverse(all(res));
	cout << res << "\n";
}

void bfs() {
	queue<pii> Q;
	for (int i = 1; i < 10; i++) {
		Q.push({i, i % n});
		P[{i, i % n}] = {-1, -1};
		ans[{i, i % n}] = i;
	}
	while (!Q.empty()) {
		auto cur = Q.front();
		Q.pop();
		if (cur.first == s && cur.second == 0) {
			build(cur);
			return;;
		}
		for (int i = 0; i < 10; i++) {
			int nxt = (cur.second * 10 + i) % n;
			int ns = cur.first + i;
			if (ns > s || ans.find({ns, nxt}) != ans.end())
				continue;
			Q.push({ns, nxt});
			P[{ns, nxt}] = cur;
			ans[{ns, nxt}] = i;
		}
	}
	cout << "-1\n";
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	cin >> n >> s;
	bfs();
	return 0;
}