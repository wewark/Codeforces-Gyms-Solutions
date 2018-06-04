#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
typedef vector<unsigned long long> vi;
typedef vector<vi> vvi;
typedef pair<unsigned long long, unsigned long long> pii;
typedef vector<pii> vii;
typedef vector<bool> vb;
typedef vector<string> vs;
long long a[200005],b[200005];
int main() {
	ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>b[i];
	}
	sort(a,a+n);
	sort(b,b+n);
	int c1=0,c2=0,j=0,k=0;
	for(int i=0;i<n;i++)
	{
		for(;j<n;j++)
		{
			if(a[j]>b[i])
			{
				c1++;
				j++;
				break;
			}
		}
		for(;k<n;k++)
		{
			if(b[k]>a[i])
			{
				c2++;
				k++;
				break;
			}
		}
	}
	//cout<<c1<<" "<<c2<<endl;
	if(c1>n-c1&&c2>n-c2)
	{
		cout<<"Both\n";
	}
	else if(c1>n-c1)
	{
		cout<<"First\n";
	}
	else if(c2>n-c2)
	{
		cout<<"Second\n";
	}
	else
	{
		cout<<"None\n";
	}
}
