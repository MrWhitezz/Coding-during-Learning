#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll P = 1e9 + 7;
#define maxn 1000005
int n;

int a[maxn];
int amax[maxn];
int amin[maxn];
int aor [maxn];
int lft[maxn];
int rgt[maxn];

template <typename T>
vector<size_t> sort_indexes(const vector<T> &v) {

  // initialize original index locations
  vector<size_t> idx(v.size());
  iota(idx.begin(), idx.end(), 0);

  // sort indexes based on comparing values in v // using std::stable_sort instead of std::sort
  // to avoid unnecessary index re-orderings // when v contains elements of equal values 
  stable_sort(idx.begin(), idx.end(),
       [&v](size_t i1, size_t i2) {return v[i1] < v[i2];});

  return idx;
}

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
    for (int i = 1; i <= n; i++) f[i] = i;
  }

  int setid(int x) {
    return _setid(x);
  }

  void merge(int x, int y) {
    _merge(x, y);
  }
} ;

void merge(UnionFindSet &ufs, int x, int y) {
    int x1 = ufs.setid(x);
    int y1 = ufs.setid(y);
    ufs.merge(x, y);
    int x2 = ufs.setid(x);
    int y2 = ufs.setid(y);
    assert(x2 == y2);
    amax[x2] = max(amax[x1], amax[y1]);
    amin[x2] = min(amin[x1], amin[y1]);
    aor [x2] = aor[x1] | aor[y1];
    lft[x2] = min(lft[x1], lft[y1]);
    rgt[x2] = max(rgt[x1], rgt[y1]);
}

int main(){
    int T;
    cin >> T;
    while (T--){
        cin >> n;
        ll p, q, x, y, z;
        cin >> p >> q >> x >> y >> z;
        a[1] = p;
        a[2] = q;
        for (int i = 3; i <= n; i++){
            a[i] = (a[i - 2] * x + a[i - 1] * y + z) % 1000000LL + 1; 
        }
        // a[0] = a[1], a[n + 1] = a[n];
        vector<int> v(a + 1, a + n + 1);
        assert(v.size() == n);
        vector<size_t> idx = sort_indexes(v);
        for (auto &i :idx) i += 1;
        UnionFindSet ufs(n);

        for (int i = 1; i <= n; i++){
            amax[i] = amin[i] = aor[i] = a[i];
            lft[i] = rgt[i] = i;
        }

        __int128_t V = 0;
        for (auto it = idx.rbegin(); it != idx.rend(); ++it){
            int i = *it;
            assert(i >= 1 && i <= n);
            if (i != n && a[i] <= a[i + 1]){
                assert(a[i] <= amin[ufs.setid(i + 1)]);
                merge(ufs, i, i + 1);
            }
            if (i != 1 && a[i] <= a[i - 1]){
                merge(ufs, i, i - 1);
            }
            int id = ufs.setid(i);
            __int128_t A = amax[id];
            __int128_t B = amin[id];
            __int128_t C = (rgt[id] - lft[id]) + 1;
            __int128_t D = aor[id];
            V = max(V, (A - B) * B * C * D);
        }
        V = V % P;
        cout << ((ll)V) << endl;
    }
}