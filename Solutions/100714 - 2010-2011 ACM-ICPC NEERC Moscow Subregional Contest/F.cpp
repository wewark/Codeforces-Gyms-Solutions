// 2010-2011 ACM-ICPC NEERC Moscow Subregional Contest
// 100714F

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
const int di[] = {0, 0, 1, -1};
const int dj[] = {1, -1, 0, 0};
const ll MOD = 1e9 + 7;
const long double EPS = 1e-3;
#define all(x) x.begin(),x.end()

#include <ext/hash_set>
#include <ext/numeric>

vi num(8);
int mx = 0;
vi mxv;

void bt(int idx, int cur) {
	int ocur = cur;
	for (int i = idx == 4 ? 53 : num[idx - 1] + 1; i <= 104; ++i) {
		num[idx] = i;
		cur = ocur;
		int c = idx;
		while (c > 4 && num[c] == num[c - 1] + 1) c--;
		for (int j = 0; j < c; ++j)
			if (num[c] - num[j] <= 52)
				cur++;

		if (idx == 7) {
			if (cur > mx) {
				mx = cur;
				mxv = {num[4], num[5], num[6], num[7]};
			}
		}
		else bt(idx + 1, cur);
	}

}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	for (int i = 0; i < 4; ++i)
		cin >> num[i];

	bt(4, 0);
//	cout << mx << endl;
	for (int i = 0; i < 4; ++i) {
		cout << mxv[i] - 52 << " \n"[i == 7];
	}

}