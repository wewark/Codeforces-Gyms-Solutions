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

vii solve(int h, int w) {
	vii ret;
	for (int i = 0; i < h - 1; i += 2) {
		bool last = i + 1 == h - 2 && h % 2 == 1;
		if (last) for (int j = 0; j < w - 1; j += 2)
			ret.push_back({ i + 1, j });

		for (int j = 0; j < w - 1; j++)
			ret.push_back({ i,j });

		if (last) break;
		if (w > 2 && i + 1 < h - 1)
			ret.push_back({ i + 1,w - 2 });


		i += 2;
		if (i >= h - 1) break;

		last = i + 1 == h - 2 && h % 2 == 1;
		if (last) for (int j = 0; j < w - 1; j += 2)
			ret.push_back({ i + 1, j });

		for (int j = w - 2; j >= 0; j--)
			ret.push_back({ i,j });

		if (last) break;
		if (w > 2 && i + 1 < h - 1)
			ret.push_back({ i + 1,0 });
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	int h, w;
	cin >> h >> w;
	vii v1 = solve(h, w);
	vii v2 = solve(w, h);

	if (v1.size() > v2.size()) {
		cout << v1.size() << endl;
		for (int i = 0; i < v1.size(); i++) {
			cout << v1[i].first + 1 << " " << v1[i].second + 1 << endl;
		}
	}
	else {
		cout << v2.size() << endl;
		for (int i = 0; i < v2.size(); i++) {
			cout << v2[i].second + 1 << " " << v2[i].first + 1 << endl;
		}
	}
	cin.ignore(), cin.get();
}
