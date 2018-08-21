// 101745 - 2018 Yandex.Algorithm - Elimination Stage, Online Round 1
// 101745A

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
const int di[] = { -1, 0, 1, 0, -1, 1, 1, -1 };
const int dj[] = { 0, 1, 0, -1, -1, 1, -1, 1 };
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const long double EPS = 1e-7;
#define all(n) n.begin(),n.end()

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	ll n, k; cin >> n >> k;
	ll r = n / (k + 1);
	r *= 2;
	n %= k + 1;
	if (n == 1) r++;
	else if (n) r += 2;
	cout << r << endl;
	cin.ignore(), cin.get();
}
