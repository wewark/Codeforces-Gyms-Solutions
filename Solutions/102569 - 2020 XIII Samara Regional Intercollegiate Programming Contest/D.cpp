// 2020 XIII Samara Regional Intercollegiate Programming Contest
// 102569D - BFS

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vb = vector<bool>;
using pii = pair<int, int>;
using vii = vector<pii>;
using vs = vector<string>;
#define all(x) x.begin(), x.end()
// int di[] = {0, 1, 0, -1};
// int dj[] = {1, 0, -1, 0};
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const double PI = 3.14159265359;



int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#else
	//	freopen("document.in", "r", stdin);
//	freopen("document.out", "w", stdout);
#endif

	int n, m; cin >> n >> m;
	vector<vector<pair<int, char>>> adj(n);
	for (int i = 0; i < m; ++i) {
		int u, v; char c;
		cin >> u >> v >> c; u--, v--;
		adj[u].emplace_back(v, c);
		adj[v].emplace_back(u, c);
	}

	for (auto& i : adj) {
		sort(all(i), [](pair<int, char>& a, pair<int, char>& b) {
		  return a.second < b.second;
		});
	}

	vb vis(n);
	vi distn(n);
	vi prv(n, -1);
	vector<char> prvChar(n);
	queue<int> q;

	vis.assign(n, false);
	q.push(n - 1); vis[n - 1] = true;
	distn[n - 1] = 0;
	while (!q.empty()) {
		int cur = q.front(); q.pop();

		for (auto& i : adj[cur]) {
			if (!vis[i.first]) {
				distn[i.first] = distn[cur] + 1;
				vis[i.first] = true;
				q.push(i.first);
			}
		}
	}

	vis.assign(n, false);
	q.push(0); vis[0] = true;
	while (!q.empty()) {
		vi v = { q.front() }; q.pop();
		while (!q.empty() && distn[q.front()] == distn[v[0]]) {
			v.push_back(q.front());
			q.pop();
		}

		char mn = 'z' + 1;
		for (auto& cur : v) {
			for (auto &i : adj[cur]) {
				int v = i.first;
				if ((!vis[v] ||
					vis[v] && i.second < prvChar[v]) &&
					distn[v] == distn[cur] - 1) {
					mn = min(mn, i.second);
				}
			}
		}

		for (auto& cur : v) {
			for (auto &i : adj[cur]) {
				int v = i.first;
				if ((!vis[v] ||
					vis[v] && i.second < prvChar[v]) &&
					distn[v] == distn[cur] - 1 &&
					i.second == mn) {
					prv[i.first] = cur;
					prvChar[i.first] = i.second;
					vis[i.first] = true;
					q.push(i.first);
				}
			}
		}
	}

	vi path;
	string pathStr;
	int cur = n - 1;
	while (cur) {
		path.push_back(cur);
		pathStr.push_back(prvChar[cur]);
		cur = prv[cur];
	}
	path.push_back(0);

	reverse(all(path));
	reverse(all(pathStr));
	cout << path.size() - 1 << endl;
	for (int i = 0; i < path.size(); ++i) {
		cout << path[i] + 1 << " \n"[i == path.size() - 1];
	}
	cout << pathStr << endl;
}
