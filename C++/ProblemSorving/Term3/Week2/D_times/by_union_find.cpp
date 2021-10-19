#include<bits/stdc++.h>
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
};
int n, T, tmp, reach;
vector<int> bitsnum;
int main(){
    cin >> T;
    while (T--){
        cin >> n;
        UnionFindSet u(n);
        bitsnum = vector<int> (n, INT_MAX / 2);   
        for (int i = 1; i < n; ++i)
            u.merge(i, i * 2 % n);
        if (n == 1 || u.setid(1) == 0){
            cout << 1 << endl;
            continue;
        }
        bitsnum[1] = 1;
        for (int i = 1; i < n; ++i){
            reach = (i * 2 + 1) % n;
            if (bitsnum[u.setid(reach)] > bitsnum[u.setid(i)] + 1)
                bitsnum[u.setid(reach)] = bitsnum[u.setid(i)] + 1;

        }
        cout << bitsnum[0] << endl;
    }
}