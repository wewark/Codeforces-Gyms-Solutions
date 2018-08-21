// 101471 - 2017 ACM-ICPC World Finals
// 101471F

#include <bits/stdc++.h>
#define fs first
#define sc second
#define pb push_back

using namespace std;

typedef long long ll;
const int N=101, mod=60;
const ll INF=1e18+7;
const double PI = 3.141592653589793238462643383279502884197, EPS=1e-9, two=2.0;

int d, k;
vector<pair<ll, ll>> rp;

inline ll error(ll col, ll idx) {
	return (rp[idx].fs - col) * (rp[idx].fs - col) * rp[idx].sc;
}

int BS(int c)
{
	int s=0, e=rp.size(), m, ans=rp.size();

	while(s<=e)
	{
		m =(s+e)/2;

		if(rp[m].fs>=c)
			ans=m, e=m-1;
		else
			s=m+1;
	}

	return ans;
}

ll cal (int c)
{
	int ind = BS(c);
	ll ans=0;

	while(ind<rp.size())
		ans += error(c,ind), ind++;

	return ans;
}

ll cal (int c1, int c2)
{
	int ind1 = BS(c1);
	int ind2 = BS(c2);

	ll ans=0;

	while(ind1<ind2)
		ans += min(error(c1,ind1),error(c2,ind1)), ind1++;

	return ans;
}

ll cal2 (int c)
{
	ll ans=0;

	for(int i=0 ; rp[i].fs<c ; i++)
		ans += error(c,i);

	return ans;
}

ll mem[261][261];
ll solve(int col, int kc) {
	if(kc==k) return cal(col);

	ll& ret = mem[col][kc];
	if (~ret) return ret;
	ret = INF;

	for(int i=col+1 ; i<256 ; i++)
		ret = min(ret,solve(i,kc+1)+cal(col,i));

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	ll ans=INF;
	memset(mem, -1, sizeof mem);
	cin >> d >> k;
	rp.resize(d);
	for (int i = 0; i < d; ++i)
		cin >> rp[i].fs >> rp[i].sc;

	for(int i=0 ; i<256 ; i++)
		ans = min(ans,solve(i,1)+cal2(i));

	cout << ans;

	return 0;
}
