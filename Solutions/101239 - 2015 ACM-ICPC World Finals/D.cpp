// 101239 - 2015 ACM-ICPC World Finals
// 101239D

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<ll, ll> pii;
typedef vector<pii> vii;
typedef vector<bool> vb;
typedef vector<string> vs;
const int di[] = { -1, 0, 1, 0, -1, 1, 1, -1 };
const int dj[] = { 0, 1, 0, -1, -1, 1, -1, 1 };
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const long double EPS = 1e-10;
#define all(n) n.begin(),n.end()

typedef long double ld;
const ld PI = 3.14159265359;

struct Hole {
	ld x, y, z, r;
};

// https://en.wikipedia.org/wiki/Spherical_cap
inline ld capVolume(ld h, ld r) {
	return PI * h * h / 3.0 * (3 * r - h);
}

inline ld sphereVolume(ld r) {
	return PI * r * r * r * 4 / 3.0;
}

int n, s;
ld totalWeight = 1e15;
vector<Hole> hole;

ld weight(ld a, ld b) {
	ld ret = 1e10 * (b - a);
	for (auto& i : hole) {
		if (abs(i.z - a) <= i.r && abs(i.z - b) <= i.r) {
			ret -= sphereVolume(i.r)
				- capVolume(i.r + a - i.z, i.r)
				- capVolume(i.r + i.z - b, i.r);
		}
		else if (abs(i.z - a) <= i.r) {
			ret -= capVolume(i.r + i.z - a, i.r);
		}
		else if (abs(i.z - b) <= i.r) {
			ret -= capVolume(i.r + b - i.z, i.r);
		}
		else if (i.z > a && i.z < b) {
			ret -= sphereVolume(i.r);
		}
	}
	return ret;
}

ld bs(ld start) {
	ld sliceWeight = totalWeight / (ld)s;
	ld a = start, b = 1e5, mid = (a + b) / 2.0;
	while (b - a > EPS) {
		if (weight(start, mid) >= sliceWeight)
			b = mid;
		else
			a = mid;
		mid = (a + b) / 2.0;
	}
	return mid;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> s;
	hole.resize(n);
	for (auto& i : hole) {
		cin >> i.r >> i.x >> i.y >> i.z;
		totalWeight -= sphereVolume(i.r);
	}

	ld start = 0;
	cout << fixed << setprecision(10);
	for (int i = 0; i < s; i++) {
		ld cut = bs(start);
		cout << (cut - start) / 1000.0 << endl;
		start = cut;
	}
	cin.ignore(), cin.get();
}
