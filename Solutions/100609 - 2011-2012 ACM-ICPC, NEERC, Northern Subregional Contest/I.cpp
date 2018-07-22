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
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};
const int N = 1e6 + 7;
const ll MOD = 1e9 + 7;
const ll INF = 1e8;
const long double EPS = 1e-10;
#define mp make_pair
#define all(x) x.begin(),x.end()

int n, m;
int arr[20][20];
vector<int> path[20][20];

void floyed() {
	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {

				int d = arr[i][k] + arr[k][j];
				if (d < arr[i][j]) {
					arr[i][j] = d;
					path[i][j].clear();
					path[i][j].insert(path[i][j].end(), path[i][k].begin(), path[i][k].end());
					path[i][j].push_back(k);
					path[i][j].insert(path[i][j].end(), path[k][j].begin(), path[k][j].end());
				}
			}
		}
	}
}

int memo[20][(1 << 20)];
int best[20][(1 << 20)];

int solve(int cur, int m) {
	if (m == 0) return 0;
	int &res = memo[cur][m];
	if (~res) return res;
	res = 1e9;

	for (int i = 0; i < n; i++) {
		if ((m >> i) & 1) {
			int x = arr[cur][i] + solve(i, m ^ (1 << i));
			if (x < res) best[cur][m] = i;
			res = min(res, x);
		}
	}
	return res;
}

void tobin(int v1, int v2) {
	for (int i = 0; i < n; i++) {
		cout << int((v1 >> i) & 1);
	}
	cout<<endl;
	for (int i = 0; i < n; i++) {
		cout << int((v2 >> i) & 1);
	}
	cout<<endl;
}

vi p;
void build(int cur, int m) {
	p.push_back(cur);
	if(m==0) return;
	int nx=best[cur][m];
	p.insert(p.end(),path[cur][nx].begin(),path[cur][nx].end());
	build(nx,m^(1<<nx));
}

int main() {
	//ios::sync_with_stdio(false), cin.tie(nullptr);
	freopen("immediate.in", "r", stdin);
	freopen("immediate.out", "w", stdout);

	cin >> n >> m;
	memset(arr, 0x3f3f3f3f, sizeof arr);
	memset(memo, -1, sizeof memo);
	int x, y, v;
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> v;
		--x;
		--y;
		arr[x][y] = arr[y][x] = v;
	}
	for (int i = 0; i < n; i++) arr[i][i] = 0;
	floyed();

	int mn = 1e9;
	int msk1, msk2;
	for (int m = 0; m < (1 << (n - 1)); m++) {
		//cout<<m<<endl;
		int v1 = m, v2 = (v1 ^ ((1 << (n - 1)) - 1));
		int v = max(solve(0, v1 << 1), solve(0, v2 << 1));
		//tobin(v1, v2);
		if (v < mn) {
//			cout<<v<<endl;
			//tobin(v1,v2);
			mn = v;
			msk1 = v1;
			msk2 = v2;
		}
	}
	//tobin(msk1, msk2);
	cout << mn << endl;
	p.clear();
	build(0,msk1<<1);
	cout<<p.size()-1<<" ";
	for(auto x:p) cout<<x+1<<" ";
	cout<<endl;
	p.clear();
	build(0,msk2<<1);
	cout<<p.size()-1<<" ";
	for(auto x:p) cout<<x+1<<" ";
}