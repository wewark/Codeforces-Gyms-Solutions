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
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const double EPS = 1e-5;
#define mp make_pair
#define all(x) x.begin(),x.end()

int n;
vector<vll> g;

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	string s; cin >> s;
	int o = 0, z = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '0') z++;
		else o++;
	}

	cout << min(o, z) << endl;

	cin.ignore(), cin.get();
}
