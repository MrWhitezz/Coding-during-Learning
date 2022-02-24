#include<bits/stdc++.h>
using namespace std;

#define maxn 25000
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

  void clean_flow(){
      for (auto it = edges.begin(); it != edges.end(); ++it){
          it->flow = 0;
      }
  }
};
unordered_map<int, bool> square;
void init_sq(){
    for (int i = 1; i < 1000; ++i)
        square[i * i] = 1;
}
int N;
vector<vector<int>> res;
vector<list<int>> RES;
int main(){
    init_sq();
    cin >> N;
    res.resize(N + 5);
    RES.resize(N + 5);
    int flow_cur = 0;
    int pillar = 0;
    int num = 0;
    Dinic D;
    D.init(maxn / 2);
    int S = 0, T = 1;
    int this_flow = 0;
    while (pillar <= N){
        num++;
        D.AddEdge(S, 2 * num, 1);
        D.AddEdge(2 * num + 1, T, 1);
        for (int i = 1; i < num; ++i){
            if (square.find(num + i) != square.end()){
                // printf("%d + %d = %d\n", num, i, num + i);
                D.AddEdge(2 * num, 2 * i + 1, 1);
            }
        }

        // D.clean_flow();
        this_flow = D.Maxflow(S, T);
        if (this_flow == 0){
           pillar++; 
        }
        flow_cur = this_flow;
        // printf("%d pillar hold %d balls with flow %d\n", pillar, num, flow_cur);
    }
    num -= 1;
    vector<int> follow(num + 5, -1);
    int next_pillar = 1;

    for (auto it = D.edges.begin(); it != D.edges.end(); ++it){
        int from = it->from, to = it->to, Flow = it->flow, cap = it->cap;
        if (from != S && to != T && Flow > 0){
            // printf("%d to %d flow: %d (cap: %d)\n", from / 2, to / 2, Flow, cap);
            // assert(Flow == 1);

            follow[from / 2] = (to - 1) / 2;
        } 
    }
    for (int i = 1; i <= num; i++){
        if (follow[i] == -1){
            // assert(next_pillar < N + 5);
            // assert(res[next_pillar].empty());

            // res[next_pillar].push_back(i);
            RES[next_pillar].push_back(i);
            RES[next_pillar] = list<int> (1, i);
            next_pillar++;
            continue;
        }
        else{
            for (int j = 1; j < next_pillar; ++j){
                // assert(res[j].empty() == 0);
                // if (res[j][res[j].size() - 1] == follow[i])
                //     res[j].push_back(i); 
                    
                if (RES[j].back() == follow[i]){
                  RES[j].push_back(i);
                  break;
                }
            }
        }
    }
     
    // assert(next_pillar == N + 1); 
    printf("%d\n", num);
    for (int i = 1; i < next_pillar; ++i){
        for (auto it = RES[i].begin(); it != RES[i].end(); ++it){
            printf("%d ", *it);
        }
        printf("\n");
    }
}