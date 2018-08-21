// 100609 - 2011-2012 ACM-ICPC, NEERC, Northern Subregional Contest
// 100609F

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

#define LSOne(S) (S & (-S))


int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	freopen("flat.in", "r", stdin);
	freopen("flat.out", "w", stdout);
	int n;
	ll c;
	cin>>n>>c;
	ll t=0,bed=0,bal=0;
	ll x;
	string s;
	for(int i=0;i<n;++i)
	{
		cin>>x>>s;
		t+=x;
		if(s=="bedroom")
		{
			bed+=x;
		}
		if(s=="balcony")
		{
			bal+=x;
		}
	}
	cout<<t<<endl;
	cout<<bed<<endl;
	double d=t-(bal/2.0);
	d*=c;
	cout<<fixed<<setprecision(6)<<d<<endl;
}