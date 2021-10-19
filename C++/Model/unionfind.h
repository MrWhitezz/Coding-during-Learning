#include<vector>
using namespace std;
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
    f = vector<int>(n);
    for (int i = 0; i < n; i++) f[i] = i;
  }

  int setid(int x) {
    return _setid(x);
  }

  void merge(int x, int y) {
    _merge(x, y);
  }
} ;