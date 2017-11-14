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

vi cnt(150);

bool cmpc(char a, char b) {
	return cnt[a] < cnt[b];
}

bool cmp(string a, string b) {
	int c = 0;
	while (c < a.length() && c < b.length() && cnt[a[c]] == cnt[b[c]])
		c++;
	if (c < a.length() && c < b.length())
		return cnt[a[c]] < cnt[b[c]];
	return a.length() < b.length();
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	string s; int n;
	cin >> s >> n;
	sort(all(s), cmpc);
	vb ins(150);
	for (int i = 0; i < s.length(); i++)
		ins[s[i]] = true;

	vector<set<char>> gst;
	for (int i = 0; i < n; i++) {
		gst.push_back(set<char>());
		vb vis(150);
		for (int j = 0; j < 6; j++) {
			char x; cin >> x;
			if (!vis[x]) cnt[x]++;
			vis[x] = true;
			if (ins[x]) gst.back().insert(x);
		}
		if (gst.back().empty()) gst.pop_back();
	}

	vs g;
	for (int i = 0; i < gst.size(); i++) {
		g.push_back({});
		for (char j : gst[i])
			g[i] += j;
		sort(all(g[i]), cmpc);
	}
	sort(all(g), cmp);

	int c = 0;
	for (int i = 0; i < g.size() && c < s.length(); i++) {
			if (c < s.length() - 1 && s[c + 1] != s[c])
				for (int j = i + 1; j < g.size(); j++)
					while (g[j] != "" && g[j][0] == s[c])
						g[j].erase(g[j].begin());

			if (i < g.size() - 1)
				sort(g.begin() + i + 1, g.end(), cmp);
			c++;
	}
	cout << (c == s.length() ? "YES" : "NO") << endl;
	cin.ignore(), cin.get();
}