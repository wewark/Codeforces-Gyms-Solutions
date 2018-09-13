// 2017 ACM Jordanian Collegiate Programming Contest
// 101608H

#include <bits/stdc++.h>

using namespace std;
// Check el code ya nesr we lw try some testcases we lw tmam submit
//Da full solution

const int N = 1e5 + 5;
char str[N];
int bfr[N], aftr[N];
int n;
vector<int> pos;

bool valid(int x) {
	int problem = 0;
	int canRemove = 0;
	if (bfr[pos[0]] > x)
		problem++;
	if (aftr[pos.back()] > x)
		problem++;
	if (bfr[pos[0]] + aftr[pos[0]] + 1 <= x)
		canRemove++;
	if (bfr[pos.back()] + aftr[pos.back()] + 1 <= x)
		canRemove++;

	for (int p = 0; p < pos.size() - 1; p++) {
		int i = pos[p];
		int dis = bfr[i] + aftr[i] + 1;
		if (p && dis <= x * 2)
			canRemove++;
		if (aftr[i] > 2 * x)
			problem++;
		if (problem > 1)
			return 0;
	}

	if (problem > 1)
		return 0;
	if (problem == 0)
		return 1;

	if (bfr[pos[0]] > x) {
		if (bfr[pos[0]] > 3 * x + 1)
			return 0;
		if (canRemove)
			return 1;
		return bfr[pos[0]] + aftr[pos[0]] + 1 <= 3 * x + 1;
	}

	if (aftr[pos.back()] > x) {
		if (aftr[pos.back()] > 3 * x + 1)
			return 0;
		if (canRemove)
			return 1;
		return bfr[pos.back()] + aftr[pos.back()] + 1 <= 3 * x + 1;
	}



	for (int p = 0; p < pos.size() - 1; p++) {
		int i = pos[p];
		if (aftr[i] > 2 * x) {
            if (aftr[i] <= 4 * x + 1 && canRemove)
				return 1;
            int dis = aftr[i] + bfr[i] + 1;
			if (p && dis <= 4 * x + 1)
				return 1;
            if (dis <= 3 * x + 1)
				return 1;
            i = pos[p + 1];
			dis = aftr[i] + bfr[i] + 1;
			if (p+1 != pos.size()-1 && dis <= 4 * x + 1)
				return 1;
            if(dis <= 3 * x + 1)
                return 1;
			return 0;
		}
	}

	assert(0);
}

int bs(int s, int e) {
	while (s < e) {
		int mid = s + (e - s) / 2;
		if (valid(mid))
			e = mid;
		else
			s = mid + 1;
	}
	return s;
}

int f(int x, int y) {
	if (x > y)
		swap(x, y);
	int ans = max(x, n - y - 1);
	return max(ans, abs(y - x) / 2);
}

int solve() {
	int ret = INT_MAX;
	for (int i = 0; i < n; i++) {
		ret = min(ret, f(i, pos[1]));
		ret = min(ret, f(i, pos[0]));
	}
	return ret;
}

int main() {
    freopen("stations.in", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%s", &n, str);
		pos.clear();
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (str[i] == '+') {
				bfr[i] = cnt;
				pos.push_back(i);
				cnt = 0;
			} else {
				cnt++;
			}
		}

		cnt = 0;
		for (int i = n - 1; ~i; i--) {
			if (str[i] == '+') {
				aftr[i] = cnt;
				cnt = 0;
			} else {
				cnt++;
			}
		}

		if (pos.size() == 2) {
			printf("%d\n", solve());
		} else if (pos.size() == n) {
			printf("0\n");
		} else if (pos.size() == 1) {
			printf("%d\n", n / 2);
		} else {
			printf("%d\n", bs(0, n - 1));
		}

	}
	return 0;
}
