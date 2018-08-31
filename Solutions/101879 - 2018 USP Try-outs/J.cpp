// 2018 USP Try-outs
// 101879J

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
const int di[] = { 0, 0, 1, -1 };
const int dj[] = { 1, -1, 0, 0 };
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const long double EPS = 1e-6;
#define all(x) x.begin(),x.end()
#define fr first
#define sc second

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int n; cin >> n;
	string s = "a";
	while (s.length() < n)
		s = s + string(1, s[s.length() / 2] + 1) + s;
	cout << s[n - 1] << endl;
}
