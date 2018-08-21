// 101170 - 2016-2017 ACM-ICPC Northwestern European Regional Programming Contest (NWERC 2016)
// 101170H

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
const ll INF = 1e9;
const double EPS = 1e-6;
#define mp make_pair
#define all(x) x.begin(),x.end()

ll dist(string s) {
	ll ret = 0;
	bool flip = false;
	for (int i = 0; i < s.length(); i++) {
		if (flip) {
			if (s[i] == '0')
				ret += (1ll << (s.length() - i - 1));
			else
				flip = false;
		}
		else if (s[i] == '1')
			ret += (1ll << (s.length() - i - 1)), flip = true;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int n; cin >> n;
	string s1, s2; cin >> s1 >> s2;
	cout << abs(dist(s1) - dist(s2)) - 1 << endl;
	cin.ignore(), cin.get();
}
