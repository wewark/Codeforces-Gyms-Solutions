// 2013-2014 CT S01E09 2011 German Collegiate Programming Contest (GCPC 2011)  GCJ 2009 R3 C-D
// 100274J

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
const int di[] = {0, 0, 1, -1};
const int dj[] = {1, -1, 0, 0};
const ll MOD = 1e9 + 7;
const long double EPS = 1e-5;
#define all(x) x.begin(),x.end()
#include <ext/hash_set>
#include <ext/numeric>

const int N = 1e5 + 5;
vi adj[N];
int mx , node;

void dfs(int u , int p , int lvl){
	if(lvl > mx){
		mx = lvl;
		node = u;
	}

	for(int nxt : adj[u])
		if(nxt != p)
			dfs(nxt , u , lvl+1);
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
//	cout<<"sdfsdf"<<endl;
	int t;
	cin >> t;
	while(t--){
		int n , a , b;
		cin >> n;
		for(int i = 0 ; i < n ; i++){
			adj[i].clear();
		}
		for(int i = 0 ; i < n-1 ; i++){
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		mx = -1;
		dfs(0,-1,0);
		mx = -1;
		dfs(node,-1,0);
		mx++;
		printf("%d\n",mx/2);
	}
}