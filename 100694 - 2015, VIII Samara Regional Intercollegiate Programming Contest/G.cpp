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
const ll MOD = 998244353;
const ll INF = 1e9;
const double EPS = 1e-5;
#define mp make_pair
#define all(x) x.begin(),x.end()

int n;
vi prnt;

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n;
	prnt.assign(n, -1);
	int cur = -1;
	for (int i = 0; i < 2 * n; i++) {
		string s; int x; cin >> s >> x; x--;
		if (s == "in") {
			prnt[x] = cur;
			cur = x;
		}
		else {
			cur = prnt[cur];
		}
	}

	for (int i = 0; i < n; i++)
		if (prnt[i] != -1)
			cout << i + 1 << " " << prnt[i] + 1 << endl;
	cin.ignore(), cin.get();
}
