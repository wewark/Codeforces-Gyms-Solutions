// 2013-2014 CT S01E05 2007 Nordic Collegiate Programming Contest (NCPC 2007)  Selected Problems from 2009 Google Code Jam World Finals (GCJ WF 2009)
// 100240L

#include <bits/stdc++.h>
#include <ext/hash_set>
#include <ext/numeric>

using namespace std;
typedef long long ll;
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
#define SZ(x) (int)x.size()



int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	cin.ignore();
	string s , a;
	map<string,string> name;
	map<string,int> cnt;
	int mx = 0 , c = 1;
	for(int i = 0 ; i < n ; i++){
		getline(cin,s);
		getline(cin,a);
		name[s] = a;
	}

	int m;
	cin >> m;
	cin.ignore();
	for(int i = 0 ; i < m ; i++){
		getline(cin,s);
		if(name.find(s) == name.end())continue;
		int x = ++cnt[s];
		if(x > mx){
			mx = x;
			a = s;
			c = 0;
		}else if(x == mx){
			c++;
		}
	}

	if(c){
		cout << "tie" << endl;
	}else{
		cout << name[a] << endl;
	}

	return 0;
}