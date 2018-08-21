// 101061 - Higher Institute for Applied Sciences and Technology Collegiate Programming Contest 2016
// 101061I

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
const ll INF = 1e10;
const double EPS = 1e-10;
#define mp make_pair
#define all(x) x.begin(),x.end()

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int t; cin >> t;
	while (t--) {
		string s1, s2; cin >> s1 >> s2;
		vi cnt1(150), cnt2(150);
		for (int i = 0; i < s1.length(); i++)
			cnt1[s1[i]]++;
		for (int i = 0; i < s2.length(); i++)
			cnt2[s2[i]]++;

		int r = 0;
		for (int i = 0; i < 150; i++)
			r += abs(cnt1[i] - cnt2[i]);
		cout << r << endl;
	}
	cin.ignore(), cin.get();
}
