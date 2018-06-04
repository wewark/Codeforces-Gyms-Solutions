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
	int n; cin >> n;
	vi num(n + 1);
	queue<int> q;
	for (int i = 1; i <= n; ++i)
	{
		cin >> num[i];
		if (num[i] == i)
			q.push(i);
	}
	cout << ceil(q.size() / 2.0) << endl;
	while (q.size() > 1)
	{
		int a = q.front(), b;
		q.pop(), b = q.front(), q.pop();
		cout << a << " " << b << endl;
		swap(num[a], num[b]);
	}
	if (q.size() == 1)
		for (int i = 1; i <= n; ++i)
			if (i != num[q.front()] && num[i] != q.front())
			{
				cout << i << " " << q.front() << endl;
				break;
			}
}
