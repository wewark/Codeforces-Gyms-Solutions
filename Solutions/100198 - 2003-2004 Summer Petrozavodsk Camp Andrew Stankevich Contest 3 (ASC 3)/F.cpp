// 2003-2004 Summer Petrozavodsk Camp Andrew Stankevich Contest 3 (ASC 3)
// 100198F

#include <bits/stdc++.h>
#include <ext/hash_set>
#include <ext/numeric>

using namespace __gnu_cxx;

using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<bool> vb;
typedef vector<string> vs;
const ll MOD = 1e9 + 7;
const long double EPS = 1e-5;
const ll INF = LLONG_MAX;
int di[] = { 0, 0, 1, -1 };
int dj[] = { 1, -1, 0, 0 };
#define all(x) x.begin(),x.end()

int na, nb;
string ch, a, b;
ll d[260][260];
map<int, ll> besta, bestb;
map<int, int> bestac, bestbc;

ll mem[2019][2019];
ll solve(int ia, int ib) {
	if (ia == na && ib == nb) return 0;

	ll& ret = mem[ia][ib];
	if (~ret) return ret;

	ret = INF;
	if (ia < na && ib < nb)
		ret = solve(ia + 1, ib + 1) + d[a[ia]][b[ib]];
	if (ia < na)
		ret = min(ret, solve(ia + 1, ib) + d[a[ia]][bestac[a[ia]]]);
	if (ib < nb)
		ret = min(ret, solve(ia, ib + 1) + d[bestbc[b[ib]]][b[ib]]);

	return ret;
}

string pa, pb;
void build(int ia, int ib) {
	if (ia == na && ib == nb) return;

	ll ret = INF;
	int choice = -1;
	int ca, cb;
	if (ia < na && ib < nb) {
		ret = solve(ia + 1, ib + 1) + d[a[ia]][b[ib]];
		ca = a[ia], cb = b[ib];
		choice = 0;
	}
	if (ia < na) {
		ll x = solve(ia + 1, ib) + d[a[ia]][bestac[a[ia]]];
		if (x < ret) {
			ret = x;
			ca = a[ia], cb = bestac[a[ia]];
			choice = 1;
		}
	}
	if (ib < nb) {
		ll x = solve(ia, ib + 1) + d[bestbc[b[ib]]][b[ib]];
		if (x < ret) {
			ret = x;
			ca = bestbc[b[ib]], cb = b[ib];
			choice = 2;
		}
	}

	pa.push_back(ca);
	pb.push_back(cb);
	if (choice == 0) build(ia + 1, ib + 1);
	else if (choice == 1) build(ia + 1, ib);
	else build(ia, ib + 1);
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#else
	freopen("dissim.in", "r", stdin);
	freopen("dissim.out", "w", stdout);
#endif

	memset(mem, -1, sizeof(mem));

	cin >> ch >> a >> b;
	na = a.length();
	nb = b.length();
	int m = ch.length();
	for (int i = 0; i < ch.length(); ++i) {
		for (int j = 0; j < ch.length(); ++j) {
			cin >> d[ch[i]][ch[j]];
			if (besta.find(ch[i]) == besta.end() ||
				d[ch[i]][ch[j]] < besta[ch[i]]) {
				besta[ch[i]] = d[ch[i]][ch[j]];
				bestac[ch[i]] = ch[j];
			}
			if (bestb.find(ch[j]) == bestb.end() ||
			    d[ch[i]][ch[j]] < bestb[ch[j]]) {
				bestb[ch[j]] = d[ch[i]][ch[j]];
				bestbc[ch[j]] = ch[i];
			}
		}
	}

	cout << solve(0, 0) << endl;
	build(0, 0);
	cout << pa << endl;
	cout << pb << endl;
}
