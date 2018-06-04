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
const long double EPS = 1e-10;
#define all(x) x.begin(),x.end()

ll n, k, sum = 0;
vll A;

bool bs(ll res) {
	ll mid = k / (n - 1 + A.back());
	k %= n - 1 + A.back();
	res += mid * (sum - A.back() - (n - 1));
	if (k < n - 1) {
		if (mid == 0) return false;
		k += n - 1 + A.back();
		res -= (sum - A.back() - (n - 1));
	}

	if (res + sum - A.back() >= k)
		return true;
	return false;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	cin >> n >> k;
	A.resize(n);
	int mx = 0, mxi = -1;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
		sum += A[i];
		if (A[i] > mx)
			mx = A[i], mxi = i;
	}

	ll bef = 0;
	for (int i = 0; i < mxi; i++) {
		bef += A[i];
	}
	if (k < mxi) {
		cout << "KEK\n"; return 0;
	}
	if (bef >= k) {
		cout << "YES\n"; return 0;
	}

	A.insert(A.end(), A.begin(), A.begin() + mxi + 1);
	A.erase(A.begin(), A.begin() + mxi + 1);

	k -= mxi + A.back();
	if (k <= 0) {
		cout << "KEK\n"; return 0;
	}

	cout << (bs(bef - mxi) ? "YES" : "KEK") << endl;

	cin.ignore(), cin.get();
}
