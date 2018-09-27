// 2010-2011 ACM-ICPC NEERC Moscow Subregional Contest
// 100714J

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
const int di[] = { 0,0,1,-1 };
const int dj[] = { 1,-1,0,0 };
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const long double EPS = 1e-6;
#define all(x) x.begin(),x.end()

int main() {
	ios::sync_with_stdio(0), cin.tie(0);

	string x, y; cin >> x >> y;
	int px = 0, py = 0;
	if (x.find('.') != string::npos) {
		px = x.length() - x.find('.') - 1;
		x.erase(x.find('.'), 1);
	}
	if (y.find('.') != string::npos) {
		py = y.length() - y.find('.') - 1;
		y.erase(y.find('.'), 1);
	}

	if (px > py)
		y += string(px - py, '0');
	else
		x += string(py - px, '0');

	cout << stoll(x) / stoll(y) << endl;
}
