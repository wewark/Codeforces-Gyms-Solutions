// III (XIV) Volga Region Open Team Student Programming Contest
// 100186A

#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ll;
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

const int N = 102;

int n;
string a[N][3], f[N];
int c[N][3];

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> n;
	set<string> s1a, s1b, s1c, s2a, s2b, s2c;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> a[i][j];
		}
		cin >> f[i];

		if (a[i][0] == f[i])
			s1a.insert(a[i][0]), s2a.erase(a[i][0]);
		else if (s1a.find(a[i][0]) == s1a.end())
			s2a.insert(a[i][0]);

		if (a[i][1] == f[i])
			s1b.insert(a[i][1]), s2b.erase(a[i][1]);
		else if (s1b.find(a[i][1]) == s1b.end())
			s2b.insert(a[i][1]);

		if (a[i][2] == f[i])
			s1c.insert(a[i][2]), s2c.erase(a[i][2]);
		else if (s1c.find(a[i][2]) == s1c.end())
			s2c.insert(a[i][2]);
		cout << s2a.size() << " " << s2b.size() << " " << s2c.size() << endl;
	}

	return 0;
}