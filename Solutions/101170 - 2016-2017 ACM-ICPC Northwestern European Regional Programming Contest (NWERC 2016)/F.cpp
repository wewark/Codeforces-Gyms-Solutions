#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<ll, ll> pii;
typedef vector<pii> vii;
typedef vector<bool> vb;
typedef vector<string> vs;
const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, 1, 0, -1 };
const ll MOD = 5e6;
const ll INF = 1e9;
const double EPS = 1e-6;
#define mp make_pair
#define all(x) x.begin(),x.end()

class SparseTable
{
private:
	vi A;
	vvi st; // Sparse Table (N * log(N))

public:
	SparseTable() {}
	SparseTable(const vi& _A) {
		build(_A);
	}

	void build(const vi& _A) {
		st.assign(_A.size(), vi(log2(_A.size()) + 1));
		A = _A;

		int i, j;
		// initialize st for the intervals with length 1
		for (i = 0; i < A.size(); i++)
			st[i][0] = i;
		//compute values from smaller to bigger intervals
		for (j = 1; (1 << j) <= A.size(); j++)
			for (i = 0; i + (1 << j) - 1 < A.size(); i++)
				if (A[st[i][j - 1]] > A[st[i + (1 << (j - 1))][j - 1]])
					st[i][j] = st[i][j - 1];
				else
					st[i][j] = st[i + (1 << (j - 1))][j - 1];
	}

	int rmq(int i, int j) {
		int k = log2(j - i + 1);
		if (A[st[i][k]] > A[st[j - (1 << k) + 1][k]])
			return A[st[i][k]];
		else
			return A[st[j - (1 << k) + 1][k]];
	}
};

struct Dumbell {
	int r1 = -1, r2 = -1;
	int p1, p2;
};

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int n; cin >> n;
	map<int, Dumbell> m;
	vvi num(2, vi(n));

	for (int rw = 1; rw <= 2; rw++) {
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			num[rw - 1][i] = x;
			if (m[x].r1 == -1)
				m[x].r1 = rw, m[x].p1 = i;
			else
				m[x].r2 = rw, m[x].p2 = i;
		}
	}

	SparseTable sp1(num[0]), sp2(num[1]);

	int mx = 0;
	for (auto& i : m) {
		if (i.second.r1 != i.second.r2)
			mx = max(mx, i.first);
		else if (i.second.p2 - i.second.p1 > 1) {
			int mn = min(i.first, i.second.r1 == 1 ? sp1.rmq(i.second.p1 + 1, i.second.p2 - 1) : sp2.rmq(i.second.p1 + 1, i.second.p2 - 1));
			mx = max(mx, mn);
		}
	}

	cout << mx << endl;
	cin.ignore(), cin.get();
}
