// 100609 - 2011-2012 ACM-ICPC, NEERC, Northern Subregional Contest
// 100609A

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
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};
const int N = 1e6 + 7;
const ll MOD = 1e9 + 7;
const ll INF = 1e8;
const long double EPS = 1e-10;
#define mp make_pair
#define all(x) x.begin(),x.end()
int arr[505];

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	freopen("ate.in", "r", stdin);
	freopen("ate.out", "w", stdout);
	int n; cin >> n;
	int r = 0;
	for (int i = 0; i < 100; ++i) {
		if (n - i < 100)
			r++;
	}
	cout << r << endl;
}