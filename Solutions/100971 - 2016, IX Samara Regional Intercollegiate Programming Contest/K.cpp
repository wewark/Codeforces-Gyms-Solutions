// 100971 - 2016, IX Samara Regional Intercollegiate Programming Contest
// 100971K

#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
typedef vector<unsigned long long> vi;
typedef vector<vi> vvi;
typedef pair<unsigned long long, unsigned long long> pii;
typedef vector<pii> vii;
typedef vector<bool> vb;
typedef vector<string> vs;
bool isPal(string s) {
	string x = s;
	reverse(x.begin(), x.end());
	return (s == x);
}
int main() {
	ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int ch = 0;
	string s;
	cin >> s;
	int l = 0, r = s.size() - 1;
	while (l < s.size() && r >= 0) {
		if (s[l] != s[r]) {
			ch = 1;
			break;
		}
		l++;
		r--;
	}
	if (!ch) {
		cout << "YES" << endl;
		cout << s.size() / 2 + 1;
	} else {
		string a, b;
		for (int i = 0; i < s.size(); i++) {
			if (i != l)
				a += s[i];
			if (i != r)
				b += s[i];
		}
		if (isPal(a)) {
			cout << "YES" << endl;
			cout << l + 1;
		} else if (isPal(b)) {
			cout << "YES" << endl;
			cout << r + 1;
		} else
			cout << "NO";
	}

}
