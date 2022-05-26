#include <bits/stdc++.h>
using namespace std;
#define maxn 10005
int e[maxn];
int vis[maxn];
vector<int> edge[maxn];
int n, q, ans;

void dfs(int s, int t, int res) {
    if (s == t) 
        ans = res;
    vis[s] = 1;
    for (auto v : edge[s]) {
        if (!vis[v]) {
            dfs(v, t, res ^ e[v]);
        }
    }
}

int main() {
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
        cin >> e[i];
    int u, v;
    for (int i = 1; i < n; ++i) {
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    while (q--) {
        cin >> u >> v;
        ans = 0;
        memset(vis, 0, sizeof(vis));
        dfs(u, v, e[u]);
        cout << ans << endl;
    }
}