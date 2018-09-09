// Arab Collegiate Programming Contest 2012
// 100155G

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
#define x first
#define y second

const long double PI = acos(-1);

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int n; cin >> n;
	vii a(n), b(n);
	map<ll, pii> m;
	ll mul = 1e15;
	for (int i = 0; i < n; i++) {
		cin >> a[i].x >> a[i].y >> b[i].x >> b[i].y;
		ll s = atan2(a[i].y, a[i].x) * mul;
		ll e = atan2(b[i].y, b[i].x) * mul;
		if (a[i].x * b[i].y - b[i].x * a[i].y < 0)
			swap(s, e);
		if (s == e) {
			m[s].first++;
			m[s + 1].second++;
		}
		else if (s > e) {
			m[s].first++;
			m[PI * mul].second++;
			m[-PI * mul].first++;
			m[e + 1].second++;
		}
		else {
			m[s].first++;
			m[e + 1].second++;
		}
	}

	vll cnt(105);
	ll c = 0, prv = 0;
	for (auto& i : m) {
		cnt[c] += i.first - prv + 1;
		prv = i.first;
		c += i.second.first;
		c -= i.second.second;
	}

	double r = 0;
	for (int i = 1; i < cnt.size(); i++) {
		r += (long double)i * cnt[i] / (long double)(PI * 2LL * mul);
	}
	cout << fixed << setprecision(10) << r << endl;
}
