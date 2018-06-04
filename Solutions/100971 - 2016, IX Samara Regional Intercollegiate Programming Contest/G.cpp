#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
typedef vector<unsigned long long> vi;
typedef vector<vi> vvi;
typedef pair<unsigned long long, unsigned long long> pii;
typedef vector<pii> vii;
typedef vector<bool> vb;
typedef vector<string> vs;

int main() {
	ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	long long a,b,a1,b1,a2,b2;
	cin>>a>>b>>a1>>b1>>a2>>b2;
	if(((a1+a2)<=a&&max(b1,b2)<=b)||
    ((a1+a2)<=b&&max(b1,b2)<=a)||
    ((a1+b2)<=a&&max(b1,a2)<=b)||
    ((a1+b2)<=b&&max(b1,a2)<=a)||
			((b1+b2)<=a&&max(a1,a2)<=b)||((b1+b2)<=b&&max(a1,a2)<=a)||((b1+a2)<=a&&max(a1,b2)<=b)||((b1+a2)<=b&&max(a1,b2)<=a))
	{
		cout<<"YES\n";
	}
	else
	{
		cout<<"NO\n";
	}
}
