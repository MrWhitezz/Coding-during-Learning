#include<bits/stdc++.h>
using namespace std;
int N, M, x, y;
class UnionFindSet {
private:
  vector<int> f;
  int _setid(int x) {
    if (f[x] == x) return x;
    return f[x] = _setid(f[x]);
  }

  void _merge(int x, int y) {
    if (setid(x) < setid(y)) f[setid(y)] = setid(x);
    else f[setid(x)] = setid(y);
  }

public:
  UnionFindSet(int n = 0) { 
    f = vector<int>(n + 5);
    for (int i = 1; i <= n; i++) f[i] = i;
  }

  int setid(int x) {
    return _setid(x);
  }

  void merge(int x, int y) {
    _merge(x, y);
  }
};
int main()
{
    cin >> N >> M;
    vector<int> deg(N + 5);
    UnionFindSet u(N);
    for (int i = 0; i < M; ++i){
        cin >> x >> y;
        u.merge(x, y);
        ++deg[x], ++deg[y];
    }
    for (int i = 1; i <= N; ++i){
        if (u.setid(i) != 1 || deg[i] & 1){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}
