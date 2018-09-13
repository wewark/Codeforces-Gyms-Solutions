// 2017 ACM Jordanian Collegiate Programming Contest
// 101608G

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
const int di[] = { 0,0,1,-1,1,-1,-1,1 };
const int dj[] = { 1,-1,0,0,1,-1,1,-1 };
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const long double EPS = 1e-6;
#define all(x) x.begin(),x.end()

class SegmentTree {
private:
	vi st, A;
	int n;
	int left(int p) { return p << 1; }
	int right(int p) { return (p << 1) + 1; }

	void build(int p, int L, int R) {
		if (L == R)
			st[p] = A[L];
		else {
			build(left(p), L, (L + R) / 2);
			build(right(p), (L + R) / 2 + 1, R);
			int p1 = st[left(p)], p2 = st[right(p)];
			st[p] = p1 | p2;
		}
	}

	int rmq(int p, int L, int R, int i, int j) {
		if (i > R || j < L) return 0;
		if (L >= i && R <= j) return st[p];

		int p1 = rmq(left(p), L, (L + R) / 2, i, j);
		int p2 = rmq(right(p), (L + R) / 2 + 1, R, i, j);

		return p1 | p2;
	}

public:
	SegmentTree(const vi& _A) {
		A = _A; n = (int)A.size();
		st.assign(4 * n, 0);
		build(1, 0, n - 1);
	}

	int rmq(int i, int j) { return rmq(1, 0, n - 1, i, j); }
};

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	ifstream cin("wifi.in");
	int t; cin >> t;
	while (t--) {
		int n, v; cin >> n >> v;
		vi num(n);
		for (int i = 0; i < n; i++) {
			cin >> num[i];
		}
		
		SegmentTree sgt(num);
		int a = 0, b = 0;
		int r = 0;
		while (a < n) {
			while (b < n && sgt.rmq(a, b) <= v) b++;
			r = max(r, b - a);
			a++;
			if (b < a) b++;
		}
		cout << r << endl;
	}
}
