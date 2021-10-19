#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 10005
#define INF 0x3f3f3f3f3f3f3f3f
const ll shift = 0x3f3f3f3f3f3f;

struct Edge {
  int from, to; ll cap, flow;
  Edge(int u, int v, ll c, ll f) : from(u), to(v), cap(c), flow(f) {}
};

struct Dinic {
  int n, m, s, t;
  vector<Edge> edges;
  vector<ll> G[maxn];
  int d[maxn], cur[maxn];
  bool vis[maxn];

  void init(int n) {
    for (int i = 0; i < n; i++) G[i].clear();
    edges.clear();
  }

    void AddEdge(int from, int to, ll cap) {
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

  ll DFS(int x, ll a) {
    if (x == t || a == 0) return a;
    ll flow = 0, f;
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

  ll Maxflow(int s, int t) {
    this->s = s;
    this->t = t;
    ll flow = 0;
    while (BFS()) {
      memset(cur, 0, sizeof(cur));
      flow += DFS(s, INF);
    }
    return flow;
  }
};
int T, n, p, q, x, y, z, r;
ll a, b, c, d, e, f;
ll W;
int main(){
    cin >> T;
    while (T--){
        cin >> n >> W >> p >> q;
        Dinic D; D.init(n + 5);
        vector<ll> in(n + 1, -W), out(n + 1, W);
        for (int i = 0; i < p; ++i){
            cin >> x >> y >> z >> a >> b >> c >> d >> e >> f;
            D.AddEdge(x, y, 2 * a * W), D.AddEdge(y, x, 2 * a * W);
            D.AddEdge(y, z, 2 * b * W), D.AddEdge(z, y, 2 * b * W);
            D.AddEdge(x, z, 2 * c * W), D.AddEdge(z, x, 2 * c * W);
            in[x] += (f - d) * W;
            in[y] += (d - e) * W;
            in[z] += (e - f) * W;
        }
        for (int i = 0; i < q; ++i){
            cin >> x >> y >> r;
            switch (r){
                case 0: D.AddEdge(x, y, INF); break;
                case 1: D.AddEdge(x, y, INF); D.AddEdge(y, x, INF); break;
                case 2: D.AddEdge(0, y, INF); D.AddEdge(x, n + 1, INF); break;
                default: break;
            }
        }
        for (int i = 1; i <= n; ++i){
            out[i] = - in[i];
            D.AddEdge(0, i, in[i] + shift);
            D.AddEdge(i, n + 1, out[i] + shift);
        }
        ll flow = D.Maxflow(0, n + 1) - (ll)n * shift;
        printf("%lld\n", flow);
    }
    return 0;
}