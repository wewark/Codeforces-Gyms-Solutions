// 100971 - 2016, IX Samara Regional Intercollegiate Programming Contest
// 100971A

#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
typedef vector<unsigned long long> vi;
typedef vector<vi> vvi;
typedef pair<unsigned long long, unsigned long long> pii;
typedef vector<pii> vii;
typedef vector<bool> vb;
typedef vector<string> vs;
string s[55];
vector <pair<int,int> >adj [55][55];
int vis[55][55];

void bfs(pair<int,int> p,int c)
{
	vis[p.first][p.second]=c;
	queue<pair<int,int> >q;
	q.push(p);
	while(!q.empty())
	{
		pair<int ,int >x;
		x=q.front();
		q.pop();
		for(int i=0;i<adj[x.first][x.second].size();i++)
		{
			if(vis[adj[x.first][x.second][i].first][adj[x.first][x.second][i].second]!=c)
			{
				q.push(make_pair(adj[x.first][x.second][i].first,adj[x.first][x.second][i].second));
				vis[adj[x.first][x.second][i].first][adj[x.first][x.second][i].second]=c;
			}

		}
	}
}
int main() {
	ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int n,m,c=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	s[0]=s[1];
	s[n+1]=s[1];
	for(int i=0;i<=n+1;i++)
	{
		s[i]='#'+s[i];
		s[i]+='#';

	}
	for(int i=1;i<=m;i++)
	{
		s[0][i]='#';
		s[n+1][i]='#';
	}
	vector<pair<int,int> > land,v,a;
	int x[]={0,1,-1,0};
	int y[]={1,0,0,-1};
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(s[i][j]=='.'||s[i][j]=='?')
			{
				for(int k=0;k<4;k++)
				{
					if(s[i+x[k]][j+y[k]]=='.'||s[i+x[k]][j+y[k]]=='?')
					{
						adj[i][j].push_back(make_pair(i+x[k],j+y[k]));
					}
				}
			}
			if(s[i][j]=='?')
			{
				v.push_back(make_pair(i,j));
			}
			if(s[i][j]=='.')
			{
				a.push_back(make_pair(i,j));
			}
		}
	}
	bfs(a[0],1);
	for(int i=0;i<a.size();i++)
	{
		if(vis[a[i].first][a[i].second]!=c)
		{
			cout<<"Impossible\n";
			return 0;
		}
	}
	for(int i=0;i<v.size();i++)
	{
		if(vis[v[i].first][v[i].second]!=c)
		{
			s[v[i].first][v[i].second]='#';
		}
	}
	v.clear();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			adj[i][j].clear();
			if(s[i][j]=='?')
			{
				v.push_back(make_pair(i,j));
				land.push_back(make_pair(i,j));
			}
			if(s[i][j]=='.')
			{
				land.push_back(make_pair(i,j));
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(s[i][j]=='.'||s[i][j]=='?')
			{
				for(int k=0;k<4;k++)
				{
					if(s[i+x[k]][j+y[k]]=='.'||s[i+x[k]][j+y[k]]=='?')
					{
						adj[i][j].push_back(make_pair(i+x[k],j+y[k]));
					}
				}
			}
		}
	}
	bool b=false;
	for(int i=0;i<v.size();i++)
	{
		b=false;
		c++;
		adj[v[i].first][v[i].second].clear();
		for(int j=0;j<4;j++)
		{
			for(int k=0;k<adj[v[i].first+x[j]][v[i].second+y[j]].size();j++)
			{
				if(adj[v[i].first+x[j]][v[i].second+y[j]][k]==v[i])
				{
					adj[v[i].first+x[j]][v[i].second+y[j]].erase(adj[v[i].first+x[j]][v[i].second+y[j]].begin()+k);
					k--;
					break;
				}
			}
		}
		bfs(a[0],c);

		for(int j=0;j<land.size();j++)
		{
			if(land[j]!=v[i])
			{
				if(vis[land[j].first][land[j].second]!=c)
				{
					b=true;
					break;
				}
			}
		}
		if(!b)
		{
			cout<<"Ambiguous\n";
			return 0;
		}
		for(int j=0;j<4;j++)
		{
			if(s[v[i].first+x[j]][v[i].second+y[j]]=='.'||s[v[i].first+x[j]][v[i].second+y[j]]=='?')
			{
				adj[v[i].first+x[j]][v[i].second+y[j]].push_back(make_pair(v[i].first,v[i].second));
				adj[v[i].first][v[i].second].push_back(make_pair(v[i].first+x[j],v[i].second+y[j]));
			}
		}

	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(s[i][j]=='?')
			{
				cout<<'.';
			}
			else
			{
				cout<<s[i][j];
			}
		}
		cout<<endl;
	}
}
