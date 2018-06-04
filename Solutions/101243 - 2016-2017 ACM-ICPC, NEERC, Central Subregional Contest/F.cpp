#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
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
#define all(x) x.begin(),x.end()

int find(vector<int> &C, int x) { return (C[x] == x) ? x : C[x] = find(C, C[x]); }
void merge(vector<int> &C, int x, int y) { C[find(C, x)] = find(C, y); }

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	int n, m; cin >> n >> m;
	vii gt, eq;
	for (int i = 0; i < m; i++) {
		string s; cin >> s;
		if (s.find('>') != string::npos)
			gt.push_back({ stoi(s.substr(0,s.find('>'))) - 1, stoi(s.substr(s.find('>') + 1)) - 1 });
		else if (s.find('<') != string::npos)
			gt.push_back({ stoi(s.substr(s.find('<') + 1)) - 1, stoi(s.substr(0,s.find('<'))) - 1 });
		else if (s.find('=') != string::npos)
			eq.push_back({ stoi(s.substr(0,s.find('='))) - 1, stoi(s.substr(s.find('=') + 1)) - 1 });
	}

	vector<int> C(n);
	for (int i = 0; i < n; i++) C[i] = i;
	for (int i = 0; i < eq.size(); i++) {
		merge(C, eq[i].first, eq[i].second);
	}

	int mid = -1;
	map<int, bool> isgt, islt;
	for (int i = 0; i < gt.size(); i++) {
		if (isgt[find(C, gt[i].second)]) {
			if (mid == -1)
				mid = find(C, gt[i].second);
			else
				merge(C, mid, gt[i].second);
		}
		if (islt[find(C, gt[i].first)]) {
			if (mid == -1)
				mid = find(C, gt[i].first);
			else
				merge(C, mid, gt[i].first);
		}
		isgt[find(C, gt[i].first)] = true;
		islt[find(C, gt[i].second)] = true;
	}

	vector<char> r(n, '?');
	for (int i = 0; i < gt.size(); i++) {
		if (mid != -1 && find(C, gt[i].first) == find(C, mid)) {
			r[find(C, gt[i].first)] = 'R';
			r[find(C, gt[i].second)] = 'B';
		}
		else if (mid != -1 && find(C, gt[i].second) == find(C, mid)) {
			r[find(C, gt[i].first)] = 'W';
			r[find(C, gt[i].second)] = 'R';
		}
	}

	for (int i = 0; i < n; i++) {
		cout << r[find(C, i)];
	}
	cout << endl;
	cin.ignore(), cin.get();
}
