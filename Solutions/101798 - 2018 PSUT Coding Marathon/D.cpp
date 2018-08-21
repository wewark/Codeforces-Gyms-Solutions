// 101798 - 2018 PSUT Coding Marathon
// 101798D

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
const int di[] = { 0, 1 };
const int dj[] = { 1, 0 };
const ll MOD = 1e9 + 9;
const ll INF = 1e9;
const long double EPS = 1e-7;
#define all(n) n.begin(),n.end()

int n;
vvi adj;
vi prnt, num;

int shift = 1;
void bfs(int root) {
	queue<int> q; q.push(root);
	int curNum = 0;
	while (!q.empty()) {
		int cur = q.front(); q.pop();

		num[cur] = shift - curNum++;

		for (int i = 0; i < adj[cur].size(); i++) {
			q.push(adj[cur][i]);
		}
	}
	
	q.push(root);
	while (!q.empty()) {
		int cur = q.front(); q.pop();

		num[cur] += curNum - 1;

		for (int i = 0; i < adj[cur].size(); i++) {
			q.push(adj[cur][i]);
		}
	}

	shift += curNum;
}

vi r;
void dfs(int node) {
	for (int i = adj[node].size() - 1; i >= 0; i--) {
		r.push_back(num[adj[node][i]]);
		dfs(adj[node][i]);
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n;
	prnt.resize(n);
	adj.assign(n, vi());
	for (int i = 0; i < n; i++) {
		cin >> prnt[i]; prnt[i]--;
		if (~prnt[i])
			adj[prnt[i]].push_back(i);
	}

	num.assign(n, 0);
	for (int i = 0; i < n; i++) {
		if (prnt[i] == -1) {
			bfs(i);
			r.push_back(num[i]);
			dfs(i);
		}
	}

	for (int i = 0; i < n; i++) {
		cout << r[i] << " \n"[i == n - 1];
	}

	cin.ignore(), cin.get();
}
