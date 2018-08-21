// 100609 - 2011-2012 ACM-ICPC, NEERC, Northern Subregional Contest
// 100609B

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

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	freopen("black.in", "r", stdin);
	freopen("black.out", "w", stdout);
	int n,m,s,k;
	cin>>n>>m>>s>>k;
	string str;
	cin>>str;
	vector<int> vec;
	int c=0;
	for(int i=0;i<m;++i){
		if(str[i]=='.'){
			if(c) vec.push_back(c);
			c=0;
		}
		else ++c;
	}
	if(c) vec.push_back(c);
	if(vec.size()==0){
		c=0;
		int p=k-1;
		if(p>=s){
			c+=(p-s+1)*(m-s+1);
		}
		p=n-k;
		if(p>=s){
			c+=(p-s+1)*(m-s+1);
		}
		if(c==0) cout<<"Impossible";
		else if(c==1) cout<<"Unique";
		else cout<<"Ambiguous";
	}
	else if(vec.size()==1){
		c=0;
		if(vec[0]==s){
			for(int i=1;i<=s;i++){
				int u=i-1,d=s-i;
				if(u<=k-1 && d<=n-k) c++;
			}
			if(c==0) cout<<"Impossible";
			else if(c==1) cout<<"Unique";
			else cout<<"Ambiguous";
		}
		else cout<<"Impossible";
	}
	else{
		cout<<"Impossible";
	}
}