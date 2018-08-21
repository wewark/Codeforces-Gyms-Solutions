// 101243 - 2016-2017 ACM-ICPC, NEERC, Central Subregional Contest
// 101243A

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<bool> vb;
typedef vector<string> vs;
const int di[] = { -1, 0, 1, 0, -1, 1, 1, -1 };
const int dj[] = { 0, 1, 0, -1, -1, 1, -1, 1 };
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const long double EPS = 1e-10;
#define mp make_pair
#define all(x) x.begin(),x.end()

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	int n, k; cin >> n >> k;
	//int r = n / k;
	//int left = n;
	//r += n % k + left - n % k;
	if (k <= n)
		cout << (int)ceil((n * 2) / (double)k) << endl;
	else
		cout << 2 << endl;
	//cin.ignore(), cin.get();
}
