// 2015-2016 ACM-ICPC Nordic Collegiate Programming Contest (NCPC 2015)
// 100781E

#include <bits/stdc++.h>

#define fr first
#define sc second

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<ll, ll> pii;
const int MOD = 1e9 + 7;

const int N = 1e5 + 5;
pair<int, int> arr[N];
int n, k;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
#endif
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	sort(arr, arr + n);

	multiset<int> st;
	int ans = 0;
	for (int i = 0; i < k; ++i) {
		st.insert(arr[i].second);
		ans++;
	}

	for (int i = k; i < n; ++i) {
		if (arr[i].first >= *st.begin()) {
			st.erase(st.begin());
			ans++;
			st.insert(arr[i].second);
		}
		else {
			st.insert(arr[i].second);
			st.erase(prev(st.end()));
		}
	}

	cout << ans << "\n";
}
