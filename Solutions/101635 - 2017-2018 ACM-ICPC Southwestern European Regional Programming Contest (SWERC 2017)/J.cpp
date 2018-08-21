// 101635 - 2017-2018 ACM-ICPC Southwestern European Regional Programming Contest (SWERC 2017)
// 101635J

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
#define all(x) x.begin(),x.end()

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int n; cin >> n;
	vll a(n), b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}

	vll part(3);
	for (int i = 0; i < n; i++) {
		part[i % 3] += a[i];
	}

	deque<ll> r(3);
	for (int i = 0; i < n; i++) {
		r[0] += part[0] * b[i];
		r[1] += part[1] * b[i];
		r[2] += part[2] * b[i];
		r.push_back(r[0]);
		r.pop_front();
	}
	for (int i = 0; i < n % 3; i++) {
		r.push_front(r.back());
		r.pop_back();
	}
	cout << r[1] << " " << r[2] << " " << r[0] << endl;
	cin.ignore(), cin.get();
}
