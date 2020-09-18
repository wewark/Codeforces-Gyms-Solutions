// 2009-2010 VI International Zhautykov Olympiad
// 100143B

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

#define LSOne(S) (S & (-S))
const int N = 3e7 + 7;

vi b[32];
void compDP() {
	for (int i = 1; i < N; ++i) {
		b[__builtin_popcount(i)].push_back(i);
	}
}

vi primes;
vb isprime(N + 5, true);
void precompPrimes() {
	for (ll i = 2; i <= N; i++)
		if (isprime[i])
			for (ll j = i * i; j <= N; j += i)
				isprime[j] = false;
	for (int i = 2; i <= N; ++i) {
		if (isprime[i])
			primes.push_back(i);
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#else
	freopen("monster.in", "r", stdin);
	freopen("monster.out", "w", stdout);
#endif

//	memset(mem, -1, sizeof(mem));
	precompPrimes();
	compDP();
	int k, n; cin >> k >> n;
	for (int i = 0; i < n; ++i) {
		int x; cin >> x;
		if (x == 1) {
			k--;
			continue;
		}
		if (x % 2) {
			k--;
			auto it = lower_bound(all(primes), x);
			it--;
			k += *it;
			k = min(k, int(3e7));
		} else {
			int pc = __builtin_popcount(x);
			auto it = upper_bound(all(b[pc]), k);
			k -= it - b[pc].begin();
		}
	}
	cout << k << endl;
}
