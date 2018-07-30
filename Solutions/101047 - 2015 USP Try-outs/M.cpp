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
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};
const ll MOD = 1e9 + 7;
const ll INF = 1e8;
const long double EPS = 1e-10;

#define all(x) x.begin(),x.end()

const int N = 100005;

int n;
bool a[N];
char s[N];

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
//	freopen("input.txt", "r", stdin);
//	freopen("cube.in", "r", stdin);
//	freopen("cube.out", "w", stdout);

	int t; cin >> t;
	while (t--) {
		cin >> n >> s;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			cnt += (a[i] = s[i] == 'D');
		}

		if (cnt & 1) {
			cout << "Y\n";
			vector<int> res;
			stack<int> stk;
			for (int i = 0; i < n; i++) {
				if (a[i]) {
					a[i + 1] ^= 1;
					res.push_back(i);
					while (!stk.empty()) {
						res.push_back(stk.top());
						stk.pop();
					}
				} else {
					stk.push(i);
				}
			}
			for (int i = 0; i < n; i++)
				cout << res[i] + 1 << " \n"[i == n - 1];
		} else {
			cout << "N\n";
		}
	}

}