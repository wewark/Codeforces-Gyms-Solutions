// 101341 - 2017, X Samara Regional Intercollegiate Programming Contest
// 101341M

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
const int di[] = { -1,0,1,0 };
const int dj[] = { 0,1,0,-1 };
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
#define mp make_pair

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int n; cin >> n;
	vii num(n);
	ll sum = 0;
	bool w = true;
	for (int i = 0; i < n; i++) {
		cin >> num[i].first, sum += num[i].first, num[i].second = i;
		if (num[i].first == 0)
			w = false;
	}
	if (w || sum > n - 1)
		cout << "NO\n";
	else {
		cout << "YES" << endl;
		sort(num.begin(), num.end());
		int a = 0, b = 0;
		while (b < n && num[b].first == 0) b++;
		while (b < n) {
			for (int i = 0; i < num[b].first; i++)
				cout << num[b].second + 1 << " " << num[a++].second + 1 << endl;
			b++;
		}
	}
	//cin.ignore(), cin.get();
}
