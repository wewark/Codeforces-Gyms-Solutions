// 100738 - KTU Programming Camp (Day 2)
// 100738D

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
const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, 1, 0, -1 };
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const double EPS = 1e-5;
#define mp make_pair
#define all(x) x.begin(),x.end()

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int n; cin >> n;
	vii num(n);
	for (int i = 0; i < n; i++) {
		cin >> num[i].first;
		num[i].second = i;
	}

	vvi adj(n);
	bool w = false;
	sort(num.rbegin(), num.rend());
	for (int i = num.size() - 1; i >= 0 && !w; i--) {
		while (num[i].first > 1 || i == 0 && num[i].first == 1) {
			if (i == num.size() - 1) {
				w = true; break;
			}

			adj[num[i].second].push_back(num.back().second);
			num.pop_back();
			num[i].first--;
		}
	}


	//if (vrt[0].first == 0 && n > 1 || n == 1) w = true;

	//while (!vrt.empty() && !w) {
	//	pii cur = *vrt.begin(); vrt.erase(vrt.begin());
	//	vii buf;
	//	for (auto i = vrt.begin(); i != vrt.end() && cur.first; i = vrt.begin()) {
	//		buf.push_back(*i);
	//		vrt.erase(vrt.begin());
	//		if (buf.back().first == 0) {
	//			w = true; break;
	//		}

	//		adj[cur.second].push_back(buf.back().second);
	//		cur.first--;
	//		buf.back().first--;
	//	}

	//	if (cur.first) w = true;
	//	for (int i = 0; i < buf.size(); i++)
	//		if (buf[i].first)
	//			vrt.insert(buf[i]);
	//}

	if (w) cout << "-1\n";
	else {
		int cnt = 0;
		for (int i = 0; i < adj.size(); i++)
			for (int j = 0; j < adj[i].size(); j++)
				cnt++;
		if (cnt == n - 1)
			for (int i = 0; i < adj.size(); i++)
				for (int j = 0; j < adj[i].size(); j++)
					cout << i + 1 << " " << adj[i][j] + 1 << endl;
		else cout << "-1\n" << endl;
	}
	cin.ignore(), cin.get();
}