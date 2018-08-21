// 101755 - 2018, XI Samara Regional Intercollegiate Programming Contest
// 101755K

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
const long double EPS = 1e-10;
#define all(n) n.begin(),n.end()

int n, m;
vi num;

inline int f(int x) {
	int c = 0;
	for (int i = 0; i < n; i++) {
		if (c >= num[i]) c++;
		else if (x) x--, c++;
	}
	return c;
}

int BS() {
	int a = 0, b = n, mid = (a + b) / 2;
	while (a < b) {
		if (f(mid) >= m)
			b = mid;
		else
			a = mid + 1;
		mid = (a + b) / 2;
	}
	return mid;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m;
	num.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	cout << BS() << endl;
	cin.ignore(), cin.get();
}
