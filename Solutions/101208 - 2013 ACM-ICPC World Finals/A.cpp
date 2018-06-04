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
const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, 1, 0, -1 };
const int N = 1e6 + 7;
const ll MOD = 1e9 + 7;
const ll INF = 1e8;
const long double EPS = 1e-10;
#define mp make_pair
#define all(x) x.begin(),x.end()

int n;
vs mol;
const int ALPHA = 26 * 2;
bool adjmat[ALPHA][ALPHA];

void floyd() {
	for (int k = 0; k < ALPHA; ++k) {
		for (int i = 0; i < ALPHA; ++i) {
			for (int j = 0; j < ALPHA; ++j) {
				if (adjmat[i][k] && adjmat[k][j])
					adjmat[i][j] = true;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	cin >> n;
	mol.resize(n);
	for (int i = 0; i < n; ++i) {
		string s; cin >> s;
		for (int j = 0; j < s.length(); j += 2) {
			if (s[j] == '0') continue;
			int a = s[j] - 'A' + (s[j + 1] == '-' ? 26 : 0);

			for (int k = 0; k < s.length(); k += 2) {
				if (k == j || s[k] == '0') continue;
				int b = s[k] - 'A' + (s[k + 1] == '-' ? 0 : 26);
				adjmat[a][b] = true;
			}
		}
	}

	floyd();

	bool bounded = true;
	for (int i = 0; i < ALPHA; ++i) {
		if (adjmat[i][i])
			bounded = false;
	}
	cout << (bounded ? "bounded" : "unbounded") << endl;
}
