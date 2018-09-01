// 2015-2016 ACM-ICPC Nordic Collegiate Programming Contest (NCPC 2015)
// 100781C

#include <bits/stdc++.h>
#include <ext/hash_map>
#include <ext/hash_set>

#define fr first
#define sc second

using namespace __gnu_cxx;
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef pair<pii, pii> ppii;

const int MOD = 1e9 + 7;
const int N = 1e5 + 5;
vi adj[N];
int n , m;
int node , mx;
int vis[N];

void dfs(int u , int par , int _lvl = 0){
	if(_lvl > mx){
		mx = _lvl;
		node = u;
	}
	vis[u] = 1;
	for(int nxt : adj[u]){
		if(nxt == par)continue;
		dfs(nxt , u , _lvl+1);
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
#endif
	string s;
	cin >> s;
	int n = s.size();
	int res = n;
	for (int i = 0; i < n; i += 3) {
		if (s[i] == 'P')
			res--;
		if (s[i + 1] == 'E')
			res--;
		if (s[i + 2] == 'R')
			res--;
	}
	cout << res << endl;
}