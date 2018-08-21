// 101754 - Yandex.Algorithm 2018, second qualification round
// 101754C

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
const int di[] = { -1, 0, 1, 0, -1, 1, 1, -1 };
const int dj[] = { 0, 1, 0, -1, -1, 1, -1, 1 };
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const long double EPS = 1e-7;
#define all(n) n.begin(),n.end()

int n, m, ds, cs, da, ca;
vi h;

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m >> ds >> cs >> da >> ca;
	h.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}
	sort(all(h));

	int r = 0;
	for (int i = 0; i * ca <= m; i++) {
		int kld = 0, mana = m - i * ca;
		for (int j = 0; j < n; j++) {
			if (h[j] - i * da <= 0) kld++;
			else if (ceil((h[j] - i * da) / (double)ds) * cs <= mana)
				kld++, mana -= ceil((h[j] - i * da) / (double)ds) * cs;
		}
		r = max(r, kld);
	}
	cout << r << endl;
	cin.ignore(), cin.get();
}
