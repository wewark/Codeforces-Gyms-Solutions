// 101726 - 2013 USP Try-outs
// 101726B

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
const int di[] = { -1, 0, 1, 0, -1, 1, 1, -1 };
const int dj[] = { 0, 1, 0, -1, -1, 1, -1, 1 };
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const long double EPS = 1e-9;
#define all(x) x.begin(),x.end()

int N1, N2;
vi sum1, sum2;
vector<vector<double>> prob1, prob2;

vector<vector<vector<double>>> mem(305, vector<vector<double>>(305, vector<double>(2, -1)));
vector<vvi> vis(305, vvi(305, vi(2))); int vf = 0;
double solve(int v1, int v2, bool turn) {
	if (v1 <= 0) return 0;
	if (v2 <= 0) return 1;

	double& ret = mem[v1][v2][turn];
	if (vis[v1][v2][turn] == vf) return ret;
	vis[v1][v2][turn] = vf;
	ret = 0;

	if (turn) {
		for (int j = 0; j < sum1.size(); j++) {
			double x = 0;
			for (int i = 1; i <= sum1[j]; i++) {
				x += prob1[j][i] * solve(v1, v2 - i, false);
			}
			ret = max(ret, x);
		}
	}
	else {
		ret = 1;
		for (int j = 0; j < sum2.size(); j++) {
			double x = 0;
			for (int i = 1; i <= sum2[j]; i++) {
				x += prob2[j][i] * solve(v1 - i, v2, true);
			}
			ret = min(ret, x);
		}
	}
	return ret;
}

void init() {
	prob1.assign(N1, vector<double>(12 * 3 + 1));
	prob2.assign(N2, vector<double>(12 * 3 + 1));
	sum1.assign(N1, 0);
	sum2.assign(N2, 0);
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int va, vb; cin >> va >> vb >> N1 >> N2;

		init();

		for (int I = 0; I < N1; I++) {
			int x; cin >> x;
			vi v(x);
			for (int j = 0; j < v.size(); j++) {
				cin >> v[j];
				sum1[I] += v[j];
			}

			if (v.size() == 1) {
				for (int i = 1; i <= v[0]; i++) {
					prob1[I][i] += 1.0 / (double)v[0];
				}
			}
			else if (v.size() == 2) {
				for (int i = 1; i <= v[0]; i++) {
					for (int j = 1; j <= v[1]; j++) {
						prob1[I][i + j] += 1.0 / (double)(v[0] * v[1]);
					}
				}
			}
			else {
				for (int i = 1; i <= v[0]; i++) {
					for (int j = 1; j <= v[1]; j++) {
						for (int k = 1; k <= v[2]; k++) {
							prob1[I][i + j + k] += 1.0 / (double)(v[0] * v[1] * v[2]);
						}
					}
				}
			}
		}

		for (int I = 0; I < N2; I++) {
			int x; cin >> x;
			vi v(x);
			for (int j = 0; j < v.size(); j++) {
				cin >> v[j];
				sum2[I] += v[j];
			}

			if (v.size() == 1) {
				for (int i = 1; i <= v[0]; i++) {
					prob2[I][i] += 1.0 / (double)v[0];
				}
			}
			else if (v.size() == 2) {
				for (int i = 1; i <= v[0]; i++) {
					for (int j = 1; j <= v[1]; j++) {
						prob2[I][i + j] += 1.0 / (double)(v[0] * v[1]);
					}
				}
			}
			else {
				for (int i = 1; i <= v[0]; i++) {
					for (int j = 1; j <= v[1]; j++) {
						for (int k = 1; k <= v[2]; k++) {
							prob2[I][i + j + k] += 1.0 / (double)(v[0] * v[1] * v[2]);
						}
					}
				}
			}
		}

		vf++;
		cout << fixed << setprecision(10) << solve(va, vb, true) << endl;
	}
	cin.ignore(), cin.get();
}
