// 101652 - 2017-2018 ACM-ICPC Pacific Northwest Regional Contest (Div. 2)
// 101652P

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
const double EPS = 1e-7;
#define mp make_pair
#define all(x) x.begin(),x.end()

long long sumRange(long long l, long long r) {
	return l * (r - l + 1) + (r - l) * (r - l + 1) / 2;
}

const ll MAX = 1000000;
int main() {
	ios::sync_with_stdio(false), cin.tie(0);

	long long a, b;
	cin >> a >> b;

	long long sum = 0;
	for (ll i = 1; i <= MAX; i++) {
		long long L = a / i;
		long long R = b / i;

		if (L * i < a) L = max(L + 1LL, i + 0LL);
		else
			L = max(L, 0LL + i);

		if (R < L or R > b or L < i) continue;
		//cout << i << " " << L << " " << R << endl;

		sum += sumRange(L, R) + (R - L + 1) * i;
		if (i >= L && i <= R)
			sum -= i;
	}

	cout << sum << endl;
	cin.ignore(), cin.get();
}