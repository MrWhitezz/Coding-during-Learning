// This question is worth including
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
    memset(d, 0, sizeof(d));
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
int p, c;
int res = 0;
int main(){
    cin >> m >> n;
    vector<vector<int>> instr(m + 5);
    Dinic D;
    D.init(m + n + 5);
    int S = m + n + 1, T = m + n + 2;
    for (int i = 1; i <= m; ++i){
        cin >> p;
        res += p;
        D.AddEdge(S, i, p);
        // printf("from source to exp %d : %d\n", i, p);

        char tools[100];
        memset(tools, 0, sizeof(tools));
        cin.getline(tools, 100);
        int ulen = 0, tool;
        while (sscanf(tools + ulen, "%d", &tool) == 1)//之前已经用scanf读完了赞助商同意支付该实验的费用
        {//tool是该实验所需仪器的其中一个      
            //这一行，你可以将读进来的编号进行储存、处理，如连边
            
            D.AddEdge(i, m + tool, INF);
            instr[i].push_back(tool);
            // printf("exp %d need instr %d\n", i, tool);
            
            if (tool==0) 
                ulen++;
            else {
                while (tool) {
                    tool/=10;
                    ulen++;
                }
            }
            ulen++;
        }
    }
    for (int i = 1; i <= n; ++i){
        cin >> c;
        D.AddEdge(m + i, T, c);
        // printf("instr %d: %d\n", i, c);
    }
    int flow = D.Maxflow(S, T);
    res -= flow;
    
    vector<int> exp_use(m + 5, 0);
    vector<int> instr_use(n + 5, 0);

    D.BFS();
    for (int i = 1; i <= m; ++i){
        if (D.d[i] != 0)
            exp_use[i] = 1;
    }
    for (int i = 1; i <= n; ++i){
        if (D.d[m + i] != 0)
            instr_use[i] = 1;
    }
    
    for (int i = 1; i <= m; ++i){
        if (exp_use[i] == 1)
            cout << i << " ";
    }
    cout << endl;
    for (int i = 1; i <= n; ++i){
        if (instr_use[i] == 1)
            cout << i << " ";
    }
    cout << endl;

    printf("%d\n", res);
}