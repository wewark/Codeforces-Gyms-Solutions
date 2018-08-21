// 101612 - 2017-2018 ACM-ICPC, NEERC, Northern Subregional Contest
// 101612A

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
const int di[] = { -1, 0, 1, 0 }, N=1e6+7;
const int dj[] = { 0, 1, 0, -1 };
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const double EPS = 1e-5;
#define mp make_pair
#define all(x) x.begin(),x.end()

pair<int, int> x[N];

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	ifstream cin("auxiliary.in");
	ofstream cout("auxiliary.out");
	int n; cin >> n;
	ll sum = 7 * (n / 3);

	if (n % 3 == 1)
		sum -= 3;
	else if (n % 3 == 2)
		sum++;

	cout << sum << endl;
	cin.ignore(), cin.get();
}
