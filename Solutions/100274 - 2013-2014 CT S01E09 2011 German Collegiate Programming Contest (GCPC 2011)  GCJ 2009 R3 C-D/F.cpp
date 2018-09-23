// 2013-2014 CT S01E09 2011 German Collegiate Programming Contest (GCPC 2011)  GCJ 2009 R3 C-D
// 100274F

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
const long double EPS = 1e-5;
#define all(x) x.begin(),x.end()
#include <ext/hash_set>
#include <ext/numeric>

string decrypt(string s, int c) {
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == ' ') continue;
		s[i] -= c;
		if (s[i] < 'A')
			s[i] += 26;
	}
	return s;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int t;
	cin >> t;
	cin.ignore();
	while(t--){
		string s;
		getline(cin, s);
		map<int, vector<pair<string, int>>> m;
		for (int i = 0; i <= 25; ++i) {
			string org = decrypt(s, i);
			m[count(all(org), 'E')].push_back({org,i});
		}

		if (m.rbegin()->second.size() > 1)
			cout << "NOT POSSIBLE" << endl;
		else
			cout << m.rbegin()->second[0].second << " " << m.rbegin()->second[0].first << endl;
	}
}