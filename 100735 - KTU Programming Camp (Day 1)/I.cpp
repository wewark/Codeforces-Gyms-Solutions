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
#define mp make_pair
#define all(x) x.begin(),x.end()

string sum(string a, string b) {
	while (a.size() < b.size()) a = "0" + a;
	while (a.size() > b.size()) b = "0" + b;

	int carry = 0;
	string ret = "";
	for (int i = a.length() - 1; i >= 0; i--) {
		int x = a[i] + b[i] - '0' - '0' + carry;
		carry = x / 10;
		x %= 10;
		ret = to_string(x) + ret;
	}
	if (carry)
		ret = to_string(carry) + ret;
	while (ret != "0" && ret[0] == '0')
		ret = ret.substr(1);
	return ret;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	string num[3]; cin >> num[0] >> num[1] >> num[2];
	bool yes = false;
	for (int i = 0; i < 3 && !yes; i++) {
		for (int j = 0; j < 3 && !yes; j++) {
			for (int k = 0; k < 3 && !yes; k++) {
				if (sum(num[i], num[j]) == num[k])
					yes = true;
			}
		}
	}
	if (yes)
		cout << "YES\n";
	else
		cout << "NO\n";
	cin.ignore(), cin.get();
}
