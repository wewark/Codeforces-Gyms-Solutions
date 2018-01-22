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
#define mp make_pair
#define all(x) x.begin(),x.end()

vb isprime(2e7 + 100, true);
void sieve(int n) {
	for (ll i = 2; i <= n; i++)
		if (isprime[i])
			for (ll j = i * i; j <= n; j += i)
				isprime[j] = false;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	int n; cin >> n;
	sieve(n + 100);
	int r = 0;
	for (int i = 2; i <= n; i++) {
		if (isprime[i] && n % i == 0) {
			r++;
			n /= i;
		}
	}
	cout << (r == 3 ? "YES\n" : "NO\n");
	//cin.ignore(), cin.get();
}
