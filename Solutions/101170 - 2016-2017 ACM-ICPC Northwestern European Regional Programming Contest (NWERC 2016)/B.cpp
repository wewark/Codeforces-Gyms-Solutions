// 101170 - 2016-2017 ACM-ICPC Northwestern European Regional Programming Contest (NWERC 2016)
// 101170B

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<ll, ll> pii;
typedef vector<pii> vii;
typedef vector<bool> vb;
typedef vector<string> vs;
const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, 1, 0, -1 };
const ll MOD = 5e6;
const ll INF = 1e8;
const double EPS = 1e-12;
#define mp make_pair
#define all(x) x.begin(),x.end()

int curComp = 0;
vi compof, sz;
vvi comp;

class Graph
{
	int V;    // No. of vertices
	list<int> *adj;    // An array of adjacency lists

					   // Fills Stack with vertices (in increasing order of finishing
					   // times). The top element of stack has the maximum finishing
					   // time
	void fillOrder(int v, bool visited[], stack<int> &Stack);

	// A recursive function to print DFS starting from v
	void DFSUtil(int v, bool visited[]);
public:
	Graph(int V);
	void addEdge(int v, int w);

	// The main function that finds and prints strongly connected
	// components
	void printSCCs();

	// Function that returns reverse (or transpose) of this graph
	Graph getTranspose();
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

// A recursive function to print DFS starting from v
void Graph::DFSUtil(int v, bool visited[])
{
	// Mark the current node as visited and print it
	visited[v] = true;
	//cout << v << " ";
	comp[curComp].push_back(v);
	compof[v] = curComp;
	sz.back()++;

	// Recur for all the vertices adjacent to this vertex
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			DFSUtil(*i, visited);
}

Graph Graph::getTranspose()
{
	Graph g(V);
	for (int v = 0; v < V; v++)
	{
		// Recur for all the vertices adjacent to this vertex
		list<int>::iterator i;
		for (i = adj[v].begin(); i != adj[v].end(); ++i)
		{
			g.adj[*i].push_back(v);
		}
	}
	return g;
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); // Add w to v’s list.
}

void Graph::fillOrder(int v, bool visited[], stack<int> &Stack)
{
	// Mark the current node as visited and print it
	visited[v] = true;

	// Recur for all the vertices adjacent to this vertex
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			fillOrder(*i, visited, Stack);

	// All vertices reachable from v are processed by now, push v
	Stack.push(v);
}

// The main function that finds and prints all strongly connected
// components
void Graph::printSCCs()
{
	stack<int> Stack;

	// Mark all the vertices as not visited (For first DFS)
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	// Fill vertices in stack according to their finishing times
	for (int i = 0; i < V; i++)
		if (visited[i] == false)
			fillOrder(i, visited, Stack);

	// Create a reversed graph
	Graph gr = getTranspose();

	// Mark all the vertices as not visited (For second DFS)
	for (int i = 0; i < V; i++)
		visited[i] = false;

	// Now process all vertices in order defined by Stack
	while (Stack.empty() == false)
	{
		// Pop a vertex from stack
		int v = Stack.top();
		Stack.pop();

		// Print Strongly connected component of the popped vertex
		if (visited[v] == false)
		{
			comp.push_back({});
			sz.push_back(0);
			gr.DFSUtil(v, visited);
			//cout << endl;
			curComp++;
		}
	}
}

struct CompEdge {
	int vComp, u, v;
};

int n, m;
vvi adj;
vector<vector<CompEdge>> adjComp;
map<pii, int> dist;

void buildAdjComp() {
	adjComp.assign(curComp, vector<CompEdge>());
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < adj[i].size(); j++) {
			if (compof[i] != compof[adj[i][j]]) {
				adjComp[compof[i]].push_back({ compof[adj[i][j]], i, adj[i][j] });
			}
		}
	}
}

vi vis; int vf = 0;
void dfs(int node, int start, int d) {
	if (vis[node] == vf) return;
	vis[node] = vf;
	dist[{start, node}] = max(dist[{start, node}], d);
	for (int i = 0; i < adj[node].size(); i++) {
		if (compof[adj[node][i]] == compof[node])
			dfs(adj[node][i], start, d + 1);
	}
	vis[node] = 0;
}

void buildCompDist() {
	vis.assign(n, 0);
	for (int i = 0; i < comp.size(); i++) {
		for (int j = 0; j < comp[i].size(); j++) {
			vf++;
			dfs(comp[i][j], comp[i][j], 0);
		}
	}
}

vi mem(1e5 + 5, -1);
int solve(int node) {
	int& ret = mem[node];
	if (ret != -1) return ret;
	ret = 0;
	for (auto& i : comp[compof[node]])
		ret = max(ret, dist[{node, i}]);

	for (auto& i : adjComp[compof[node]]) {
		ret = max(ret, solve(i.v) + dist[{node, i.u}] + 1);
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m;
	adj.assign(n, vi());
	Graph g(n);
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v; u--, v--;
		adj[u].push_back(v);
		g.addEdge(u, v);
	}
	compof.assign(n, -1);
	g.printSCCs();
	buildAdjComp();
	buildCompDist();

	int r = 0;
	for (int i = 0; i < n; i++)
		r = max(r, solve(i));
	cout << r + 1 << endl;
	cin.ignore(), cin.get();
}
