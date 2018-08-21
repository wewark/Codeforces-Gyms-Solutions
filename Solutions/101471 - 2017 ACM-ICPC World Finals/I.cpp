// 101471 - 2017 ACM-ICPC World Finals
// 101471I

#include <bits/stdc++.h>
#define fs first
#define sc second
#define pb push_back

using namespace std;

typedef long long ll;
const int N=300, mod=60;
const double PI = 3.141592653589793238462643383279502884197, eps=1e-6;

vector<int> g[N];
bool vis[N];

bool check(int x, int y)
{
	if(x==y)
		return 1;

	bool ans=0;

	vis[x]=1;

	for(unsigned int i=0 ; i<g[x].size() && !ans; i++)
		if(!vis[g[x][i]])
			ans |= check(g[x][i],y);

	return ans;
}

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n, m;
	char ch1, ch2;
	string s1, s2;
	bool f;

	cin >> m >> n;

	while(m--)
	{
		cin >> ch1 >> ch2;
		g[ch1].pb(ch2);
	}

	while(n--)
	{
		cin >> s1 >> s2;

		f=0;

		if(s1.size()==s2.size())
		{
			f=1;

			for(unsigned int i=0 ; i<s1.size() && f ; i++)
			{
				f=check(s1[i],s2[i]);
				memset(vis,0,sizeof vis);
			}
		}

		cout << (f ? "yes" : "no") << '\n';
	}

	return 0;
}
