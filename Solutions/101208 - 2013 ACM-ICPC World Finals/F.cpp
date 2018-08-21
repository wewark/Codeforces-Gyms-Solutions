// 101208 - 2013 ACM-ICPC World Finals
// 101208F

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
const int N = 1e6 + 7;
const ll MOD = 1e9 + 7;
const ll INF = 1e8;
const long double EPS = 1e-10;
#define mp make_pair
#define all(x) x.begin(),x.end()

int arr[N];
int sz, n, k;
bool valid(int mid) {
	int rem = 2 * k - 2;
	int chips = n - 1;
	for (int i = 2; i < sz - 1 && chips; i++) {
		if (arr[i + 1] - arr[i] <= mid) {
			rem += 2 * k - 2;
			i++, --chips;
		}
		else {
			if (!rem)
				return false;
			--rem;
		}
	}
	return  chips == 0;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	cin >> n >> k;
	sz = 2 * n * k;
	for (int i = 0; i < sz; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + sz);

	int s = arr[1] - arr[0], e = 1e9 + 1, ans = -1;
	while (s <= e) {
		int mid = (s + e) / 2;
		if (valid(mid)) {
			e = mid - 1;
			ans = mid;
		}
		else
			s = mid + 1;
	}
	cout << ans;
}
