// 101341 - 2017, X Samara Regional Intercollegiate Programming Contest
// 101341C

﻿#include <bits/stdc++.h>
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
const ll INF = 1e15;
const long double EPS = 1e-6;
#define all(x) x.begin(),x.end()

ll a, b, c, n, m;

bool valid(ll x) {
	return min(x, a + c) <= n && min(x, b + c) <= m;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> a >> b >> c >> n >> m;
	ll l = 0, r = a + b + c, mid = (l + r) / 2;

	while (l < r) {
		if (valid(mid))
			l = mid;
		else
			r = mid - 1;
		mid = (l + r + 1) / 2;
	}
	cout << mid << endl;

	cin.ignore(), cin.get();
}
