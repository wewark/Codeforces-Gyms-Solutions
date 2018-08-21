// 101466 - 2017 ACM-ICPC, Universidad Nacional de Colombia Programming Contest
// 101466C

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
#define all(pt) pt.begin(),pt.end()

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

struct Point {
	int x, y, z;
};

struct Slope {
	int x, y, z;
	Slope(Point a, Point b) {
		x = a.x - b.x;
		y = a.y - b.y;
		z = a.z - b.z;
		int g = gcd(gcd(x, y), z);
		x /= g, y /= g, z /= g;
	}

	bool operator < (Slope other) const {
		if (x != other.x)
			return x < other.x;
		if (y != other.y)
			return y < other.y;
		return z < other.z;
	}
};

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int n; cin >> n;
	Point e;
	cin >> e.x >> e.y >> e.z;

	set<Slope> st;
	for (int i = 1; i < n; i++) {
		Point cur;
		cin >> cur.x >> cur.y >> cur.z;
		st.insert(Slope(e, cur));
	}
	cout << st.size() << endl;
	cin.ignore(), cin.get();
}
