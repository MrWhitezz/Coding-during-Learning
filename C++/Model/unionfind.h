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

// 带权并查集
#define N 105
int father[N];
int value[N];

void init(int n) {
  for (int i = 0; i <= n; i++) {
    father[i] = i;
    value[i] = 0;
  }
}

int Find (int x) {
    if (father[x] == x)
        return x;
 
    int temp = father[x];
    father[x] = Find(father[x]);
    value[x] += value[temp]; //结点x到根的距离
 
    return father[x];
}

int Union(int x, int y, int val) {
    int fx = Find(x);
    int fy = Find(y);
 
    if (fx == fy) //如果当前两点与之前距离有冲突
        if(value[y] != value[x] + val)
            return 1;
 
    father[fy] = fx; // fx as root
    value[fy] = value[x] - value[y] + val; //计算两点距离
    return 0;
}