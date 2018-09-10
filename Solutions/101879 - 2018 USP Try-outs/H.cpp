// 2018 USP Try-outs
// 101879H

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
const int di[] = { 0,0,1,-1,1,-1,-1,1 };
const int dj[] = { 1,-1,0,0,1,-1,1,-1 };
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const long double EPS = 1e-6;
#define all(x) x.begin(),x.end()
#define fr first
#define sc second

struct Query {
	int a, b, idx;
};

int n, m;
vi num;
vector<Query> q;
int block;
unordered_map<int, int> cnt;
vi numcnt;
set<int> st;

inline void insert(int x) {
	cnt[x]++;
	int cx = cnt[x];
	numcnt[cx]++;
	if (numcnt[cx] == cx)
		st.insert(cx);
}

inline void remove(int x) {
	int cx = cnt[x];
	if (numcnt[cx] == cx)
		st.erase(cx);
	numcnt[cx]--;
	cnt[x]--;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	num.resize(n);
	numcnt.resize(n + 1);
	for (auto& i : num) {
		cin >> i;
	}

	q.resize(m);
	for (int i = 0; i < m; i++) {
		cin >> q[i].a >> q[i].b;
		q[i].a--, q[i].b--;
		q[i].idx = i;
	}

	block = sqrt(n);
	sort(all(q), [](Query& a, Query& b) {
		if (a.a / block != b.a / block)
			return a.a / block < b.a / block;
		return a.b > b.b;
	});

	int a = 0, b = -1;
	for (int i = 0; i < m; i++) {
		while (a < q[i].a) remove(num[a++]);
		while (a > q[i].a) insert(num[--a]);
		while (b < q[i].b) insert(num[++b]);
		while (b > q[i].b) remove(num[b--]);
		if (st.empty()) q[i].a = 0;
		else q[i].a = *st.rbegin();
	}

	sort(all(q), [](Query& a, Query& b) {
		return a.idx < b.idx;
	});

	for (auto& i : q) {
		cout << i.a << endl;
	}
}
