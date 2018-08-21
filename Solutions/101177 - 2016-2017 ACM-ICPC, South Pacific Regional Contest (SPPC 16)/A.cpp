#include <bits/stdc++.h>

using namespace std;

pair<int, int> get(int x) {
	if (x == 1)
		return {0, 0};
	int i = 1;
	while (x > i * i)
		i += 2;
	int j = i - 1;
	pair<int, int> cur = {-j / 2, -j / 2};
	int dif = i * i - x;
	if (dif < j)
		return {cur.first, cur.second + dif};
	dif -= j;
	cur = {cur.first, cur.second + j};
	if (dif < j)
		return {cur.first + dif, cur.second};
	dif -= j;
	cur = {cur.first + j, cur.second};
	if (dif < j)
		return {cur.first, cur.second - dif};
	dif -= j;
	cur = {cur.first, cur.second - j};
	if (dif < j)
		return {cur.first - dif, cur.second};
	assert(0);
	return cur;
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
#endif

	int a, b;
	cin >> a >> b;
	pair<int, int> aa = get(a);
	pair<int, int> bb = get(b);
	int res = abs(aa.first - bb.first) + abs(aa.second - bb.second);
	cout << res << endl;
	return 0;
}