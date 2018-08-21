// 101755 - 2018, XI Samara Regional Intercollegiate Programming Contest
// 101755F

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
const int di[] = { -1, 0, 1, 0, -1, 1, 1, -1 };
const int dj[] = { 0, 1, 0, -1, -1, 1, -1, 1 };
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const long double EPS = 1e-10;
#define all(n) n.begin(),n.end()

int n;
vvi adj;
vector<set<int>> suc;
bool yes = true;

vb vis;
vi ans;
void dfs(int node) {
	if (vis[node]) {
		yes = false; return;
	}
	vis[node] = true;
	
	for (int& i : ans) {
		if (suc[i].find(node) == suc[i].end())
			yes = false;
		suc[i].erase(node);
	}

	ans.push_back(node);
	for (int i = 0; i < adj[node].size(); i++) {
		dfs(adj[node][i]);
	}
	ans.pop_back();
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n;
	suc.assign(n, set<int>());
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		for (int j = 0; j < x; j++) {
			int h; cin >> h; h--;
			suc[i].insert(h);
		}
	}

	adj.assign(n, vi());
	int root = -1;
	for (int i = 0; i < n; i++) {
		int mn = n, mni = -1;
		for (int j = 0; j < n; j++) {
			if (j != i && suc[j].find(i) != suc[j].end() && suc[j].size() < mn)
				mn = suc[j].size(), mni = j;
		}

		if (mni == -1) {
			if (root == -1) root = i;
			else {
				yes = false; break;
			}
		}
		if (i != root)
			adj[mni].push_back(i);
	}

	vis.assign(n, false);
	if (root == -1)
		yes = false;
	else if (yes)
		dfs(root);

	for (int i = 0; i < n; i++) {
		if (!suc[i].empty()) {
			yes = false; break;
		}
	}

	if (yes) {
		cout << "YES\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < adj[i].size(); j++) {
				cout << i + 1 << " " << adj[i][j] + 1 << endl;
			}
		}
	}
	else cout << "NO\n";
	cin.ignore(), cin.get();
}
