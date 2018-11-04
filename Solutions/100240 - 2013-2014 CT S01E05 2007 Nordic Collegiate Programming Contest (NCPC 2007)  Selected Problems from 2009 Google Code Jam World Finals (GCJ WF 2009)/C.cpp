// 2013-2014 CT S01E05 2007 Nordic Collegiate Programming Contest (NCPC 2007)  Selected Problems from 2009 Google Code Jam World Finals (GCJ WF 2009)
// 100240C

#include <bits/stdc++.h>
#include <ext/hash_set>
#include <ext/numeric>

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

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int t , n;
	cin >> t;
	while(t--){
		cin >> n;
		vi v(n);
		for(int i = 0 ; i < n ; i++){
			cin >> v[i];
		}

		sort(all(v));
		int ans = INT_MAX;
		for(int i = 0 ; i <= 100 ; i++){
			int cur = 0;
			if(v[0] < i)cur += abs(v[0]-i)*2;
			if(v[n-1] > i)cur += abs(v[n-1])*2;
			ans = min(ans , cur);
		}

		cout << ans << endl;

	}
}