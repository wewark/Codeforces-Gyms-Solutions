// 101572 - 2017-2018 ACM-ICPC Nordic Collegiate Programming Contest (NCPC 2017)
// 101572B

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
const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, 1, 0, -1 };
const ll MOD = 1e9 + 7;
const ll INF = 1e14;
const double EPS = 1e-5;
#define mp make_pair
#define all(x) x.begin(),x.end()

struct Player {
	string name;
	double a, b;

	bool operator < (Player other) const {
		return b < other.b;
	}
};

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int n; cin >> n;
	vector<Player> p(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i].name >> p[i].a >> p[i].b;
	}
	sort(all(p));

	int mxi = -1;
	double mx = INT_MAX;
	for (int i = 0; i < n; i++) {
		double cur = p[i].a;
		if (i <= 2)
			cur += p[3].b, cur -= p[i].b;
		for (int j = 0; j < 3; j++)
			cur += p[j].b;

		if (cur < mx)
			mx = cur, mxi = i;
	}

	cout << fixed << setprecision(6) << mx << endl;
	cout << p[mxi].name << endl;

	int limit = 3;
	for (int i = 0; i < limit; i++) {
		if (i == mxi) limit++;
		else cout << p[i].name << endl;
	}

	cin.ignore(), cin.get();
}
