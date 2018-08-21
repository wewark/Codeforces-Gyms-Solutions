// 101755 - 2018, XI Samara Regional Intercollegiate Programming Contest
// 101755J

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
const int di[] = { -1, 0, 1, 0, -1, 1, 1, -1 };
const int dj[] = { 0, 1, 0, -1, -1, 1, -1, 1 };
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const long double EPS = 1e-10;
#define all(n) n.begin(),n.end()

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int n; cin >> n;
	vi num(n), cnt(2e5 + 5);
	for (int i = 0; i < n; i++) {
		cin >> num[i];
		cnt[num[i]]++;
	}
	int r = 0;
	for (int i = 0; i < cnt.size(); i++) {
		r += cnt[i] / 2;
	}
	cout << r / 2 << endl;
	cin.ignore(), cin.get();
}
