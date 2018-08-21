// 101727 - 2018 Yandex.Algorithm - Warmup Round
// 101727B

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
#define all(x) x.begin(),x.end()

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	string s; cin >> s;
	string r = "";
	for (int i = 0; i < s.length() - 1; i++) {
		if (s[i] == s[i + 1]) {
			if (r == "") r = string(1, s[i]) + s[i + 1];
			else r = min(r, string(1, s[i]) + s[i + 1]);
		}
	}

	if (r == "") {
		for (int i = 0; i < s.length() - 2; i++) {
			if (s[i] == s[i + 2]) {
				if (r == "") r = string(1, s[i]) + s[i + 1] + s[i + 2];
				else r = min(r, string(1, s[i]) + s[i + 1] + s[i + 2]);
			}
		}
	}

	cout << (r == "" ? "-1" : r) << endl;
	cin.ignore(), cin.get();
}
