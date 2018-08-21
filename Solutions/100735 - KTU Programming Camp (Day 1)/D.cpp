// 100735 - KTU Programming Camp (Day 1)
// 100735D

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

int n;
vi num;

vi mem((1 << 15) + 10, -1);
int count(int msk) {
	int& ret = mem[msk];
	if (ret != -1) return ret;
	ret = 0;

	for (int i = 0; i < n; i++) {
		if (!(msk & (1 << i))) for (int j = i + 1; j < n; j++) {
			if (!(msk & (1 << j))) for (int k = j + 1; k < n; k++) {
				if (!(msk & (1 << k))) {
					int arr[] = { num[i], num[j], num[k] };
					sort(arr, arr + 3);
					if (arr[2] < arr[1] + arr[0]) {
						int tmp = msk;
						tmp |= (1 << i);
						tmp |= (1 << j);
						tmp |= (1 << k);
						ret = max(ret, count(tmp) + 1);
					}
				}
			}
		}
	}

	return ret;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n;
	num.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	cout << count(0) << endl;
	cin.ignore(), cin.get();
}
