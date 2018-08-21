// 100285 - 2013-2014 ACM-ICPC, NEERC, Eastern Subregional Contest
// 100285F

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
const ll INF = 1e8;
const long double EPS = 1e-6;
#define mp make_pair
#define all(x) x.begin(),x.end()

#define LSOne(S) (S & (-S))

class FenwickTree {
private:
	vi ft;

public:
	FenwickTree() {}
	// initialization: n + 1 zeroes, ignore index 0
	FenwickTree(int n) { ft.assign(n + 1, 0); }

	int rsq(int b) {                                     // returns RSQ(1, b)
		int sum = 0; for (; b; b -= LSOne(b)) sum += ft[b];
		return sum;
	}

	int rsq(int a, int b) {                              // returns RSQ(a, b)
		return rsq(b) - (a == 1 ? 0 : rsq(a - 1));
	}

	// adjusts value of the k-th element by v (v can be +ve/inc or -ve/dec)
	void adjust(int k, int v) {                    // note: n = ft.size() - 1
		for (; k < (int)ft.size(); k += LSOne(k)) ft[k] += v;
	}
};

int n, k, p;
vi num, cum;
FenwickTree ftr(1e5 + 5);

inline bool valid(int x, int i) {
	return ftr.rsq(x - 1) * 100 >= p * i;
}

int bs(int i) {
	int a = 1, b = 1e5 + 5, mid = (a + b) / 2;
	while (a < b) {
		if (valid(mid, i))
			b = mid;
		else
			a = mid + 1;
		mid = (a + b) / 2;
	}
	return mid;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> k >> p;
	num.assign(n, 1);

	ftr.adjust(1, n - k);
	ll sum = n - k;
	for (int i = n - k; i < n; i++) {
		if (!i) {
			ftr.adjust(1, 1);
			sum++;
			continue;
		}
		num[i] = bs(i);
		ftr.adjust(num[i], 1);
		sum += num[i];
	}
	cout << sum << endl;
	for (int i = 0; i < n; i++) {
		cout << num[i] << " \n"[i == n - 1];
	}

	cin.ignore(), cin.get();
}
