// 101341 - 2017, X Samara Regional Intercollegiate Programming Contest
// 101341K

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<ll, ll> pii;
typedef vector<pii> vii;
typedef vector<bool> vb;
typedef vector<string> vs;
const int di[] = { -1,0,1,0 };
const int dj[] = { 0,1,0,-1 };
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
#define mp make_pair

int n;
vector<pair<pii, pii>> cm; // ((start, end), (usef, idx))
vi st;

vii mem(200005, pii(-1, -1));
//vi nxt(200005, -1);
// (usef,dur)
pii solve(int idx) {
	if (idx == n) return pii(0, 0);
	if (mem[idx] != pii(-1, -1)) return mem[idx];

	pii a1 = solve(idx + 1), a2 = mp(0, 0);
	auto it = lower_bound(st.begin(), st.end(), cm[idx].first.second);
	if (it != st.end())
		a2 = solve(it - st.begin());
	a2 = pii(a2.first + cm[idx].second.first,
		a2.second + cm[idx].first.second - cm[idx].first.first);
	if (a2.first > a1.first ||
		a2.first == a1.first && a2.second < a1.second)
		a1 = a2;
	return mem[idx] = a1;
}

vi path;
//void build(int idx) {
//	if (idx == n) return;
//	path.push_back(idx);
//	build(nxt[idx]);
//}
void build(int idx) {
	if (idx == n) return;

	int nxt;
	pii a1 = solve(idx + 1), a2 = mp(0, 0);
	nxt = idx + 1;
	auto it = lower_bound(st.begin(), st.end(), cm[idx].first.second);
	if (it != st.end())
		a2 = solve(it - st.begin());
	a2 = pii(a2.first + cm[idx].second.first,
		a2.second + cm[idx].first.second - cm[idx].first.first);
	if (a2.first > a1.first ||
		a2.first == a1.first && a2.second < a1.second)
		path.push_back(idx), nxt = it - st.begin();
	build(nxt);
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n;
	cm.resize(n);
	st.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> cm[i].first.first >> cm[i].first.second >> cm[i].second.first;
		cm[i].second.second = i;
	}
	//cm.back() = mp(mp(-1, -1), mp(0, n));
	sort(cm.begin(), cm.end());
	for (int i = 0; i < n; i++)
		st[i] = cm[i].first.first;

	solve(0);
	build(0);

	cout << path.size() << " " << mem[0].first << " " << mem[0].second << endl;
	for (int i = 0; i < path.size(); i++)
		cout << cm[path[i]].second.second + 1 << " \n"[i == path.size() - 1];

	//cin.ignore(), cin.get();
}
