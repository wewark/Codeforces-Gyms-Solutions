// 101341 - 2017, X Samara Regional Intercollegiate Programming Contest
// 101341H

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
const ll INF = 1e9;
const long double EPS = 1e-6;
#define all(x) x.begin(),x.end()

int n, m;

int solveH(vvi& g) {
	int mx = -1, mxi = -1;
	for (int i = 0; i < n; i++) {
		int x = *max_element(all(g[i]));
		if (x > mx)
			mx = x, mxi = i;
	}
	return mxi;
}

int solveV(vvi& g) {
	int mx = -1, mxj = -1;
	for (int i = 0; i < n; i++) {
		auto x = max_element(all(g[i]));
		if (*x > mx)
			mx = *x, mxj = x - g[i].begin();
	}
	return mxj;
}

pair<int, pii> solveHV(vvi g) {
	int rmi = solveH(g);
	g[rmi].assign(m, 0);
	int rmj = solveV(g);
	for (int i = 0; i < n; i++) {
		g[i][rmj] = 0;
	}

	int mx = -1;
	for (int i = 0; i < n; i++) {
		int x = *max_element(all(g[i]));
		if (x > mx)
			mx = x;
	}

	return { mx,{ rmi, rmj } };
}
pair<int, pii> solveVH(vvi g) {
	int rmj = solveV(g);
	for (int i = 0; i < n; i++) {
		g[i][rmj] = 0;
	}
	int rmi = solveH(g);
	g[rmi].assign(m, 0);

	int mx = -1;
	for (int i = 0; i < n; i++) {
		int x = *max_element(all(g[i]));
		if (x > mx)
			mx = x;
	}

	return { mx,{ rmi, rmj } };
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m;
	vvi g(n, vi(m));

	int mxi = 0, mxj = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> g[i][j];
		}
	}

	pair<int, pii> r = min(solveHV(g), solveVH(g));

	cout << r.second.first + 1 << " " << r.second.second + 1 << endl;
	cin.ignore(), cin.get();
}
