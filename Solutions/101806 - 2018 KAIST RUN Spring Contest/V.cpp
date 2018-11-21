// 2018 KAIST RUN Spring Contest
// 101806V

#include <bits/stdc++.h>
#include <ext/hash_map>
#include <ext/numeric>

using namespace std;
using namespace __gnu_cxx;

#define REP(i,n) for( (i)=0 ; (i)<(n) ; (i)++ )
#define rep(i,x,n) for( (i)=(x) ; (i)<(n) ; (i)++ )
#define REV(i,n) for( (i)=(n) ; (i)>=0 ; (i)-- )
#define FORIT(it,x) for( (it)=(x).begin() ; (it)!=(x).end() ; (it)++ )
#define foreach(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define rforeach(it,c) for(__typeof((c).rbegin()) it=(c).rbegin();it!=(c).rend();++it)
#define foreach2d(i, j, v) foreach(i,v) foreach(j,*i)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define SZ(x) ((int)(x).size())
#define MMS(x,n) memset(x,n,sizeof(x))
#define mms(x,n,s) memset(x,n,sizeof(x)*s)
#define pb push_back
#define NX next_permutation
#define UN(x) sort(all(x)),x.erase(unique(all(x)),x.end())
#define CV(x,n) count(all(x),(n))
#define FIND(x,n) find(all(x),(n))-(x).begin()
#define ACC(x) accumulate(all(x),0)
#define PPC(x) __builtin_popcountll(x)
#define LZ(x) __builtin_clz(x)
#define TZ(x) __builtin_ctz(x)
#define mxe(x) *max_element(all(x))
#define mne(x) *min_element(all(x))
#define low(x,i) lower_bound(all(x),i)
#define upp(x,i) upper_bound(all(x),i)
#define NXPOW2(x) (1ll << ((int)log2(x)+1))
#define PR(x) cout << #x << " = " << (x) << endl ;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vector<int> > vvi;
typedef pair<ll, ll> pii;

const int OO = (int) 2e9;
const double eps = 1e-9;
const ll INF = 1e18;

typedef pair<ll, ll> pii;
typedef vector<pii> vii;

#define fr first
#define sc second

ll n, m, k;
vector<vii> adj;
vi st, prnt;

struct Edge {
	int u, v;
	ll w;
};
vector<Edge> edge;
vector<ll> dist;

void dijkstra() {
	dist.assign(n, INF);
	priority_queue<pair<ll, pii>, vector<pair<ll, pii>>, greater<pair<ll, pii>>> pq;

	for (int i = 0; i < k; ++i) {
		pq.push(pair<ll, pii>(0, { st[i], st[i] }));
		dist[st[i]] = 0;
	}

	while (!pq.empty()) {
		pair<ll, pii> front = pq.top();
		pq.pop();
		ll d = front.first, u = front.second.second;
		if (d > dist[u])
			continue;

		for (int i = 0; i < adj[u].size(); i++) {
			pii v = adj[u][i];
			if (dist[u] + v.second < dist[v.first] ||
					dist[u] + v.second == dist[v.first] &&
					prnt[v.first] > prnt[u]) {
				dist[v.first] = dist[u] + v.second;
				prnt[v.first] = prnt[u];
				pq.emplace(pair<ll, pii>(dist[v.first],
						{ prnt[v.first], v.first }));
			}
		}
	}
}

int main() {
//	std::ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("in.txt", "rt", stdin);
//	freopen("out.txt", "wt", stdout);
#endif

	cin >> n >> m;
	adj.assign(n, vii());
	for (int i = 0; i < m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		u--, v--;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
		edge.push_back(Edge { u, v, w });
	}

	cin >> k;
	st.resize(k);
	for (int i = 0; i < k; ++i) {
		cin >> st[i];
		st[i]--;
	}

	prnt.resize(n);
	for (int i = 0; i < n; ++i) {
		prnt[i] = i;
	}

	dijkstra();
	vector<double> score(n);
	for (int i = 0; i < edge.size(); ++i) {
		int u = edge[i].u;
		int v = edge[i].v;
		int w = edge[i].w;
		if (prnt[u] == prnt[v]) {
			score[prnt[u]] += w;
		} else {
			if (dist[u] > dist[v]) swap(u, v);
			ll diff = dist[v] - dist[u];
			u = prnt[u], v = prnt[v];

			if (diff == 0) {
				score[u] += w / 2.0;
				score[v] += w / 2.0;
			} else if (diff >= w)
				score[u] += w;
			else {
				score[u] += diff;
				w -= diff;
				score[u] += w / 2.0;
				score[v] += w / 2.0;
			}
		}
	}

	for (auto& i : st) {
		cout << fixed << setprecision(1) << score[i] << endl;
	}

}
