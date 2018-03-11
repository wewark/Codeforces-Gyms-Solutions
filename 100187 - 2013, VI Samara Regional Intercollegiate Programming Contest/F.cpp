#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<short, int> pii;
typedef vector<pii> vii;
typedef vector<bool> vb;
typedef vector<string> vs;
const int di[] = { -1,0,1,0 };
const int dj[] = { 0,1,0,-1 };
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
#define mp make_pair
#define all(x) x.begin(),x.end()

ll n, m, k, t;
vll v, p, vc;

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m >> k >> t;
	p.resize(n), v.resize(m), vc.assign(m, 0);
	for (int i = 0; i < n; i++)
		cin >> p[i];
	for (int i = 0; i < m; i++)
		cin >> v[i];
	sort(all(p)), sort(all(v));

	int r = 0, a = 0, b = m - 1;
	for (int i = 0; i < m; i++) {
		while (a < n && v[i] - p[a] > t) a++;
		while (a < n && vc[i] < k && abs(p[a] - v[i]) <= t) {
			r++;
			vc[i]++;
			a++;
		}
	}
	cout << r << endl;
	cin.ignore(), cin.get();
}
