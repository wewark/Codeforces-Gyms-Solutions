// 2017 ACM Jordanian Collegiate Programming Contest
// 101608E

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
const int di[] = { 0,0,1,-1 };
const int dj[] = { 1,-1,0,0 };
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const long double EPS = 1e-6;
#define all(x) x.begin(),x.end()
#define x first
#define y second


int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	ifstream cin("reduce.in");

	int dn[128];
	dn['R'] = 0;
	dn['L'] = 1;
	dn['D'] = 2;
	dn['U'] = 3;
	char dnxt[128];
	dnxt['U'] = 'R';
	dnxt['R'] = 'D';
	dnxt['D'] = 'L';
	dnxt['L'] = 'U';

	int t; cin >> t;
	while (t--) {
		int n, m, qn; cin >> n >> m >> qn;
		pii cur; cin >> cur.x >> cur.y;
		cur.x--, cur.y--;
		char cd; cin >> cd;

		vs g(n);
		for (int i = 0; i < n; i++)
			cin >> g[i];

		vector<pair<char, int>> q(qn);
		for (int i = 0; i < qn; i++) {
			cin >> q[i].first;
			if (q[i].first == 'F')
				cin >> q[i].second;
		}

		while (!q.empty() && q.back().first == 'R')
			q.pop_back();

		for (int i = 0; i < (int)q.size() - 3; i++) {
			bool same = true;
			for (int j = i; j < i + 4; j++)
				if (q[j].first != 'R') {
					same = false; break;
				}
			if (same) {
				q.erase(q.begin() + i, q.begin() + i + 4);
				i--;
			}
		}

		for (int i = 0; i < q.size(); i++) {
			if (q[i].first == 'R') {
				pii tcur1 = cur, tcur2 = cur;
				char tcd1 = cd, tcd2 = cd;
				while (g[tcur1.x + di[dn[tcd1]]][tcur1.y + dj[dn[tcd1]]] == '#')
					tcd1 = dnxt[tcd1];

				int cb = i;
				while (cb < q.size() && q[cb].first == 'R') {
					tcd2 = dnxt[tcd2];
					cb++;
				}
				cb -= i;
				while (g[tcur2.x + di[dn[tcd2]]][tcur2.y + dj[dn[tcd2]]] == '#')
					tcd2 = dnxt[tcd2];
				
				if (tcur1.x + di[dn[tcd1]] == tcur2.x + di[dn[tcd2]] &&
					tcur1.y + dj[dn[tcd1]] == tcur2.y + dj[dn[tcd2]]) {
					q.erase(q.begin() + i, q.begin() + i + cb);
					i--;
				}
				else
					cd = dnxt[cd];
			}
			else {
				for (int j = 0; j < q[i].second; j++) {
					while (g[cur.x + di[dn[cd]]][cur.y + dj[dn[cd]]] == '#')
						cd = dnxt[cd];
					cur.x += di[dn[cd]];
					cur.y += dj[dn[cd]];
				}
			}
		}

		for (int i = 0; i < (int)q.size() - 1; i++) {
			if (q[i].first == 'F' &&
				q[i + 1].first == 'F') {
				q[i].second += q[i + 1].second;
				q.erase(q.begin() + i + 1);
				i--;
			}
		}

		cout << q.size() << endl;
	}
}
