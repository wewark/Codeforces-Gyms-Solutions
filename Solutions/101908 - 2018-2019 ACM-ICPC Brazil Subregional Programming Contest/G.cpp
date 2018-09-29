// 2018-2019 ACM-ICPC Brazil Subregional Programming Contest
// 101908G

#include <bits/stdc++.h>
using namespace std;


const int N  = 2050;
const int M = 1e5;
int n,m;


int head[N], work[N], nxt[M], to[M], cap[M], dis[N], que[N];
int edge_cnt , src, snk , back , front , qsz;

void add_edge(int f, int t, int c) {
  nxt[edge_cnt] = head[f];
  head[f] = edge_cnt;
  to[edge_cnt] = t;
  cap[edge_cnt] = c;
  edge_cnt++;
}

void add_bi_edge(int f, int t, int c) {
  add_edge(f, t, c);
  add_edge(t, f, 0);
}

void init() {
    memset(head, -1, sizeof head);
    edge_cnt = 0;
}

bool bfs() {
    back = front = qsz = 0;
    memset(dis, -1, sizeof dis);
    dis[src] = 0;
    que[qsz++, back++] = src;
    while (qsz) {
        int cur = que[qsz--,front++];
        for (int i = head[cur]; ~i; i = nxt[i]){
                int t = to[i];
                if (!cap[i] || dis[t] != -1)continue;
                dis[t] = dis[cur] + 1;
                if (t == snk)return 1;
                que[qsz++, back++] = t;
        }
    }
    return 0;
}

int dfs(int u, int flow = 1e9 + 3) {
    if(!flow)return flow;
    if (u == snk)return flow;
    for (int &i = work[u]; i != -1; i = nxt[i]){
        int v = to[i];
        if (!cap[i] || dis[u] + 1 != dis[v])continue;
        int f = dfs(v, min(flow, cap[i]));
        if (f){
          cap[i] -= f;
          cap[i ^ 1] += f;
          return f;
        }
    }
    return 0;
}

long long  max_flow(){
    long long ret = 0, flow = 0;
    while (bfs()) {
        memcpy(work, head, sizeof head);
        while (flow = dfs(src))ret += flow;
  }
  return ret;
}

int gas[N] , supply[N];
pair<int,pair<int,int> > edges[M];
int sum = 0;
int p , r , c;

bool valid(int E){
    init();
    for(int i = 0 ; i < E ; i++){
        add_bi_edge(edges[i].second.first,edges[i].second.second,1e9);
    }

    for(int i = 1 ; i <= r ; i++){
        add_bi_edge(src,i,supply[i]);
    }

    for(int i = 1 ; i <= p ; i++){
        add_bi_edge(i+r,snk,gas[i+r]);
    }
    //cout << max_flow() << " " << sum << endl;
    return max_flow() == sum;
}


int bs(int s, int e){
    while (s < e){
        int mid = (s + (e - s) / 2);
        if (valid(mid))
            e = mid;
        else
            s = mid + 1;
    }

    return s;
}

int main(){

    scanf("%d%d%d",&p,&r,&c);
    for(int i = 1 ; i <= p ; i++){
        scanf("%d",&gas[r+i]);
        sum += gas[r+i];
    }

    for(int i = 1 ; i <= r ; i++){
        scanf("%d",&supply[i]);
    }

    src = 0;
    snk = r + p + 2;
    for(int i = 0 ; i < c ; i++){
        scanf("%d%d%d",&edges[i].second.second,&edges[i].second.first,&edges[i].first);
        edges[i].second.second += r;
        //cout << edges[i].second.first << "==>" << edges[i].second.second;
        //supply --> gas
    }

    sort(edges,edges+c);
    if(!valid(c)){
        puts("-1");
    }else{
        printf("%d\n",edges[bs(1,c)-1].first);
    }

    return 0;
}
