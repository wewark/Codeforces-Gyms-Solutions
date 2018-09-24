// 2016-2017 CT S03E01 Codeforces Trainings Season 3 Episode 1 - 2010 Benelux Algorithm Programming Contest (BAPC 10)
// 101078A

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
const int di[] = { 0,0,1,-1 };
const int dj[] = { 1,-1,0,0 };
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const long double EPS = 1e-9;
#define all(x) x.begin(),x.end()

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vi A(n), B(n);
		for (int i = 0; i < n; i++) {
			cin >> A[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> B[i];
		}

		vi cnt(1e5 + 5);
		int a = 0, b = 0, net = 0;
		vii r;
		while (a < n) {
			while (b < n) {
				if (cnt[A[b]] == 0) net++;
				cnt[A[b]]++;
				if (cnt[A[b]] == 0) net--;

				if (cnt[B[b]] == 0) net++;
				cnt[B[b]]--;
				if (cnt[B[b]] == 0) net--;
				b++;
				if (net == 0) break;
			}

			if (net == 0)
				r.emplace_back(a, b - 1);
			a = b;
		}

		for (int i = 0; i < r.size(); i++) {
			cout << r[i].first + 1 << "-" << r[i].second + 1 << " \n"[i == r.size() - 1];
		}
	}
}
