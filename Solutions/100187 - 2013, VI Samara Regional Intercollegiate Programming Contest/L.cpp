// 100187 - 2013, VI Samara Regional Intercollegiate Programming Contest
// 100187L

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<short, int> pii;
typedef vector<pii> vii;
typedef vector<bool> vb;
typedef vector<string> vs;
const int di[] = { -1,0,1,0 };
const int dj[] = { 0,1,0,-1 };
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
#define mp make_pair
#define all(x) x.begin(),x.end()

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	string s; cin >> s;
	int a = 0, b = s.length() - 1;
	while (a < b) {
		s[b--] = s[a++];
	}
	cout << s << endl;
	cin.ignore(), cin.get();
}
