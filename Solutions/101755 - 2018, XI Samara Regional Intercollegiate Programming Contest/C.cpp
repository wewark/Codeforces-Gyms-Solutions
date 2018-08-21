// 101755 - 2018, XI Samara Regional Intercollegiate Programming Contest
// 101755C

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

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int n; cin >> n;
	vii p(n);
	map<int, pair<set<int>, set<int>>> m;
	for (int i = 0; i < n; i++) {
		cin >> p[i].first >> p[i].second;
		m[p[i].first].first.insert(i);
		m[p[i].second].second.insert(i);
	}

	vi r;
	set<int> started;
	for (auto& i : m) {
		started.insert(all(i.second.first));
		if (!i.second.second.empty()) {
			r.push_back(i.first);
			for (auto& j : started) {
				m[p[j].first].first.erase(j);
				m[p[j].second].second.erase(j);
			}
			started.clear();
		}
	}

	cout << r.size() << endl;
	for (int i = 0; i < r.size(); i++) {
		cout << r[i] << " \n"[i == r.size() - 1];
	}
	cin.ignore(), cin.get();
}
