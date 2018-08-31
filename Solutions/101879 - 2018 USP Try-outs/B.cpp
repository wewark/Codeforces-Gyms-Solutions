// 2018 USP Try-outs
// 101879B

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
const int di[] = { 0, 0, 1, -1 };
const int dj[] = { 1, -1, 0, 0 };
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const long double EPS = 1e-6;
#define all(x) x.begin(),x.end()
#define fr first
#define sc second

int n;
vi num;

bool valid(int k) {
	if (n % k) return false;
	vi cnt(k);
	for (int i = 0; i < n; i++) {
		cnt[num[i] % k]++;
	}
	for (int i = 0; i < k; i++) {
		if (cnt[i] != n / k)
			return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	num.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	int r = -1;
	for (int i = 2; i <= n; i++) {
		if (valid(i)) {
			r = i; break;
		}
	}
	cout << r << endl;
}
