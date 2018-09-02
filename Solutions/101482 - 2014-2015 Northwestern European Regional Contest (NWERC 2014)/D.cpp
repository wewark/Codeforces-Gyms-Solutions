// 2014-2015 Northwestern European Regional Contest (NWERC 2014)
// 101482D

#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
long long n;
int m;
int L[N], R[N], deg[N];
int state[N];
int vis[N];
long long in[N];

void solve() {
	for (int i = 1; i <= m; i++) {
		printf("%c", state[i]);
	}
	puts("");
}

int main() {
	char c;
	scanf("%lld %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf(" %c %d %d", &c, &L[i], &R[i]);
		state[i] = c;
		deg[L[i]]++;
		deg[R[i]]++;
	}

	queue<int> q;
	for(int i=0;i<m;++i)
if(!deg[i]) q.push(i);
	in[1] = n;

	while (!q.empty()) {
		int u = q.front();
		q.pop();
		if (!u)
			continue;

		long long x = (in[u] + 1) / 2;
		long long y = in[u] - x;
		if (state[u] == 'R') {
			in[R[u]] += x;
			in[L[u]] += y;
		}
		else {
			in[L[u]] += x;
			in[R[u]] += y;
		}

		if (in[u] & 1LL) {
			if (state[u] == 'R')
				state[u] = 'L';
			else
				state[u] = 'R';
		}
		in[u] = 0;

		deg[L[u]]--;
		if (!vis[L[u]] && deg[L[u]] <= 0)
			q.push(L[u]), vis[L[u]] = 1;
		deg[R[u]]--;
		if (!vis[R[u]] && deg[R[u]] <= 0)
			q.push(R[u]), vis[R[u]] = 1;
	}

	solve();

	return 0;
}