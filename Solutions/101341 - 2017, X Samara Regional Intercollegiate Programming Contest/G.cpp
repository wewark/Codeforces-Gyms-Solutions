// 101341 - 2017, X Samara Regional Intercollegiate Programming Contest
// 101341G

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
const int di[] = { -1,0,1,0 };
const int dj[] = { 0,1,0,-1 };
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
#define mp make_pair

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int n; cin >> n;
	vector<pair<int, string>> name(n);
	for (int i = 0; i < n; i++)
		cin >> name[i].second;
	int m; cin >> m;
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v; u--, v--;
		name[u].second = name[v].second;
		name[u].first = name[v].first + 1;
	}
	for (int i = 0; i < name[0].first; i++)
		cout << "I_love_";
	cout << name[0].second << endl;
	//cin.ignore(), cin.get();
}
