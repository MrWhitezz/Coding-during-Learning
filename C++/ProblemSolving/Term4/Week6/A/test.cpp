#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 100000 + 10;

int n;
ll d = 0;
ll d1[N], d2[N];
vector<pair<int, ll>> E[N];

void dfs(int u, int fa) {
  d1[u] = d2[u] = 0;
  for (auto pr : E[u]) {
    int v = pr.first;
    ll w = pr.second;
    if (v == fa) continue;
    dfs(v, u);
    int t = d1[v] + w;
    if (t > d1[u])
      d2[u] = d1[u], d1[u] = t;
    else if (t > d2[u])
      d2[u] = t;
  }
  d = max(d, d1[u] + d2[u]);
}

int main() {
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    ll w;
    cin >> u >> v >> w;
    E[u].push_back({v, w}), E[v].push_back({u, w});
  }
  dfs(1, 0);
  cout << d;
  return 0;
}