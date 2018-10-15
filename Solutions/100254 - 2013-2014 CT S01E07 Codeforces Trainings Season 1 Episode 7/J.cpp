// 2013-2014 CT S01E07 Codeforces Trainings Season 1 Episode 7
// 100254J

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

int n, k;
string s;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
int n; string s;
cin>>n>>s;
	int cnt = count(all(s), 'L');
	cnt/=2;
	int ans = n - cnt+1;
	cout<<min(ans,n)<<endl;
	return 0;
}