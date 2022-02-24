#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 2005
struct edge {
  int v;
  ll w;
};
vector<edge> e[maxn];
ll dis[maxn]; int cnt[maxn], vis[maxn];
queue<int> q;
bool spfa(int n, int s) {
  memset(dis, 63, sizeof(dis));
  dis[s] = 0, vis[s] = 1;
  q.push(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop(), vis[u] = 0;
    for (auto ed : e[u]) {
      int v = ed.v; ll w = ed.w;
      if (dis[v] > dis[u] + w) {
        dis[v] = dis[u] + w;
        cnt[v] = cnt[u] + 1;  // 记录最短路经过的边数
        if (cnt[v] >= n) return false;
        // 在不经过负环的情况下，最短路至多经过 n - 1 条边
        // 因此如果经过了多于 n 条边，一定说明经过了负环
        if (!vis[v]) q.push(v), vis[v] = 1;
      }
    }
  }
  return true;
}

int n, m, u, v;
ll w;
int main(){
    cin >> n >> m;
    for (int i = 0; i < m; ++i){
        cin >> u >> v >> w;
        e[u].push_back(edge({v, w}));
    }
    spfa(n, 1);
    for (int i  = 1; i <= n; ++i){
        cout << dis[i] << " ";
    }
}