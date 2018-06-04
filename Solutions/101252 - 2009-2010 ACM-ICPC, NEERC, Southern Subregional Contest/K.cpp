#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
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
const long double EPS = 1e-7;
#define all(x) x.begin(),x.end()

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	vs line;
	string s;
	//cin.ignore();
	while (getline(cin, s)) line.push_back(s);

	string cur = "";
	int c = 0;
	for (int i = 0; i < line.size(); i++) {
		while (line[i].substr(0, c) != cur) {
			if (cur.back() == '*')
				cout << "</ul>\n";
			else
				cout << "</ol>\n";
			cur.pop_back(), c--;
			if (c) cout << "</li>\n";
		}


		if (i < line.size() - 1)
			while (line[i + 1].substr(0, c) == cur &&
				c < line[i].size() && c < line[i + 1].size() &&
				line[i][c] == line[i + 1][c] && !isalnum(line[i][c]) && !isalnum(line[i + 1][c])) {
				if (c) cout << "<li>\n";
				cur += line[i][c++];
				if (cur.back() == '*')
					cout << "<ul>\n";
				else
					cout << "<ol>\n";
			}

		if (c) cout << "<li>\n";
		cout << line[i].substr(c) << endl;
		if (c) cout << "</li>\n";
	}

	while (c) {
		if (cur.back() == '*')
			cout << "</ul>\n";
		else
			cout << "</ol>\n";
		cur.pop_back(), c--;
		if (c) cout << "</li>\n";
	}

	cin.ignore(), cin.get();
}
