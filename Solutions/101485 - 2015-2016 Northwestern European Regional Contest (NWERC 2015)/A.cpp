// 101485 - 2015-2016 Northwestern European Regional Contest (NWERC 2015)
// 101485A

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
const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, 1, 0, -1 };
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const double EPS = 1e-5;
const int N = 2e5 + 7;
#define mp make_pair
#define all(x) x.begin(),x.end()

ll n, m;
vector<pair<ll, ll>> emp;

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m;
	emp.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> emp[i].first >> emp[i].second;
		emp[i].second += emp[i].first;
	}
	sort(all(emp));

	priority_queue<ll, vll, greater<ll>> pq;
	int r = 0;
	for (int i = 0; i < n; i++) {
		while (!pq.empty() && emp[i].first - pq.top() > m)
			pq.pop();
		if (!pq.empty() && emp[i].first >= pq.top() && emp[i].first - pq.top() <= m)
			r++, pq.pop();
		pq.push(emp[i].second);
	}
	cout << r << endl;
	cin.ignore(), cin.get();
}
