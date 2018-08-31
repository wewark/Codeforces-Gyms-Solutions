// 2018 USP Try-outs
// 101879D

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

struct Voter {
	int x, y;
	char vote;
};

int n;
vector<Voter> v;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].x >> v[i].y >> v[i].vote;
	}

	sort(all(v), [](Voter a, Voter b) {
		return a.x < b.x;
	});

	int r = 0;
	int cb = 0, cw = 0;
	for (int i = 0; i < n; i++)
		if (v[i].vote == 'w')
			cw++;
	r = max(r, cw);
	for (int i = 0; i < n; i++) {
		if (v[i].vote == 'w')
			cw--;
		else
			cb++;
		
		if (i + 1 < n && v[i + 1].x == v[i].x)
			continue;
		r = max(r, cw + cb);
	}

	cb = 0, cw = 0;
	for (int i = 0; i < n; i++)
		if (v[i].vote == 'b')
			cb++;
	r = max(r, cb);
	for (int i = 0; i < n; i++) {
		if (v[i].vote == 'b')
			cb--;
		else
			cw++;

		if (i + 1 < n && v[i + 1].x == v[i].x)
			continue;
		r = max(r, cw + cb);
	}

	sort(all(v), [](Voter a, Voter b) {
		return a.y < b.y;
	});

	cb = 0, cw = 0;
	for (int i = 0; i < n; i++)
		if (v[i].vote == 'w')
			cw++;
	r = max(r, cw);
	for (int i = 0; i < n; i++) {
		if (v[i].vote == 'w')
			cw--;
		else
			cb++;

		if (i + 1 < n && v[i + 1].y == v[i].y)
			continue;
		r = max(r, cw + cb);
	}

	cb = 0, cw = 0;
	for (int i = 0; i < n; i++)
		if (v[i].vote == 'b')
			cb++;
	r = max(r, cb);
	for (int i = 0; i < n; i++) {
		if (v[i].vote == 'b')
			cb--;
		else
			cw++;

		if (i + 1 < n && v[i + 1].y == v[i].y)
			continue;
		r = max(r, cw + cb);
	}

	cout << r << endl;
}
