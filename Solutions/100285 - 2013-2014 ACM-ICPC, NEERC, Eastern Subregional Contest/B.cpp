// 100285 - 2013-2014 ACM-ICPC, NEERC, Eastern Subregional Contest
// 100285B

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
const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, 1, 0, -1 };
const ll MOD = 5e6;
const ll INF = 1e8;
const long double EPS = 1e-6;
#define mp make_pair
#define all(x) x.begin(),x.end()

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int n, k; cin >> n >> k;
	vi num(n);
	ll a = 0, b = 0;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
		if (num[i] > k)
			a += num[i] - k;
		else
			b += k - num[i];
	}
	cout << a << " " << b << endl;
	cin.ignore(), cin.get();
}
