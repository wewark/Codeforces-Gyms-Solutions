#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
typedef vector<unsigned long long> vi;
typedef vector<vi> vvi;
typedef pair<unsigned long long, unsigned long long> pii;
typedef vector<pii> vii;
typedef vector<bool> vb;
typedef vector<string> vs;
int n, m, c = 0, ch = 1;
bool valid(int i, int j) {
	return (i >= 0 && j >= 0 && i < n && j < m);
}

int dx[] = { 0, 1, -1, 0 };
int dy[] = { 1, 0, 0, -1 };
int main() {
	ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;
	char a[n][m];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == '#')
				continue;
			c = 0;
			for (int k = 0; k < 4; k++) {
				if (valid(i + dx[k], j + dy[k])
						&& a[i + dx[k]][j + dy[k]] != '#')
					c++;
			}
			if (c >= 3) {
				cout << "YES" << endl;
				return 0;
			}
			if (c == 1)
				ch = 0;
		}
	}
	if (ch)
		cout << "YES";
	else
		cout << "NO";
	cout << endl;

}
