// 100609 - 2011-2012 ACM-ICPC, NEERC, Northern Subregional Contest
// 100609D

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

vector<int> ans[1003];

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	freopen("dice.in","rt",stdin);
	freopen("dice.out","w",stdout);
	int n;
	cin>>n;
	vector<pair<int,int> > vec;
	int x;
	int c=0;
	for(int i=0;i<n;i++){
		cin>>x;
		vec.push_back(make_pair(x,i));
		c+=x;
	}
	sort(vec.begin(),vec.end());
	double ex=0;

	for(auto d:vec){
		double p=1.0/d.first;
		x=d.first;
		while(x--){
			ex+=p*c;
			ans[d.second].push_back(c--);
		}
	}
	cout<<fixed<<setprecision(5)<<ex<<"\n";
	for(int i=0;i<n;i++){
		for(auto v:ans[i]) cout<<v<<" ";
		cout<<"\n";
	}
}