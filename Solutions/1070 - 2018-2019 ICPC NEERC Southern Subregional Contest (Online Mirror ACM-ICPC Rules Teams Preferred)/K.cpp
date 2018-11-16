// 2018-2019 ICPC NEERC Southern Subregional Contest (Online Mirror ACM-ICPC Rules Teams Preferred)
// 1070K

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
const ll MOD = 1e9 + 7;
const long double EPS = 1e-5;
#define all(x) x.begin(),x.end()
#define SZ(x) (int)(x).size()

#include <ext/hash_set>
#include <ext/numeric>

#define  fr first
#define  sc second

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int n, k;
	cin >> n >> k;
	vi v(n);
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		sum += v[i];
	}

	vi ans;

	if (sum % k == 0) {
		ll need = sum / k;
		ll cur = 0;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			cur += v[i];
			cnt++;
			if (cur == need) {
				cur = 0;
				ans.push_back(cnt);
				cnt = 0;
			}

			if (cur > need) {
				puts("No");
				return 0;
			}

		}

		if (cur == need) {
			cur = 0;
			ans.push_back(cnt);
			cnt = 0;
		}

		if (cur > need) {
			puts("No");
			return 0;
		}

		puts("Yes");
		for(int x : ans){
			printf("%d ",x);
		}

		return 0;

	}

	puts("No");

	return 0;
}