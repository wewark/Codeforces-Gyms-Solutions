// 2018 USP Try-outs
// 101879I

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
const int di[] = { 0, 0, 1, -1 };
const int dj[] = { 1, -1, 0, 0 };
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const long double EPS = 1e-6;
#define all(x) x.begin(),x.end()
#define fr first
#define sc second

int n, k;

vii path;
void solve(int disk, int st, int ed, int aux) {
	if (disk == 0) return;
	
	solve(disk - 1, st, aux, ed);
	path.emplace_back(st, ed);
	solve(disk - 1, aux, ed, st);
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> k;
	if (k < (1 << n) - 1) {
		cout << "N" << endl; return 0;
	}

	solve(n, 0, 2, 1);
	if (path.size() < k) {
		int cur = path.back().first;
		path.pop_back();
		while (path.size() < k - 1) {
			path.emplace_back(cur, (cur + 1) % 2);
			cur = (cur + 1) % 2;
		}
		path.emplace_back(cur, 2);
	}

	cout << "Y" << endl;
	char c[] = { 'A','B','C' };
	for (int i = 0; i < path.size(); i++) {
		cout << c[path[i].first] << " " << c[path[i].second] << endl;
	}
}
