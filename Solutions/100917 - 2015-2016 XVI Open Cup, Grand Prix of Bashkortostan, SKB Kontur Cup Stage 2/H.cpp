// 2015-2016 XVI Open Cup, Grand Prix of Bashkortostan, SKB Kontur Cup Stage 2
// 100917H

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
const int di[] = {0, 0, 1, -1};
const int dj[] = {1, -1, 0, 0};
const ll MOD = 1e9 + 7;
const long double EPS = 1e-6;
#define all(x) x.begin(),x.end()
#define x first
#define y second

#include <ext/hash_set>
#include <ext/numeric>

struct data {
	int yy, mm, dd;
	int dep, id;
	string name;

	bool operator<(const data &tmp) const {
		if (yy != tmp.yy)
			return yy < tmp.yy;
		if (mm != tmp.mm)
			return mm < tmp.mm;
		if (dd != tmp.dd)
			return dd < tmp.dd;
		if (dep != tmp.dep)
			return dep < tmp.dep;
		return id < tmp.id;
	}
};

set<data> office;
map<int, set<data> > department;
map<int, vector<data> > depId;

int main() {
//	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int q;
	scanf("%d", &q);
	while (q--) {
		int t, dep;
		scanf(" %d %d", &t, &dep);
		if (t == 1) {
			char s[11];
			scanf(" %s", s);
			string name;
			int dd, mm, yy;
			for (int i = 0; s[i]; i++)
				name += s[i];
			scanf(" %02d:%02d:%04d", &dd, &mm, &yy);
			int id = depId[dep].size();
			data cur;
			cur.dd = dd, cur.mm = mm, cur.yy = yy, cur.dep = dep, cur.id = id, cur.name = name;
			department[dep].insert(cur);
			office.insert(cur);
			depId[dep].push_back(cur);
		}
		else {
			int id;
			scanf(" %d", &id);
			id--;
			data cur = depId[dep][id];
//			cout << department[dep].find(cur)->name;
			department[dep].erase(cur);
			office.erase(cur);
		}
		if (office.empty())
			printf("Vacant ");
		else
			printf("%s ", office.begin()->name.c_str());
		if (department[dep].empty())
			puts("Vacant");
		else
			printf("%s\n", department[dep].begin()->name.c_str());
	}

	return 0;
}