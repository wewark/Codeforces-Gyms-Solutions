// 2013-2014 CT S01E09 2011 German Collegiate Programming Contest (GCPC 2011)  GCJ 2009 R3 C-D
// 100274B

#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<bool> vb;
typedef vector<string> vs;
const int di[] = {0, 0, 1, -1};
const int dj[] = {1, -1, 0, 0};
const ll MOD = 1e9 + 7;
const long double EPS = 1e-5;
#define all(x) x.begin(),x.end()

#include <ext/hash_set>
#include <ext/numeric>

const int N = 1005;
char a[N], b[N];

int main() {
//	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	int t, n;
	scanf("%d", &t);
	while (t--) {
		bool pos = false;
		scanf("%d%s%s", &n, a, b);
		int len = (n + 1) / 2;
		for (int sa = 0; sa + len - 1 < n && !pos; sa++) {
			for (int sb = 0; sb + len - 1 < n && !pos; sb++) {
				bool can = true;
				for (int j = 0; j < len; j++) {
					if (abs(a[sa + j] - b[sb + j]) > 1) {
						can = false;
						break;
					}
				}
				if (can)pos = true;
			}
		}

		puts(pos?"POSITIVE":"NEGATIVE");
	}
	return 0;
}