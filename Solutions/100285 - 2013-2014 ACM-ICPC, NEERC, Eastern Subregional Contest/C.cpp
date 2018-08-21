// 100285 - 2013-2014 ACM-ICPC, NEERC, Eastern Subregional Contest
// 100285C

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
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};
const ll MOD = 5e6;
const ll INF = 1e8;
const long double EPS = 1e-6;
#define mp make_pair
#define all(x) x.begin(),x.end()

enum type {
	learn, rollback, relearn, clone, check
};

int n, m;
vector<vii> cl;
stack<int> a, b;
vi ch;

void dfs(int idx) {
	for (auto &i : cl[idx]) {
		if (i.first == learn)
			a.push(i.second);
		else if (i.first == rollback) {
			b.push(a.top());
			a.pop();
		}
		else if (i.first == relearn) {
			a.push(b.top());
			b.pop();
		}
		else if (i.first == clone) {
			dfs(i.second);
		}
		else if (!a.empty()) {
			ch[i.second] = a.top();
		}
	}

	for (int i = cl[idx].size() - 1; i >= 0; --i) {
		if (cl[idx][i].first == learn)
			a.pop();
		else if (cl[idx][i].first == relearn) {
			b.push(a.top());
			a.pop();
		}
		else if (cl[idx][i].first == rollback) {
			a.push(b.top());
			b.pop();
		}
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	cin >> n >> m;
	cl.emplace_back();
	int checks = 0;
	for (int i = 0; i < n; ++i) {
		string s; cin >> s;
		int idx, x; cin >> idx; idx--;
		if (s == "learn") {
			cin >> x;
			cl[idx].emplace_back(learn,x);
		}
		else if (s == "clone") {
			cl[idx].emplace_back(clone,cl.size());
			cl.emplace_back();
		}
		else if (s == "check") {
			cl[idx].emplace_back(check, checks++);
		}
		else if (s == "rollback") {
			cl[idx].emplace_back(rollback,-1);
		}
		else if (s == "relearn") {
			cl[idx].emplace_back(relearn, -1);
		}
	}

	ch.assign(checks, -1);
	dfs(0);

	for (int i : ch) {
		if (i == -1) cout << "basic" << endl;
		else cout << i << endl;
	}
	cin.ignore(), cin.get();
}
