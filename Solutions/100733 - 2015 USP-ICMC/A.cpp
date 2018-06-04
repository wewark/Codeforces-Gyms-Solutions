#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<pair<int, int>, int> pii;
typedef vector<pii> vii;
typedef vector<bool> vb;
typedef vector<string> vs;
const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, 1, 0, -1 };
const ll MOD = 1e9 + 7;
const ll INF = 1e10;
const double EPS = 1e-5;
#define mp make_pair
#define all(x) x.begin(),x.end()

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	long double n, R, r; cin >> n >> R >> r;
	double ang = 360.0 / (2.0 * n);
	const double PI = 3.14159265359;
	double sa = R * r * sin(ang * 2.0 * PI / 360.0);
	cout << fixed << setprecision(10) << sa * n << endl;
	cin.ignore(), cin.get();
}
