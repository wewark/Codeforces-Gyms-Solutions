// 101726 - 2013 USP Try-outs
// 101726E

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
const long double EPS = 1e-9;
#define all(x) x.begin(),x.end()

struct Candidate {
	int idx;
	int votes;
	vi pos;

	bool operator < (const Candidate& other) const {
		if (votes != other.votes)
			return votes > other.votes;
		for (int i = 0; i < pos.size(); i++) {
			if (pos[i] != other.pos[i])
				return pos[i] > other.pos[i];
		}
		return idx < other.idx;
	}

	bool operator == (const Candidate& other) const {
		if (votes != other.votes)
			return false;
		for (int i = 0; i < pos.size(); i++) {
			if (pos[i] != other.pos[i])
				return false;
		}
		return true;
	}
};

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, k, v; cin >> n >> k >> v;
		vector<Candidate> cand(k, { 0,0,vi(v) });
		for (int i = 0; i < k; i++) {
			cand[i].idx = i;
		}
		for (int i = 0; i < n; i++) {
			int l; cin >> l;
			int cv = 0;
			for (int j = 0; j < l; j++, cv++) {
				int x; cin >> x;
				if (cv >= v || x == 0 || x > k) continue;
				x--;
				cand[x].votes++;
				cand[x].pos[cv]++;
			}
		}

		sort(all(cand));
		int cv = v;
		while (cv < k && cand[cv] == cand[v - 1])
			cv++;

		for (int i = 0; i < cv; i++) {
			cout << cand[i].idx + 1 << " \n"[i == cv - 1];
		}
	}
	cin.ignore(), cin.get();
}
