// 101673 - 2017-2018 ACM-ICPC East Central North America Regional Contest (ECNA 2017)
// 101673J

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
const int di[] = { -1, 0, 1, 0, -1, 1, 1, -1 };
const int dj[] = { 0, 1, 0, -1, -1, 1, -1, 1 };
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const long double EPS = 1e-10;
#define mp make_pair
#define all(x) x.begin(),x.end()

vii mch(10);

void workout(ll u, ll r, ll& t, ll mu, ll mr, ll &mt) {
	if (t < mt)
		t += ((mt - t) / (u + r)) * (u + r);
	while (true) {
		if (t <= mt) {
			mt = max(mt, u + t);
			t += u + r;
		}
		else {
			t = max(t, mt + mu);
			mt += mu + mr;
			return;
		}
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	for (int i = 0; i < 10; i++) {
		cin >> mch[i].first >> mch[i].second;
	}

	ll ct = 0;
	vi u(10), r, t;
	r = t = u;
	for (int i = 0; i < 10; i++) {
		cin >> u[i] >> r[i] >> t[i];
	}
	for (int j = 0; j < 3; j++)
		for (int i = 0; i < 10; i++) {
			//ll u, r, t; cin >> u >> r >> t;
			workout(u[i], r[i], t[i], mch[i].first, mch[i].second, ct);
		}
	cout << ct - mch.back().second << endl;
	//cin.ignore(), cin.get();
}
