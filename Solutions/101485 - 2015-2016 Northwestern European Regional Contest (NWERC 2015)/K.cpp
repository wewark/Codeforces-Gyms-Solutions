// 101485 - 2015-2016 Northwestern European Regional Contest (NWERC 2015)
// 101485K

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
const ll INF = 1e9;
const double EPS = 1e-5;
const int N = 2e5 + 7;
#define mp make_pair
#define all(x) x.begin(),x.end()

ll r, s, m, d, n; vll ing; vvi sd, md, dd;
vector<vb> rst;
bool many = false;

inline bool overflow(ll x, ll y) {
	return x > 1e18 / y;
}

inline bool overflowp(ll x, ll y) {
	return x > 1e18 - y;
}

inline bool validDishes(int is, int im, int id) {
	return !rst[is][im + s] && !rst[is][id + s + m] && !rst[im + s][id + s + m];
}

ll combs(int is, int im, int id) {
	vi cs = sd[is], cm = md[im], cd = dd[id];

	set<int> st;
	for (int i = 0; i < cs.size(); i++)
		st.insert(cs[i]);
	for (int i = 0; i < cm.size(); i++)
		st.insert(cm[i]);
	for (int i = 0; i < cd.size(); i++)
		st.insert(cd[i]);

	ll ret = 1;
	for (auto i : st) {
		if (overflow(ret, ing[i])) {
			many = true; break;
		}
		ret *= ing[i];
	}

	return ret;
}

int main() {
	cin >> r >> s >> m >> d >> n;
	ing.resize(r);

	for (int i = 0; i < r; i++)
		cin >> ing[i];
	for (int i = 0; i < s; i++) {
		int sz; cin >> sz;
		sd.push_back(vll(sz));
		for (int j = 0; j < sz; j++)
			cin >> sd[i][j], sd[i][j]--;
	}
	for (int i = 0; i < m; i++) {
		int sz; cin >> sz;
		md.push_back(vll(sz));
		for (int j = 0; j < sz; j++)
			cin >> md[i][j], md[i][j]--;
	}
	for (int i = 0; i < d; i++) {
		int sz; cin >> sz;
		dd.push_back(vll(sz));
		for (int j = 0; j < sz; j++)
			cin >> dd[i][j], dd[i][j]--;
	}

	rst.resize(100, vb(100));
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b; a--, b--;
		rst[a][b] = rst[b][a] = true;
	}

	ll rs = 0;
	for (int is = 0; is < sd.size() && !many; is++)
		for (int im = 0; im < md.size() && !many; im++)
			for (int id = 0; id < dd.size() && !many; id++)
				if (validDishes(is, im, id)) {
					ll x = combs(is, im, id);
					if (overflowp(rs, x)) {
						many = true; break;
					}
					rs += combs(is, im, id);
				}

	if (many)
		cout << "too many\n";
	else
		cout << rs << endl;

	cin.ignore(), cin.get();
}
