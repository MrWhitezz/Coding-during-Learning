#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;
class UnionFind {
  std::vector<int> f;
public:
  UnionFind(int n = 0) : f(n + 1) {
    for (int i = 1; i <= n; i++)
      f[i] = i;
  }

  int find(int x) {
    if (f[x] == x) return x;
    return f[x] = find(f[x]);
  }

  void merge(int u, int v) {
    u = find(u); v = find(v);
    if (u < v) f[v] = u; else f[u] = v;
  }
};
struct side
{
    int v1;
    int v2;
    int w;
    bool cho;
};
bool cmp(side &s1, side &s2)
{
    return s1.w < s2.w;
}
int main()
{
    int n, m;
    cin >> n >> m;
    UnionFind u(n);
    side S[m];
    for (int i = 0; i < m; i++)
    {
        cin >> S[i].v1 >> S[i].v2 >> S[i].w;
        S[i].cho = false;
    }
    sort(S, S + m, cmp);
    long long sum = 0;
    for (int i = 0; i < m; i++)
    {
        if (u.find(S[i].v1) != u.find(S[i].v2))
        {
            u.merge(S[i].v1, S[i].v2);
            S[i].cho = true;
            sum += S[i].w;
        }

    }
    cout << sum;

    return 0;
}
