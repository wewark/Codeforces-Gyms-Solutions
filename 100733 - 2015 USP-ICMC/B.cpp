#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<pair<int, int>, int> pii;
typedef vector<pii> vii;
typedef vector<bool> vb;
typedef vector<string> vs;
const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, 1, 0, -1 };
const ll MOD = 1e9 + 7;
const ll INF = 1e10;
const double EPS = 1e-5;
#define mp make_pair
#define all(x) x.begin(),x.end()

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int k; cin >> k;
	vs usr(k), gng(k);
	vvi art(k, vi(150));
	for (int i = 0; i < k; i++)
		cin >> usr[i] >> gng[i];

	int mx = -1, mxi = -1;
	for (int i = 0; i < k; i++) {
		int n, m; cin >> n >> m;
		for (int j = 0; j < n; j++) {
			string s; cin >> s;
			for (int k = 0; k < s.length(); k++)
				art[i][s[k]]++;
		}

		vi ccnt(150);
		for (int j = 0; j < usr[i].length(); j++)
			ccnt[usr[i][j]]++;
		for (int j = 0; j < gng[i].length(); j++)
			ccnt[gng[i][j]]++;

		int mn = INT_MAX;
		for (int j = 0; j < 150; j++)
			if (ccnt[j])
				mn = min(mn, art[i][j] / ccnt[j]);

		if (mn > mx)
			mx = mn, mxi = i;
	}
	cout << usr[mxi] << " " << gng[mxi] << endl;
	cin.ignore(), cin.get();
}
