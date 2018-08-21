// 101615 - 2017-2018 ACM-ICPC Pacific Northwest Regional Contest (Div. 1)
// 101615A

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

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	string s; cin >> s;
	bool odd = true;
	for (int i = 0; i < s.length() - 1; i++) {
		//int a = i, b = i + 1;
		//while (a >= 0 && b < s.length() && s[a] == s[b]) a--, b++;
		//if (a >= 0 && b < s.length() && a == b - 1 && s[a] == s[b]) {
		//	odd = false; break;
		//}
		if (s[i] == s[i + 1]) {
			odd = false; break;
		}
	}
	cout << (odd ? "Odd." : "Or not.") << endl;
	cin.ignore(), cin.get();
}
