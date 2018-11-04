// 2013-2014 CT S01E05 2007 Nordic Collegiate Programming Contest (NCPC 2007)  Selected Problems from 2009 Google Code Jam World Finals (GCJ WF 2009)
// 100240G

//#include <bits/stdc++.h>
//typedef long long ll;
//typedef unsigned long long ull;
//#define MOD 1000000009
//#define PI 3.1415926535897932384626433832795
//#define oo 1e9
//#define pb push_back
//
//using namespace std;
//
//const int N = 100005;
//
//pair<int, int> a[N];
//bool done[N];
//
//int main() {
//    ios::sync_with_stdio(false), cin.tie(0);
////  freopen("input.txt", "r", stdin);
////  freopen("output.txt", "w", stdout);
//    int t;
//    cin>>t;
//    while(t--){
//    	int n;
//    	memset(done, 0, sizeof done);
//    	cin >> n;
//    	for (int i = 0; i < n; ++i) {
//    		cin >> a[i].first >> a[i].second;
//    	}
//    	sort(a, a + n);
//    	reverse(a, a + n);
//    	for (int i = 0; i < n; ++i) {
//    		if (done[i]) {
//    			continue;
//    		}
//    		for (int j = i + 1; j < n; ++j) {
//				if (!done[j] && a[i].first > a[j].first &&
//						a[i].second > a[j].second) {
//					a[i] = a[j];
//					done[j] = 1;
//				}
//    		}
//    	}
//    	int res = 0;
//    	for (int i = 0; i < n; ++i) {
//    		res += !done[i];
//    	}
//    	cout << res << endl;
//    }
//
//    // 1 2 3 4 5 6 7 8
//
//    return 0;
//}

#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define MOD 1000000009
#define PI 3.1415926535897932384626433832795
#define oo 1e9
#define pb push_back

using namespace std;

const int N = 200005;

pair<int, int> a[N];
int n;

vector<int> adj[N];

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
    int t;
    cin>>t;
    while(t--){
    	cin >> n;
    	set<int>st;
    	for(int i=0 ; i<N ; i++){
    		adj[i].clear();
    	}
    	for (int i = 0; i < n; ++i) {
    		cin >> a[i].first >> a[i].second;
    		adj[a[i].first].pb(a[i].second);
    		st.insert(-a[i].first);
    	}
    	multiset<int>mst;
//    	sort(a,a+n);
//    	reverse(a,a+n);
    	int cnt=0;
    	for(auto u : st){
    		for(auto u1 : adj[-u]){
    			auto it=mst.upper_bound(u1);
    			if(it==mst.end()){
    				cnt++;
    			}
    			else{
    				mst.erase(it);
    				//mst.insert(u1);
    			}
    		}
    		for(auto u1 : adj[-u]){
    			mst.insert(u1);
    		}
    	}
    	cout << cnt << endl;
    }

    // 1 2 3 4 5 6 7 8

    return 0;
}