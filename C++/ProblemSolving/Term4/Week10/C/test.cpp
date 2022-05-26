#include<bits/stdc++.h>
using namespace std;
#define maxn 2005
struct edge {
  int v, w;
};
vector<edge> e[maxn];
int dis[maxn], cnt[maxn], vis[maxn];
queue<int> q;
bool spfa(int n, int s) {
  memset(dis, 63, sizeof(dis));
  memset(cnt, 0, sizeof(cnt));
  memset(vis, 0, sizeof(vis));
  q = queue<int>();
  dis[s] = 0, vis[s] = 1;
  q.push(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop(), vis[u] = 0;
    for (auto ed : e[u]) {
      int v = ed.v, w = ed.w;
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
int n, m, k, T;

int main() {
    cin >> T;
    while (T--) {
        for (int i = 0; i < maxn; i++) {
            e[i].clear();
        }
        cin >> n >> m >> k;
        for (int i = 1; i <= k; ++i) {
            int x, y, c;
            cin >> x >> y >> c;
            e[y + n].push_back((edge){x, c});
            e[x].push_back((edge){y + n, -c});
        }
        int N = n + m + 1;
        for (int i = 1; i < N; ++i) {
            e[0].push_back((edge){i, 0});
        }

        if (spfa(N, 0)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

}