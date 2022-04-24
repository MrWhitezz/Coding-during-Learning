#include<bits/stdc++.h>
using namespace std;

#define maxn 10005

struct Twosat {
  int n;
  vector<int> g[maxn * 2];
  bool mark[maxn * 2];
  int s[maxn * 2], c; // s is for backtracking

  bool dfs(int x) {
    if (mark[x ^ 1]) return false;
    if (mark[x]) return true;
    mark[x] = true;
    s[c++] = x;
    for (int i = 0; i < (int)g[x].size(); i++)
      if (!dfs(g[x][i])) return false;
    return true;
  }

  void init(int n) {
    // should be exactly n variables ? not sure
    this->n = n;
    for (int i = 0; i < n * 2; i++) g[i].clear();
    memset(mark, 0, sizeof(mark));
  }

  void add_clause(int x, int y) {  // 这个函数随题意变化
    g[x ^ 1].push_back(y);         // 选了 x^1 就必须选 y
    g[y ^ 1].push_back(x);
  }

  bool solve() {
    for (int i = 0; i < n * 2; i += 2)
      if (!mark[i] && !mark[i + 1]) {
        c = 0;
        if (!dfs(i)) {
          while (c > 0) mark[s[--c]] = false;
          if (!dfs(i + 1)) return false;
        }
      }
    return true;
  }
};
int T, n, k, a, b, c;
int u, v, w;
int get_id (int k){
    if (k >= 0)
        return k * 2;
    else return (-k * 2) ^ 1;
}
int main(){
    cin >> T;
    while (T--){
        cin >> k >> n;
        Twosat S;
        S.init(k + 2);
        for (int i = 0; i < n; ++i){
            cin >> a >> b >> c;
            u = get_id(a), v = get_id(b), w = get_id(c);
            S.add_clause(u, v);
            S.add_clause(v, w);
            S.add_clause(w, u);
        }
        if (S.solve())
            cout << "yes\n";
        else cout << "no\n";
    }

}