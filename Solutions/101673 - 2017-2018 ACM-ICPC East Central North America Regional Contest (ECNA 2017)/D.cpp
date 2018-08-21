// 101673 - 2017-2018 ACM-ICPC East Central North America Regional Contest (ECNA 2017)
// 101673D

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
#define mp make_pair
#define all(x) x.begin(),x.end()

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int n, k; cin >> n >> k;
	vi q;
	for (int i = 0; i < k; i++) {
		string s; cin >> s;
		if (s == "undo") {
			int x; cin >> x;
			q.erase(q.end() - x, q.end());
		}
		else {
			q.push_back(stoi(s));
		}
	}

	int cur = 0;
	for (int i = 0; i < q.size(); i++) {
		cur += q[i];
		while (cur < 0) cur += n;
		cur %= n;
	}

	cout << cur << endl;
	//cin.ignore(), cin.get();
}
