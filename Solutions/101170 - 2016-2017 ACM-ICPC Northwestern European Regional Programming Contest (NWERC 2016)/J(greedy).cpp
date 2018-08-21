// 101170 - 2016-2017 ACM-ICPC Northwestern European Regional Programming Contest (NWERC 2016)
// 101170J

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
const double EPS = 1e-12;
#define mp make_pair
#define all(x) x.begin(),x.end()

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	ll n, q, s; cin >> n >> q >> s;
	vi sen(s);
	for (int i = 0; i < s; i++) {
		cin >> sen[i]; sen[i]--;
	}
	vi sz(q);
	for (int i = 0; i < q; i++) {
		cin >> sz[i];
	}

	vi d(n);
	vvi qinc(n, vi(q));
	for (int i = 0; i < n; i++) {
		cin >> d[i];
		for (int j = 0; j < s; j++) {
			ll x; cin >> x;
			qinc[i][sen[j]] += x;
		}
	}

	ll cur = 0; bool w = false;
	vi qcur(q);
	vector<queue<pii>> qp(q);
	for (int i = 0; i < n && !w; i++) {
		for (int j = 0; j < q && !w; j++) {
			while (qcur[j] + qinc[i][j] > sz[j]) {
				if (qp[j].empty()) {
					w = true; break;
				}
				ll rm = qcur[j] + qinc[i][j] - sz[j];//min(qcur[j] + qinc[i][j] - sz[j], d[qp[j].front().second]);
				//if (rm == 0) {
				//	ll x = qp[j].front().first;
				//	qp[j].pop();
				//	if (!qp[j].empty())
				//		qp[j].front().first += x;
				//}
				if (rm >= qp[j].front().first) {
					if (qp[j].front().first <= d[qp[j].front().second]) {
						rm -= qp[j].front().first;
						qcur[j] -= qp[j].front().first;
						d[qp[j].front().second] -= qp[j].front().first;
						qp[j].pop();
					}
					else {
						rm -= d[qp[j].front().second];
						qcur[j] -= d[qp[j].front().second];
						ll x = qp[j].front().first - d[qp[j].front().second];
						d[qp[j].front().second] -= d[qp[j].front().second];
						qp[j].pop();
						if (!qp[j].empty())
							qp[j].front().first += x;
					}
				}
				else {
					if (rm <= d[qp[j].front().second]) {
						qp[j].front().first -= rm;
						qcur[j] -= rm;
						d[qp[j].front().second] -= rm;
					}
					else {
						rm -= d[qp[j].front().second];
						qcur[j] -= d[qp[j].front().second];
						ll x = qp[j].front().first - d[qp[j].front().second];
						d[qp[j].front().second] -= d[qp[j].front().second];
						qp[j].pop();
						if (!qp[j].empty())
							qp[j].front().first += x;
					}
				}
			}
			qcur[j] += qinc[i][j];
			qp[j].push({ qinc[i][j],i });
		}
	}

	for (int j = 0; j < q && !w; j++) {
		while (qcur[j] > 0) {
			if (qp[j].empty()) {
				w = true; break;
			}
			ll rm = qcur[j];//min(qcur[j], d[qp[j].front().second]);
			//if (rm == 0) {
			//	ll x = qp[j].front().first;
			//	qp[j].pop();
			//	if (!qp[j].empty())
			//		qp[j].front().first += x;
			//}
			if (rm >= qp[j].front().first) {
				if (qp[j].front().first <= d[qp[j].front().second]) {
					rm -= qp[j].front().first;
					qcur[j] -= qp[j].front().first;
					d[qp[j].front().second] -= qp[j].front().first;
					qp[j].pop();
				}
				else {
					rm -= d[qp[j].front().second];
					qcur[j] -= d[qp[j].front().second];
					ll x = qp[j].front().first - d[qp[j].front().second];
					d[qp[j].front().second] -= d[qp[j].front().second];
					qp[j].pop();
					if (!qp[j].empty())
						qp[j].front().first += x;
				}
			}
			else {
				if (rm <= d[qp[j].front().second]) {
					qp[j].front().first -= rm;
					qcur[j] -= rm;
					d[qp[j].front().second] -= rm;
				}
				else {
					rm -= d[qp[j].front().second];
					qcur[j] -= d[qp[j].front().second];
					ll x = qp[j].front().first - d[qp[j].front().second];
					d[qp[j].front().second] -= d[qp[j].front().second];
					qp[j].pop();
					if (!qp[j].empty())
						qp[j].front().first += x;
				}
			}
		}
	}

	cout << (w ? "impossible" : "possible") << endl;
	cin.ignore(), cin.get();
}
