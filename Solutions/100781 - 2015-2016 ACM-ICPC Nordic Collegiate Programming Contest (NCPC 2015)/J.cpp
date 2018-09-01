// 2015-2016 ACM-ICPC Nordic Collegiate Programming Contest (NCPC 2015)
// 100781J

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
const int MOD = 1e9 + 7;
const int N = 1e5 + 5;
vi adj[N];
int cnt[N] , best[N];
double dp[N][102];
unordered_map<int,int> MAP[N];
map<string,int> m;
string str[N];
string s, ans;
int n , t , id , ansid;
int nodeID;
vector<int> v;
map<int,int> wordCnt[N];

void Insert(int u = 0 , int idx = 0){
	cnt[u]++;
	if(idx == v.size()){
		wordCnt[u][ansid]++;
		return;
	}

	if(MAP[u].find(v[idx]) == MAP[u].end()){
		MAP[u][v[idx]] = ++nodeID;
		adj[u].push_back(nodeID);
	}
	Insert(MAP[u][v[idx]] , idx+1);
}

void dfs(int u = 0){
	for(int nxt : adj[u]){
		dfs(nxt);
		for(auto &i : wordCnt[nxt]){
			wordCnt[u][i.first] += i.second;
		}
		wordCnt[nxt].clear();
	}

	for(auto &i : wordCnt[u]){
		best[u] = max(best[u],i.second);
	}
}

double solve(int u = 0 , int time = t){
	if (!time) return 0;

	double& ret = dp[u][time];
	if (ret == ret) return ret;
	ret = 0;
	double a = 0 , b = 0;
	for (int &i : adj[u]) {
		b += solve(i, time - 1) * (cnt[i] / (double)cnt[u]);
	}
	a = max(ret, best[u] / (double)cnt[u] + solve(0, time - 1));

	return ret = max(a,b);
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
#endif

	cin >> t >> n;
	cin.ignore();
	string cur;
	for(int i = 0 ; i < n ; i++){
		getline(cin , s);
		stringstream ss(s);
		v.clear();
		ans = "";
		while(ss >> s){
			if(m.find(s) == m.end()) {
				m[s] = ++id;
				str[id] = s;
			}
			v.push_back(m[s]);
			if(s.back() == '?')break;
		}

		while(ss >> s){
			ans += s;
			ans += ' ';
		}

		ans.pop_back();
		if(m.find(ans) == m.end()){
			m[ans] = ++id;
			str[id] = ans;
		}

		ansid = m[ans];
		Insert();
	}

	dfs(0);
	memset(dp,-1,sizeof dp);
	cout << fixed << setprecision(10) << solve() << endl;

	return 0;
}