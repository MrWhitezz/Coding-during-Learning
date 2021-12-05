#include<bits/stdc++.h>
using namespace std;
#define maxn 3100
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

#define prime_size 200005
bool is_prime[prime_size];
void init_prime(){
    is_prime[1] = 0, is_prime[2] = 1;
    for (int i = 3; i < prime_size; ++i){
        is_prime[i] = 1;
        for (int j = 2; j <= sqrt(i); ++j){
            if (i % j == 0){
                is_prime[i] = 0; break;
            }
        }
    }
}

// void test_prime(int n){
//     for (int i = 1; i <= n; ++i){
//         if (is_prime[i]){
//             printf("%d is prime\n", i); 
//         }
//     }
// }

int N, val, nv, o_size, e_size;
bool has_1 = false;
vector<int> odd, even;
int main(){
    init_prime();
    cin >> N;
    for (int i = 0; i < N; ++i){
        cin >> val;
        if (val == 1){
            if (!has_1){
                has_1 = true;
                odd.push_back(1);
            }
        }
        else{
            if (val & 1) odd.push_back(val);
            else even.push_back(val);
        }
    } 
    nv = odd.size() + even.size();
    o_size = odd.size(); e_size = even.size();
    Dinic D; 
    D.init(nv + 5);
    for (int i = 1; i <= o_size; ++i){
        for (int j = 1; j <= e_size; ++j){
            if (is_prime[odd[i - 1] + even[j - 1]]){
                D.AddEdge(i, o_size + j, 1);
            }
        }
    } 
    for (int i = 1; i <= o_size; ++i)
        D.AddEdge(nv + 1, i, 1);
    for (int j = 1; j <= e_size; ++j)
        D.AddEdge(o_size + j, nv + 2, 1);
    
    int match = D.Maxflow(nv + 1, nv + 2);
    cout << nv - match << endl;

}