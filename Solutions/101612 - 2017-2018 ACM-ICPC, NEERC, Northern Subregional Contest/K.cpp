// 101612 - 2017-2018 ACM-ICPC, NEERC, Northern Subregional Contest
// 101612K

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
const int di[] = { -1, 0, 1, 0 }; //  , N = 1e6 + 7;
const int dj[] = { 0, 1, 0, -1 };
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const double EPS = 1e-5;
#define mp make_pair
#define all(x) x.begin(),x.end()

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	ifstream cin("kotlin.in");
	ofstream cout("kotlin.out");
	int h, w, n; cin >> h >> w >> n;
	//ll cur = ceil(h / 2.0) * ceil(w / 2.0);
	//if (n > cur) {
	//	cout << "Impossible\n"; return 0;
	//}

	int rw = 0, cl = 0;
	int hl = ceil(h / 2.0), wl = ceil(w / 2.0);
	for (int i = 1; i <= hl && !rw; i++) {
		for (int j = 1; j <= wl && !cl; j++) {
			if (i * j == n)
				rw = i, cl = j;
		}
	}

	if (!rw && !cl) {
		cout << "Impossible\n"; return 0;
	}

	vector<vector<char>> g(h, vector<char>(w, '.'));
	cl--, rw--;
	for (int i = 1; i < h && rw; i += 2, rw--) {
		for (int j = 0; j < w; j++) {
			g[i][j] = '#';
		}
	}
	for (int j = 1; j < w && cl; j += 2, cl--) {
		for (int i = 0; i < h; i++) {
			g[i][j] = '#';
		}
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cout << g[i][j];
		}
		cout << endl;
	}
	cin.ignore(), cin.get();
}
