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
const ll MOD = 998244353;
const ll INF = 1e9;
const double EPS = 1e-5;
#define mp make_pair
#define all(x) x.begin(),x.end()

struct Pt {
	string name = "";
	int x, y;

	bool operator == (Pt other) const {
		return x == other.x && y == other.y;
	}
};

Pt goat;
string dir;

void moveGoat() {
	if (dir == "LEFT") goat.x--;
	else if (dir == "RIGHT") goat.x++;
	else if (dir == "UP") goat.y++;
	else goat.y--;
}

inline void moveX(Pt& s) {
	if (s.x < goat.x)
		s.x += min(2, goat.x - s.x);
	else
		s.x -= min(2, s.x - goat.x);
}

inline void moveY(Pt& s) {
	if (s.y < goat.y)
		s.y += min(2, goat.y - s.y);
	else
		s.y -= min(2, s.y - goat.y);
}

bool moveShep(Pt& s) {
	//if (abs(s.x - goat.x) > abs(s.y - goat.y)) {
	//	moveX(s);
	//}
	//else if (abs(s.x - goat.x) < abs(s.y - goat.y)) {
	//	moveY(s);
	//}
	//else if (s.x < goat.x && dir == "LEFT" || s.x > goat.x && dir == "RIGHT") {
	//	moveY(s);
	//}
	//else if (s.y < goat.y && dir == "DOWN" || s.y > goat.y && dir == "UP") {
	//	moveX(s);
	//}

	if (dir == "LEFT") {

	}

	return s == goat;
}

int dist(Pt s) {
	return ceil(abs(s.x - goat.x) / 2.0) + ceil(abs(s.y - goat.y) / 2.0);
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> goat.x >> goat.y;
	cin >> dir;

	int n; cin >> n;
	vector<Pt> s(n);
	for (int i = 0; i < n; i++)
		cin >> s[i].name >> s[i].x >> s[i].y;

	bool done = false;
	string winner = "";
	int gd = 0;
	while (!done) {
		moveGoat(); gd++;
		for (int i = 0; i < n; i++)
			if (dist(s[i]) <= gd) {
				done = true;
				winner = s[i].name;
				break;
			}
	}
	cout << winner << endl;
	cin.ignore(), cin.get();
}
