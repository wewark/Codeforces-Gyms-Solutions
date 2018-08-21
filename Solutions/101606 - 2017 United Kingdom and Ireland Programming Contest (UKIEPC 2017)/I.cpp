// 101606 - 2017 United Kingdom and Ireland Programming Contest (UKIEPC 2017)
// 101606I

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
	int n; cin >> n;
	vi num(n);
	int mn = 1e9, mni = -1;
	for (int i = 0; i < n; i++)
		cin >> num[i];
	int x; cin >> x;
	for (int i = 0; i < n; i++)
		if (x % num[i] < mn)
			mn = x % num[i], mni = i;
	cout << num[mni] << endl;
	cin.ignore(), cin.get();
}
