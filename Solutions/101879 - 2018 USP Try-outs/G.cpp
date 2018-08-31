// 2018 USP Try-outs
// 101879G

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
const int di[] = { 0, 0, 1, -1 };
const int dj[] = { 1, -1, 0, 0 };
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const long double EPS = 1e-6;
#define all(x) x.begin(),x.end()
#define fr first
#define sc second

class SegmentTree {
private: vii st, A;
		 int n;
		 int left(int p) { return p << 1; }
		 int right(int p) { return (p << 1) + 1; }

		 static pii intersect(pii& a, pii& b) {
			 pii ret(max(a.first, b.first), min(a.second, b.second));
			 if (ret.first > ret.second)
				 return pii(-INF, -INF - 1);
			 return ret;
		 }

		 void build(int p, int L, int R) {
			 if (L == R)
				 st[p] = A[L];
			 else {
				 build(left(p), L, (L + R) / 2);
				 build(right(p), (L + R) / 2 + 1, R);
				 pii p1 = st[left(p)], p2 = st[right(p)];
				 st[p] = intersect(p1, p2);
			 }
		 }

		 pii rmq(int p, int L, int R, int i, int j) {
			 if (i > R || j < L) return pii(-INF, INF);
			 if (L >= i && R <= j) return st[p];

			 pii p1 = rmq(left(p), L, (L + R) / 2, i, j);
			 pii p2 = rmq(right(p), (L + R) / 2 + 1, R, i, j);

			 return intersect(p1, p2);
		 } 

		 pii update_point(int p, int L, int R, int idx, pii new_value) {
			 int i = idx, j = idx;

			 if (i > R || j < L)
				 return st[p];

			 if (L == i && R == j) {
				 A[i] = new_value;
				 return st[p] = A[L];
			 }

			 pii p1, p2;
			 p1 = update_point(left(p), L, (L + R) / 2, idx, new_value);
			 p2 = update_point(right(p), (L + R) / 2 + 1, R, idx, new_value);

			 return st[p] = intersect(p1, p2);
		 }

public:
	SegmentTree(const vii &_A) {
		A = _A; n = (int)A.size();
		st.assign(4 * n, pii(-INF, -INF - 1));
		build(1, 0, n - 1);
	}

	pii rmq(int i, int j) { return rmq(1, 0, n - 1, i, j); }

	pii update_point(int idx, pii new_value) {
		return update_point(1, 0, n - 1, idx, new_value);
	}
};

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int n, q; cin >> n >> q;
	vii num(n);
	for (int i = 0; i < n; i++) {
		cin >> num[i].first >> num[i].second;
	}

	SegmentTree sgt(num);
	while (q--) {
		char type; cin >> type;
		if (type == '?') {
			int l, r; cin >> l >> r;
			l--, r--;
			pii rng = sgt.rmq(l, r);
			cout << rng.second - rng.first + 1 << endl;
		}
		else {
			int i, l, r; cin >> i >> l >> r; i--;
			sgt.update_point(i, pii(l, r));
		}
	}
}
