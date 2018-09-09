// 2015-2016 XVI Open Cup, Grand Prix of Bashkortostan, SKB Kontur Cup Stage 2
// 100917L

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
const ll INF = 1e9;
const long double EPS = 1e-6;
#define all(x) x.begin(),x.end()
#define x first
#define y second

#include <ext/hash_set>
#include <ext/numeric>

using namespace __gnu_cxx;

typedef pair<int, int> pii;

struct _hash {
	int operator()(const pii &key) const {
		return key.first * 31 + key.second;
	}
};

hash_set<pii, _hash> S;

typedef pair<ll, ll> pdd;

bool inf;
set<long long> s;

long long solve(long long n) {
	if (n == 1)return 0;
	if (s.find(n) != s.end()) {
		cout << "-1\n";
		exit(0);
	}

	s.insert(n);
	if (n & 1) {
		return (n + 1) / 2 + (n + 1) / 2 + solve((n + 1) / 2 * 3 - 1);
	}
	else {
		return n + solve(n / 2);
	}
}


int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	long long n;cin >> n;
	long long ans = solve(n);
	cout << ans << "\n";
}