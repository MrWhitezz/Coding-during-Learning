#include<bits/stdc++.h>
using namespace std;
int n, m, a, b, c, l, r, u, v, d;
#define maxn 10050+5
#define INF 0x3f3f3f3f
const int shift = 2e6;

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

int vt(int i, int x){
    return i * 201 + x + 100;
}
int main(){
    cin >> n >> m;
    vector<vector<int>> f(n);
    for (int i = 0; i < n; ++i){
        cin >> a >> b >> c;
        f[i].push_back(a); f[i].push_back(b); f[i].push_back(c);
    }
    vector<pair<int, int>> interval(n);
    for (int i = 0; i < n; ++i){
        cin >> l >> r;
        interval[i].first = l; interval[i].second = r;
    }
    vector<vector<int>> limit(m);
    for (int i = 0; i < m; ++i){
        cin >> u >> v >> d;
        limit[i].push_back(u - 1); limit[i].push_back(v - 1); limit[i].push_back(d);
    }
    Dinic D;
    D.init(10050 + 2);
    for (int i = 0; i < n; ++i){
        for (int x = interval[i].first; x <= interval[i].second; ++x){
            int val = - (f[i][0] * x * x + f[i][1] * x + f[i][2]) + shift;
            D.AddEdge(vt(i, x), vt(i, x + 1), val);
        }
    }
    for (int i = 0; i < n; ++i){
        D.AddEdge(10050, vt(i, interval[i].first), INF);
        D.AddEdge(vt(i, interval[i].second + 1), 10051, INF);
    }

    for (int j = 0; j < m; ++j){
        u = limit[j][0], v = limit[j][1], d = limit[j][2];
        int lu = interval[u].first, ru = interval[u].second, lv = interval[v].first, rv = interval[v].second;
        for (int x = lu; x <= ru; ++x){
            int dest = (x - d <= rv) ? x - d : rv + 1;
            if (x - d < lv) continue;
            D.AddEdge(vt(u, x), vt(v, dest), INF);
        }
    }

    int flow = D.Maxflow(10050, 10051);
    int ans = -(flow - n * shift);
    printf("%d", ans);

}