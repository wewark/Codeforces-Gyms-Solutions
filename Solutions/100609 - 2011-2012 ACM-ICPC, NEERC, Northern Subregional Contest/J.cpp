// 100609 - 2011-2012 ACM-ICPC, NEERC, Northern Subregional Contest
// 100609J

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
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};
const int N = 1e6 + 7;
const ll MOD = 1e9 + 7;
const ll INF = 1e8;
const long double EPS = 1e-10;
#define mp make_pair
#define all(x) x.begin(),x.end()

#define LSOne(S) (S & (-S))

class BIT {
private:
	vi ft;

public:
	BIT() {}
	BIT(int n) { ft.assign(n + 1, 0); }

	int rsq(int b) {
		int sum = 0; for (; b; b -= LSOne(b)) sum += ft[b];
		return sum;
	}

	int rsq(int a, int b) {
		return rsq(b) - (a == 1 ? 0 : rsq(a - 1));
	}

	void adjust(int k, int v) {
		for (; k < (int)ft.size(); k += LSOne(k)) ft[k] += v;
	}
};

int n;
int c = 1;
map<int, int> m;

ll inversions(vii& num) {
	BIT bit1(c + 5), bit2(c + 5);
	ll ret = 0;
	for (int i = 0; i < n; ++i) {
		ret += bit1.rsq(num[i].first + 1, c + 2);
		bit1.adjust(num[i].first, 1);
		ret += bit2.rsq(num[i].second + 1, c + 2);
		bit2.adjust(num[i].second, 1);
	}
	return ret;
}

bool cmp(pii a, pii b) {
	if (a.second != b.second)
		return a.second < b.second;
	return a.first < b.first;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	freopen("john.in", "r", stdin);
	freopen("john.out", "w", stdout);
	cin >> n;
	vii num(n);
	for (int i = 0; i < n; ++i) {
		cin >> num[i].first >> num[i].second;
		m[num[i].first] = 0;
		m[num[i].second] = 0;
	}

	for (auto& i : m)
		i.second = c++;
	for (int i = 0; i < n; ++i) {
		num[i].first = m[num[i].first];
		num[i].second = m[num[i].second];
	}

	sort(all(num));
	ll r = inversions(num);
	sort(all(num), cmp);
	r = min(r, inversions(num));

	cout << r << endl;
}