#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 300005
#define INF 0x3f3f3f3f3f3f3f

struct edge {
  int v;
  ll w;
};
vector<edge> e[maxn];
vector<edge> e2[maxn];
ll dis[maxn]; int cnt[maxn], vis[maxn];
ll ans[maxn];
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


int t1, t2, n, m, u, v;
ll w;
int main(){
    cin >> t1 >> t2 >> n >> m;
    if (t1 == 0 && t2 == 0){
    for (int i = 0; i < m; ++i){
        cin >> u >> v >> w;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }
    spfa(n, 1);
    for (int i = 2; i <= n; ++i){
        cout << dis[i] << " ";
    }
    }
    else{
      for (int i = 0; i < m; ++i){
        cin >> u >> v >> w;
        e[u].push_back({v, w});
        e[v].push_back({u, w});

        e[u + n].push_back({v + n, w});
        e[v + n].push_back({u + n, w});

        e[u + 2 * n].push_back({v + 2 * n, w});
        e[v + 2 * n].push_back({u + 2 * n, w});

        e[u].push_back({v + n, 0});
        e[v].push_back({u + n, 0});

        e[u].push_back({v + 2 * n, 2 * w});
        e[v].push_back({u + 2 * n, 2 * w});

        e[u + n].push_back({v + 2 * n, 3 * w});
        e[v + n].push_back({u + 2 * n, 3 * w});



        e2[u].push_back({v, w});
        e2[v].push_back({u, w});

        e2[u + n].push_back({v + n, w});
        e2[v + n].push_back({u + n, w});

        e2[u + 2 * n].push_back({v + 2 * n, w});
        e2[v + 2 * n].push_back({u + 2 * n, w});

        e2[u].push_back({v + n, 3 * w});
        e2[v].push_back({u + n, 3 * w});

        e2[u + n].push_back({v + 2 * n, 0});
        e2[v + n].push_back({u + 2 * n, 0});
        
    }
    spfa(3 * n, 1);

    for (int i = 2 * n + 2; i <= 3 * n; ++i){
        ans[i] = dis[i];
    }
    for (int i = 1; i <= 3 * n; ++i){
      e[i] = e2[i];
    } 
    memset(dis, 0, sizeof(dis));
    memset(cnt, 0, sizeof(cnt));
    memset(vis, 0, sizeof(vis));

    spfa(3 * n, 1);
    for (int i = 2 * n + 2; i <= 3 * n; ++i){
        ans[i] = min(ans[i], dis[i]);
        cout << ans[i] << " ";
    }

    }



}