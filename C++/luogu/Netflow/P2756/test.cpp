#include<bits/stdc++.h>
using namespace std;

#define maxn 250
#define INF 0x3f3f3f3f

struct Edge {
  int from, to, cap, flow;
  Edge(int u, int v, int c, int f) : from(u), to(v), cap(c), flow(f) {}
};

struct Dinic {
  int n, m, s, t;
  vector<Edge> edges;
  vector<int> G[maxn];
  int d[maxn], cur[maxn];
  bool vis[maxn];

  void init(int n) {
    for (int i = 0; i < n; i++) G[i].clear();
    edges.clear();
  }

    void AddEdge(int from, int to, int cap) {
    edges.push_back(Edge(from, to, cap, 0));
    edges.push_back(Edge(to, from, 0, 0));
    m = edges.size();
    G[from].push_back(m - 2);
    G[to].push_back(m - 1);
  }

  bool BFS() {
    memset(vis, 0, sizeof(vis));
    queue<int> Q;
    Q.push(s);
    d[s] = 0;
    vis[s] = 1;
    while (!Q.empty()) {
      int x = Q.front();
      Q.pop();
      for (int i = 0; i < G[x].size(); i++) {
        Edge& e = edges[G[x][i]];
        if (!vis[e.to] && e.cap > e.flow) {
          vis[e.to] = 1;
          d[e.to] = d[x] + 1;
          Q.push(e.to);
        }
      }
    }
    return vis[t];
  }

  int DFS(int x, int a) {
    if (x == t || a == 0) return a;
    int flow = 0, f;
    for (int& i = cur[x]; i < G[x].size(); i++) {
      Edge& e = edges[G[x][i]];
      if (d[x] + 1 == d[e.to] && (f = DFS(e.to, min(a, e.cap - e.flow))) > 0) {
        e.flow += f;
        edges[G[x][i] ^ 1].flow -= f;
        flow += f;
        a -= f;
        if (a == 0) break;
      }
    }
    return flow;
  }

  int Maxflow(int s, int t) {
    this->s = s;
    this->t = t;
    int flow = 0;
    while (BFS()) {
      memset(cur, 0, sizeof(cur));
      flow += DFS(s, INF);
    }
    return flow;
  }
};
int m, n;
int u, v;
int main(){
    cin >> m >> n;
    Dinic D;
    D.init(n + 5);
    int S = n + 1, T = n + 2;
    while(1){
        cin >> u >> v;
        if (u == -1 || v == -1)
            break;
        D.AddEdge(u, v, 1);
    }
    for (int i = 1; i <= m; ++i)
        D.AddEdge(S, i, 1);
    for (int i = m + 1; i <= n; ++i)
        D.AddEdge(i, T, 1);

    int flow = D.Maxflow(S, T);
    printf("%d\n", flow);
    for (auto it = D.edges.begin(); it != D.edges.end(); ++it){
        int from = it->from, to = it->to, Flow = it->flow, cap = it->cap;
        if (Flow == 1 && from != S && to != T)
            // printf("%d to %d flow: %d (cap: %d)\n", from, to, Flow, cap);
            printf("%d %d\n", from, to);
    }
}