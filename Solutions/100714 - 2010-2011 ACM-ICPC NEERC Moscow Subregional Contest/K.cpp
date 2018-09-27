// 2010-2011 ACM-ICPC NEERC Moscow Subregional Contest
// 100714K

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
const int di[] = { 0, 0, 1, -1 };
const int dj[] = { 1, -1, 0, 0 };
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const long double EPS = 1e-6;
#define all(x) x.begin(),x.end()
#define fr first
#define sc second

int n, m;
vector<vb> vis;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	deque<pair<int, pii>> rw;
	for (int i = 0; i < n; i++)
		rw.push_back({ i, {0,m - 1} });

	while (true) {
		cout << rw[0].first + 1 << " " << rw[0].second.first + 1 << endl;
		string res; cin >> res;
		if (res == "DETECTED") return 0;

		rw[0].second.first++;
		if (rw[0].second.first > rw[0].second.second)
			rw.erase(rw.begin());

		vi rm;
		if (res == "L") {
			for (int i = 0; i < rw.size(); i++) {
				rw[i].second.first = max(0, rw[i].second.first - 1);
				rw[i].second.second--;
				if (rw[i].second.first > rw[i].second.second)
					rm.push_back(i);
			}
			for (auto& i : rm)
				rw.erase(rw.begin() + i);
		}
		else if (res == "R") {
			for (int i = 0; i < rw.size(); i++) {
				rw[i].second.first++;
				rw[i].second.second = min(m - 1, rw[i].second.second + 1);
				if (rw[i].second.first > rw[i].second.second)
					rm.push_back(i);
			}
			for (auto& i : rm)
				rw.erase(rw.begin() + i);
		}
		else if (res == "U") {
			if (rw[0].first) {
				rw.push_front(rw[0]);
				rw[0].first--;
				if (rw.size() > 1)
					rw[1].second = rw[2].second;
				rw.pop_back();
			}
			else {
				rw[0].second = rw[1].second;
				rw.pop_back();
			}
		}
		else if (res == "D") {
			if (rw.back().first < n - 1) {
				rw.push_back(rw.back());
				rw.back().first++;
				if (rw.size() > 1)
					rw[1].second = rw[0].second;
				rw.pop_front();
			}
			else {
				rw[1].second = rw[0].second;
				rw.pop_front();
			}
		}
	}

}
