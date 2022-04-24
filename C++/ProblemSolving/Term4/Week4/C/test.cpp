#include<bits/stdc++.h>
#define MXN 100007
using namespace std;
std::vector<int> v[MXN];

int fa[MXN][31], dep[MXN];
int n, m, S;
int a, b, c;

// dfs，用来为 lca 算法做准备。接受两个参数：dfs 起始节点和它的父亲节点。
void dfs(int root, int fno) {
  // 初始化：第 2^0 = 1 个祖先就是它的父亲节点，dep 也比父亲节点多 1。
  fa[root][0] = fno;
  dep[root] = dep[fa[root][0]] + 1;
  // 初始化：其他的祖先节点：第 2^i 的祖先节点是 第 2^(i-1) 的祖先节点的第 2^(i-1) 的祖先节点。
  for (int i = 1; i < 31; ++i) {
    fa[root][i] = fa[fa[root][i - 1]][i - 1];
  }
  // 遍历子节点来进行 dfs。
  int sz = v[root].size();
  for (int i = 0; i < sz; ++i) {
    if (v[root][i] == fno) continue;
    dfs(v[root][i], root);
  }
}

// lca。用倍增算法算取 x 和 y 的 lca 节点。
int lca(int &x, int &y) {
  // 令 y 比 x 深。
  if (dep[x] > dep[y]) swap(x, y);
  // 令 y 和 x 在一个深度。
  int tmp = dep[y] - dep[x], ans = 0;
  for (int j = 0; tmp; ++j, tmp >>= 1)
    if (tmp & 1)  y = fa[y][j];
  // 如果这个时候 y = x，那么 x，y 就都是它们自己的祖先。
  if (y == x) return ans;
  // 不然的话，找到第一个不是它们祖先的两个点。
  for (int j = 30; j >= 0 && y != x; --j) {
    if (fa[x][j] != fa[y][j]) {
      x = fa[x][j];
      y = fa[y][j];
    }
  }
  assert(fa[x][0] == fa[y][0]);
  x = fa[x][0];
  y = fa[y][0];

  // 返回结果。
  return ans;
}

int main() {
  // 初始化表示祖先的数组 fa，代价 cost 和深度 dep。
  memset(fa, 0, sizeof(fa));
  memset(dep, 0, sizeof(dep));
  cin >> n >> m >> S;
  for (int i = 1; i < n; ++i) {
    scanf("%d %d", &a, &b);
    v[a].push_back(b);
    v[b].push_back(a);
  }
  // 为了计算 lca 而使用 dfs。
  dfs(S, 0);
  // 查询 m 次，每一次查找两个节点的 lca 点。
  for (int i = 0; i < m; ++i) {
    scanf("%d %d", &a, &b);
    lca(a, b);
    printf("%d\n", a);
  }
  return 0;
}