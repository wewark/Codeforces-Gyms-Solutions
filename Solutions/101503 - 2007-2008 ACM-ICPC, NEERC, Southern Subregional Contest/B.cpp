// 101503 - 2007-2008 ACM-ICPC, NEERC, Southern Subregional Contest
// 101503B

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

bool cmp(string& a, string& b) {
	string s1 = a + b, s2 = b + a;
	return lexicographical_compare(all(s1), all(s2));
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int n; cin >> n;
	vs s(n);
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}

	sort(all(s), cmp);
	for (int i = 0; i < n; i++) {
		cout << s[i];
	}
	cout << endl;
	//cin.ignore(), cin.get();
}
