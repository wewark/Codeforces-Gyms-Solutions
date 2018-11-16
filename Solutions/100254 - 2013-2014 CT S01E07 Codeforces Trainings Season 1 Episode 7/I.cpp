// 2013-2014 CT S01E07 Codeforces Trainings Season 1 Episode 7
// 100254I

#pragma GCC optimize ("O3")
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
const ll MOD = 1e9 + 7;
const long double EPS = 1e-5;
#define all(x) x.begin(),x.end()

#include <ext/hash_set>
#include <ext/numeric>

#define  fr first
#define  sc second
typedef pair<int, pair<int, int>> piii;

const int N = 405;

int n;
int a[N][N];
int ans[N][N][N];

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	cin >> n;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			cin >> a[i][j];
		}
	}

	int res = 0;

	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			int sum = 0;
			for(int k = 0 ;; k++){
				if(i-k == -1 || j+k == n)break;
				sum += a[i-k][j+k];
				ans[i-k][j][k] -= sum;
			}
		}
	}

	for(int i = 0 ; i <  n ; i++){
		for(int j = 0 ; j < n ; j++){
			int sum = 0;
			for(int k = 0 ;  ;k ++){
				if(i+k == n || j + k == n)break;
				sum += a[i+k][j+k];
				ans[i][j][k] += sum;
				res = max(res , ans[i][j][k]);
			}
		}
	}

	printf("%d\n",res);



	return 0;
}