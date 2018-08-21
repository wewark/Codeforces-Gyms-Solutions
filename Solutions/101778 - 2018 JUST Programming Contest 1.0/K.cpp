// 101778 - 2018 JUST Programming Contest 1.0
// 101778K

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<double, int> pii;
typedef vector<pii> vii;
typedef vector<bool> vb;
typedef vector<string> vs;
const int di[] = { 0, 1 };
const int dj[] = { 1, 0 };
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const long double EPS = 1e-7;
#define all(n) n.begin(),n.end()

struct Submission {
	int pid, sid, crct, mm, ss;

	Submission() {}

	bool operator < (Submission other) const {
		if (mm != other.mm)
			return mm < other.mm;
		return ss < other.ss;
	}
};

struct Student {
	int sid;
	vi subs;
	vb ac;

	Student(int np) {
		subs.assign(np, 0);
		ac.assign(np, false);
	}
};

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, m, k;
		cin >> n >> m >> k;

		vi fsolve(n, -2);
		vector<Submission> sub(k);
		vector<Student> st(m, n);

		for (int i = 0; i < m; i++) {
			st[i].sid = i;
		}

		for (Submission& i : sub) {
			string s;
			cin >> i.pid >> i.sid >> i.crct >> s;
			i.pid--, i.sid--;

			i.mm = stoi(s.substr(0, 3));
			i.ss = stoi(s.substr(4));
		}

		sort(all(sub));
		

		int extreme = -2, last = -2;
		int rmx = -1, rs = -2;
		for (Submission& i : sub) {
			st[i.sid].subs[i.pid]++;
			if (i.crct) {
				if (fsolve[i.pid] == -2)
					fsolve[i.pid] = i.sid;
				
				if (extreme == -2)
					extreme = i.sid;

				last = i.sid;
				st[i.sid].ac[i.pid] = true;
				
				if (st[i.sid].subs[i.pid] > rmx ||
					st[i.sid].subs[i.pid] == rmx && i.sid < rs)
					rmx = st[i.sid].subs[i.pid], rs = i.sid;
			}
		}

		int smx = -1, ss = -2;
		for (Student& i : st) {
			int cnt = 0;
			for (int j = 0; j < n; j++) {
				if (i.ac[j] && i.subs[j] == 1)
					cnt++;
			}
			if (cnt > smx)
				smx = cnt, ss = i.sid;
		}

		for (int i = 0; i < n; i++) {
			cout << fsolve[i] + 1 << " \n"[i == n - 1];
		}
		cout << extreme + 1 << " " << last + 1 << " " << ss + 1 << " " << rs + 1 << endl;
	}
	cin.ignore(), cin.get();
}
