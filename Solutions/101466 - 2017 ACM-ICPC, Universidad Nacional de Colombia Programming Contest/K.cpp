// 101466 - 2017 ACM-ICPC, Universidad Nacional de Colombia Programming Contest
// 101466K

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
const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, 1, 0, -1 };
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const double EPS = 1e-5;
#define mp make_pair
#define all(x) x.begin(),x.end()

#define LSOne(S) (S & (-S))

ll bigmod(ll a, int p, int m) {
	if (p == 0)
		return 1;
	if (p % 2 == 1)
		return ((a % m) * (bigmod(a, p - 1, m) % m)) % m;
	ll c = bigmod(a, p / 2, m);
	return (c * c) % m;
}

class FenwickTreeSum {
private:
	vll ft;

public:
	FenwickTreeSum() {}
	// initialization: n + 1 zeroes, ignore index 0
	FenwickTreeSum(int n) { ft.assign(n + 1, 0); }

	ll rsq(int b) {                                     // returns RSQ(1, b)
		ll sum = 0; for (; b; b -= LSOne(b)) sum += ft[b], sum %=MOD;
		return sum;
	}

	ll rsq(int a, int b) {                              // returns RSQ(u, b)
		return rsq(b) - (a == 1 ? 0 : rsq(a - 1));
	}

	// adjusts value of the k-th element by v (v can be +ve/inc or -ve/dec)
	void adjust(int k, int v) {                    // note: n = ft.size() - 1
		for (; k < (int)ft.size(); k += LSOne(k)) ft[k] += v, ft[k] %= MOD;
	}
};

class FenwickTreeMult {
private:
	vll ft;

public:
	FenwickTreeMult() {}
	// initialization: n + 1 zeroes, ignore index 0
	FenwickTreeMult(int n) { ft.assign(n + 1, 1); }

	ll rsq(int b) {                                     // returns RSQ(1, b)
		ll sum = 1; for (; b; b -= LSOne(b)) sum *= ft[b], sum %= MOD;
		return sum;
	}

	ll rsq(int a, int b) {                              // returns RSQ(u, b)
		return (rsq(b) * bigmod((a == 1 ? 1 : rsq(a - 1)), MOD - 2, MOD)) % MOD;
	}

	// adjusts value of the k-th element by v (v can be +ve/inc or -ve/dec)
	void adjust(int k, int v) {                    // note: n = ft.size() - 1
		for (; k < (int)ft.size(); k += LSOne(k)) ft[k] *= v, ft[k] %= MOD;
	}
};

int n;
vvi adj;
vi node, range;

void dfs(int cur, int& num) {
	node[cur] = num++;
	for (int i = 0; i < adj[cur].size(); i++)
		dfs(adj[cur][i], num);
	range[node[cur]] = num - 1;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int n; cin >> n;
	adj.assign(n, vi());
	for (int i = 0; i < n - 1; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
	}

	node.resize(n), range = node;
	int tmp = 0;
	dfs(0, tmp);

	int primes[] = { 2,3,5,7,11,13 };
	FenwickTreeMult ftm(n);
	vector<FenwickTreeSum> fts(6, FenwickTreeSum(n));
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		ftm.adjust(node[i] + 1, x);
		for (int j = 0; j < 6; j++) {
			int cnt = 0;
			while (x % primes[j] == 0)
				x /= primes[j], cnt++;
			fts[j].adjust(node[i] + 1, cnt);
		}
	}

	int q; cin >> q;
	while (q--) {
		string s; cin >> s;
		if (s == "RAND") {
			int u; cin >> u; u = node[u];
			cout << ftm.rsq(u + 1, range[u] + 1) << " ";
			ll r = 1;
			for (int i = 0; i < 6; i++) {
				r *= fts[i].rsq(u + 1, range[u] + 1) + 1;
				r %= MOD;
			}
			cout << r << endl;
		}
		else {
			int u, x; cin >> u >> x; u = node[u];
			ftm.adjust(u + 1, x);
			for (int i = 0; i < 6; i++) {
				int cnt = 0;
				while (x % primes[i] == 0)
					x /= primes[i], cnt++;
				fts[i].adjust(u + 1, cnt);
			}
		}
	}
	cin.ignore(), cin.get();
}
