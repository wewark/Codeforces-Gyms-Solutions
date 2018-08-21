// 101492 - 2017 USP Try-outs
// 101492K

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<ll, ll> pii;
typedef vector<pii> vii;
typedef vector<bool> vb;
typedef vector<string> vs;
const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, 1, 0, -1 };
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const double EPS = 1e-5;
#define mp make_pair
#define all(pt) pt.begin(),pt.end()

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int k; cin >> k;
	ll r = 1, cur = 2;
	for (int i = 0; i < k; i++) {
		r += cur;
		cur *= 2;
	}
	cout << r << endl;
	//cin.ignore(), cin.get();
}
