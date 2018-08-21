// 101755 - 2018, XI Samara Regional Intercollegiate Programming Contest
// 101755E

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<ll, ll> pii;
typedef vector<pii> vii;
typedef vector<bool> vb;
typedef vector<string> vs;
const int di[] = { -1, 0, 1, 0, -1, 1, 1, -1 };
const int dj[] = { 0, 1, 0, -1, -1, 1, -1, 1 };
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const long double EPS = 1e-10;
#define all(n) n.begin(),n.end()

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	string s1, s2; cin >> s1 >> s2;
	int a = 0, b = 0, n = s1.length();
	while (a < n && s1[a] == s2[a]) a++;

	b = n - 1;
	while (b > a && s1[b] == s2[b]) b--;
	b++;
	
	string tmp = s1.substr(a, b - a);
	reverse(all(tmp));
	tmp = s1.substr(0, a) + tmp + s1.substr(b);
	if (tmp == s2)
		cout << "YES\n";
	else
		cout << "NO\n";

	cin.ignore(), cin.get();
}
