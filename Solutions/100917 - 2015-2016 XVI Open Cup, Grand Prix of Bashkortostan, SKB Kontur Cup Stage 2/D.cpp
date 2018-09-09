// 2015-2016 XVI Open Cup, Grand Prix of Bashkortostan, SKB Kontur Cup Stage 2
// 100917D

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<ll> vi;
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

class SegmentTree {
private:
	vi st, A;
	int n;
	int left(int p) { return p << 1; }
	int right(int p) { return (p << 1) + 1; }

	void build(int p, int L, int R) {
		if (L == R)
			st[p] = L;
		else {
			build(left(p), L, (L + R) / 2);
			build(right(p), (L + R) / 2 + 1, R);
			int p1 = st[left(p)], p2 = st[right(p)];
			st[p] = (A[p1] >= A[p2]) ? p1 : p2;
		}
	}

	int rmq(int p, int L, int R, int i, int j) {
		if (i > R || j < L) return -1;
		if (L >= i && R <= j) return st[p];

		int p1 = rmq(left(p), L, (L + R) / 2, i, j);
		int p2 = rmq(right(p), (L + R) / 2 + 1, R, i , j);

		if (p1 == -1) return p2;
		if (p2 == -1) return p1;
		return (A[p1] >= A[p2]) ? p1 : p2;
	}

	int update_point(int p, int L, int R, int idx, int new_value) {
		int i = idx, j = idx;

		if (i > R || j < L)
			return st[p];

		if (L == i && R == j) {
			A[i] = new_value;
			return st[p] = L;
		}

		int p1, p2;
		p1 = update_point(left(p), L, (L + R) / 2, idx, new_value);
		p2 = update_point(right(p), (L + R) / 2 + 1, R, idx, new_value);

		return st[p] = (A[p1] >= A[p2]) ? p1 : p2;
	}

public:
	SegmentTree(const vi& _A) {
		A = _A; n = (int)A.size();
		st.assign(4 * n, 0);
		build(1, 0, n - 1);
	}

	int rmq(int i, int j) { return rmq(1, 0, n - 1, i, j); }

	int update_point(int idx, int new_value) {
		return update_point(1, 0, n - 1, idx, new_value);
	}
};

ll n, w;
vector<ll> num;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	cin >> n >> w;
	num.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> num[i];
	}

	SegmentTree sgt(num);

	for (ll l = 1; l <= n; ++l) {
		ll cw = 0;
		for (ll i = 0; i < n; i += l) {
			cw += num[sgt.rmq(i, min(i + l - 1, n - 1))] + 1;
		}
		cw--;

		if (cw <= w) {
			cout << l << endl;
			return 0;
		}
	}

}