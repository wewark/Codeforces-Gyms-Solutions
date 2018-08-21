// 100694 - 2015, VIII Samara Regional Intercollegiate Programming Contest
// 100694E

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
const ll MOD = 998244353;
const ll INF = 1e9;
const double EPS = 1e-5;
#define mp make_pair
#define all(x) x.begin(),x.end()

struct Desk {
	int idx;
	int np = 0, p1 = 0, p2 = 0;
	double average = 0;

	Desk(int _idx) {
		idx = _idx;
	}

	void add(int cust) {
		if (np == 0) p1 = p2 = cust;
		else if (np == 1) p2 = cust;
		else p1 = p2, p2 = cust;
		np++;
		average = ((p1 + p2) / 2.0) * (double)np;
	}

	bool operator < (Desk other) const {
		if (average != other.average)
			return average > other.average;
		return idx > other.idx;
	}
};

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int n, k; cin >> n >> k;

	priority_queue<Desk> pq;
	for (int i = 0; i < k; i++)
		pq.push(Desk(i));

	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		Desk cur = pq.top(); pq.pop();
		cur.add(x);
		pq.push(cur);
		cout << cur.idx + 1 << " \n"[i == n - 1];
	}
	cin.ignore(), cin.get();
}
