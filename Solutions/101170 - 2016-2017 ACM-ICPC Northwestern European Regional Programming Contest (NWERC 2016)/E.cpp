// 101170 - 2016-2017 ACM-ICPC Northwestern European Regional Programming Contest (NWERC 2016)
// 101170E

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
const ll MOD = 5e6;
const ll INF = 1e9;
const double EPS = 1e-6;
#define mp make_pair
#define all(x) x.begin(),x.end()

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int n; cin >> n;
	vii num(n); int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> num[i].first;
		sum += num[i].first;
		num[i].second = i;
	}
	sort(num.rbegin(), num.rend());

	if (sum - num[0].first < num[0].first)
		cout << "impossible\n";
	else
		for (int i = 0; i < n; i++) {
			cout << num[i].second + 1 << " \n"[i == n - 1];
		}

	cin.ignore(), cin.get();
}
