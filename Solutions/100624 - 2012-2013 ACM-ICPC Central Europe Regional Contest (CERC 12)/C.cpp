// 2012-2013 ACM-ICPC Central Europe Regional Contest (CERC 12)
// 100624C

#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<bool> vb;
typedef vector<string> vs;
const ll MOD = 1e9 + 7;
const long double EPS = 1e-5;
#define all(x) x.begin(),x.end()
#define SZ(x) (int)(x).size()

#include <ext/hash_set>
#include <ext/numeric>

#define  fr first
#define  sc second

vs pr;

string strLower(string s) {
	for (int i = 0; i < s.length(); ++i) {
		s[i] = tolower(s[i]);
	}
	return s;
}

void init() {
	stringstream ss;
	ss << "H He ";
	ss << "Li Be B C N O F Ne ";
	ss << "Na Mg Al Si P S Cl Ar ";
	ss << "K Ca Sc Ti V Cr Mn Fe Co Ni Cu Zn Ga Ge As Se Br Kr ";
	ss << "Rb Sr Y Zr Nb Mo Tc Ru Rh Pd Ag Cd In Sn Sb Te I Xe ";
	ss << "Cs Ba Hf Ta W Re Os Ir Pt Au Hg Tl Pb Bi Po At Rn ";
	ss << "Fr Ra Rf Db Sg Bh Hs Mt Ds Rg Cn Fl Lv ";
	ss << "La Ce Pr Nd Pm Sm Eu Gd Tb Dy Ho Er Tm Yb Lu ";
	ss << "Ac Th Pa U Np Pu Am Cm Bk Cf Es Fm Md No Lr";
	string s;
	while (ss >> s)
		pr.push_back(strLower(s));
}

string s;

vi vis(5e4 + 4); int vf = 0;
vb mem(5e4 + 4, false);
bool solve(int idx) {
	if (idx == s.length()) return true;
	if (vis[idx] == vf) return mem[idx];
	vis[idx] = vf;

	bool ret = false;
	for (int i = 0; i < pr.size(); ++i) {
		if (idx + pr[i].length() - 1 <= s.length()) {
			bool good = true;
			for (int j = 0; j < pr[i].length(); ++j) {
				if (pr[i][j] != s[idx + j]) {
					good = false;
					break;
				}
			}

			if (good)
				ret = (ret || solve(idx + pr[i].length()));
			if (ret)
				return mem[idx] = ret;
		}
	}
	return mem[idx] = ret;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	init();
	int t; cin >> t;
	while (t--) {
		vf++;
		cin >> s;
		cout << (solve(0) ? "YES" : "NO") << endl;
	}
	return 0;
}
