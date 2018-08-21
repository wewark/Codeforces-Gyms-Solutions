// 101673 - 2017-2018 ACM-ICPC East Central North America Regional Contest (ECNA 2017)
// 101673C

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
const long double EPS = 1e-10;
#define mp make_pair
#define all(x) x.begin(),x.end()

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	string s;
	cin >> s;

	string h1, h2;
	int sz = s.size();
	int cnt = 0, r2 = 0;
	for (int i = 0; i < sz / 2; i++) {
		h1 += s[i];
		cnt += (s[i] - 'A');
	}
	for (int i = sz / 2; i < sz; i++) {
		h2 += s[i];
		r2 += (s[i] - 'A');
	}
	for (int i = 0; i < h1.size(); i++) {
		h1[i] = char(((h1[i] - 'A') + cnt) % 26 + 'A');
	}
	for (int i = 0; i < h2.size(); i++) {
		h2[i] = char(((h2[i] - 'A') + r2) % 26 + 'A');
	}
	for (int i = 0; i < h1.size(); i++) {
		h1[i] = char(((h1[i] - 'A') + (h2[i] - 'A')) % 26 + 'A');
	}
	cout << h1;
	cin.ignore(), cin.get();
}
