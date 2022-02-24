#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 100005
#define INF 0x3f3f3f3f3f3f3f3f
struct edge {
  int v;
  ll w;
};
struct node {
  ll dis; int u;
  bool operator>(const node& a) const { return dis > a.dis; }
};
vector<edge> e[maxn];
ll dis[maxn], vis[maxn];
priority_queue<node, vector<node>, greater<node> > q;
void dijkstra(int n, int s) {
  memset(dis, 63, sizeof(dis));
  dis[s] = 0;
  q.push({0, s});
  while (!q.empty()) {
    int u = q.top().u;
    q.pop();
    if (vis[u]) continue;
    vis[u] = 1;
    for (auto ed : e[u]) {
      int v = ed.v; ll w = ed.w;
      if (dis[v] > dis[u] + w) {
        dis[v] = dis[u] + w;
        q.push({dis[v], v});
      }
    }
  }
}

int n, m, u, v;
ll w;
int main(){
    cin >> n >> m;
    for (int i = 0; i < m; ++i){
        cin >> u >> v >> w;
        e[u].push_back(edge({v, w})); // not sure
    }
    dijkstra(n, 1);
    for (int i = 1; i <= n; ++i){
        if (dis[i] == INF) cout << -1 << " ";
        else cout << dis[i] << " ";
    }
}