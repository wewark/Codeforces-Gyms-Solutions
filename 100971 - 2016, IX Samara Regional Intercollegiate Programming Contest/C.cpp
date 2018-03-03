#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
typedef vector<unsigned long long> vi;
typedef vector<vi> vvi;
typedef pair<unsigned long long, unsigned long long> pii;
typedef vector<pii> vii;
typedef vector<bool> vb;
typedef vector<string> vs;

int main() {
	ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	ll n; cin >> n;
	vi num(n);
	for (ll i = 0; i < n; ++i)
		cin >> num[i];
	sort(num.begin(), num.end());
	ll cur = num[0] + num[1] - 1;
	ll tmp[] = {cur, num[0], num[n - 1]};
	sort(tmp, tmp + 3);
	if (tmp[0] + tmp[1] <= tmp[2])
		cout << "NO" << endl;
	else
		cout << "YES" << endl << cur << endl;
}
