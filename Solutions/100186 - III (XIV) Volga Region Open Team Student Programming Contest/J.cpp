// III (XIV) Volga Region Open Team Student Programming Contest
// 100186J

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

const int N = 1e5 + 5;
int vis[N] , d[N];
int visid;
int n , m;

bool check(int prot){
	if(vis[prot] == visid)return 0;
	vis[prot] = visid;
	return 1;
}

int solve(int day){
	visid++;
	int ret = 0;
	for(int i = 0 ; i < n ; i++){
		if(day % d[i] == 0){
			ret += check(day/d[i]);
		}else{
			ret += check(day/d[i]);
			ret += check(day/d[i]+1);
		}
	}
	return ret;
}

int main() {
//	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d%d",&n,&m);
	for(int i = 0 ; i < n ; i++){
		scanf("%d",&d[i]);
	}

	int ans = 0;
	for(int i = 1 ; i <= min(1000,m) ; i++){
		ans = max(ans , solve(i));
	}

	for(int i = m ; i >= max(m-1000,0) ; i--){
		ans = max(ans, solve(i));
	}

	printf("%d\n",ans);

	return 0;
}