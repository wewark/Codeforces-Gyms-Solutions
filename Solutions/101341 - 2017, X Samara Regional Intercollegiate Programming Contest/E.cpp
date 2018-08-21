// 101341 - 2017, X Samara Regional Intercollegiate Programming Contest
// 101341E

﻿#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<bool> vb;
typedef vector<string> vs;
const int di[] = { 0, 0, 1, -1 };
const int dj[] = { 1, -1, 0, 0 };
const ll MOD = 1e9 + 7;
const ll INF = INT_MAX;
const long double EPS = 1e-6;
#define all(x) x.begin(),x.end()

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int n, m; cin >> n >> m;
	vi t(n), b(m);
	for (int i = 0; i < n; i++) {
		cin >> t[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}

	ll r = 0;
	for (int i = 0, j = 0; i < n && j < m; i++) {
		if (b[j] <= t[i]) {
			r += (t[i] - b[j]) * 2;
			while (j < m && b[j] <= t[i])
				j++;
		}

		if (i == n - 1) {
			if (j < m)
				r += (b.back() - t[i]) * 2;
		}
		else if (j < m && b[j] < t[i + 1]) {
			ll mn = (t[i + 1] - b[j]) * 2;
			while (j < m && b[j] <= t[i + 1]) {
				ll cur = (b[j] - t[i]) * 2;
				if (j < m - 1 && b[j + 1] <= t[i + 1])
					cur += (t[i + 1] - b[j + 1]) * 2;
				mn = min(mn, cur);
				j++;
			}
			mn = min(mn, t[i + 1] - t[i]);
			r += mn;
		}
	}

	cout << r << endl;
	cin.ignore(), cin.get();
}
