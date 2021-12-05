#include<bits/stdc++.h>
using namespace std;

#define maxn 30005
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
int n, m, ans = 0;
int pos(int i, int j) {return i * m + j;}
int main(){
    cin >> n >> m;
    int numst = n * m;
    int S = 3 * numst + 1, T = 3 * numst + 2;
    Dinic D;
    D.init(3 * numst + 5);
    int art[n][m], sci[n][m], same_art[n][m], same_sci[n][m];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {cin >> art[i][j]; ans += art[i][j];}
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {cin >> sci[i][j]; ans += sci[i][j];}
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {cin >> same_art[i][j]; ans += same_art[i][j];}
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {cin >> same_sci[i][j]; ans += same_sci[i][j];}

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j){
            D.AddEdge(S, pos(i, j), art[i][j]); D.AddEdge(pos(i, j), T, sci[i][j]);
            D.AddEdge(S, numst + pos(i, j), same_art[i][j]);
            D.AddEdge(numst + pos(i, j), pos(i, j), INF);
            if (i != 0)     D.AddEdge(numst + pos(i, j), pos(i - 1, j), INF);
            if (i != n - 1) D.AddEdge(numst + pos(i, j), pos(i + 1, j), INF);
            if (j != 0)     D.AddEdge(numst + pos(i, j), pos(i, j - 1), INF);
            if (j != m - 1) D.AddEdge(numst + pos(i, j), pos(i, j + 1), INF);

            D.AddEdge(2 * numst + pos(i, j), T, same_sci[i][j]);
            D.AddEdge(pos(i, j), 2 * numst + pos(i, j), INF);
            if (i != 0)     D.AddEdge(pos(i - 1, j), 2 * numst + pos(i, j), INF);
            if (i != n - 1) D.AddEdge(pos(i + 1, j), 2 * numst + pos(i, j), INF);
            if (j != 0)     D.AddEdge(pos(i, j - 1), 2 * numst + pos(i, j), INF);
            if (j != m - 1) D.AddEdge(pos(i, j + 1), 2 * numst + pos(i, j), INF);
        }

    int cut = D.Maxflow(S, T);
    ans -= cut;
    cout << ans;

    return 0;
}