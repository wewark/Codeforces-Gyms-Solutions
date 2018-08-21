// 100187 - 2013, VI Samara Regional Intercollegiate Programming Contest
// 100187B

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
	vi cnt(150);
	for (int i = 0; i < s.length(); i++)
		cnt[s[i]]++;
	double r = 0;
	for (int i = 0; i < s.length(); i++)
		r += cnt[s[i]] / (double)s.length();
	cout << fixed << setprecision(15) << r << endl;
	cin.ignore(), cin.get();
}
