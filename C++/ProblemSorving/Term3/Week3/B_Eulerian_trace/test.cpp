//fail, don't know why
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
} ;
#define NSize 500
bool is_Connected();
int F, x, y, odd, start, minn;
bool is_odd, is_minn = false;
int edge[NSize + 1][NSize + 1];
vector<int> deg(NSize + 1);
vector<int> ans;
void dfs(int v);
int main(){
    cin >> F;
    for (int i = 1; i <= NSize; ++i)
        for (int j = 1; j <= NSize; ++j)
            edge[i][j] = 0;
    for (int i = 0; i < F; ++i){
        cin >> x >> y;
        edge[x][y]++, edge[y][x]++;
        deg[x]++, deg[y]++;
    }

    is_odd = false;
    for (int i = 1; i <= NSize; ++i){
        if (deg[i] & 1){
            is_odd = true;
            odd = i;
            break;
        }
    }
    for (int i = 1; i <= NSize && !is_minn; ++i)
        for (int j = 1; j <= NSize && !is_minn; ++j){
            if (edge[i][j]) {minn = i; is_minn = true;}
        }
    start = is_odd ? odd : minn;

    ans.push_back(start);
    dfs(start);

    for(auto v : ans)
        cout << v << endl;
}
void dfs(int v){
    bool is_visited = false;
    for (int i = 1; i <= NSize; ++i){
        if (edge[v][i]){
            edge[v][i]--, edge[i][v]--;
            if(is_Connected()){
                is_visited = true;
                ans.push_back(i);
                dfs(i);
                break;
            }
            else {edge[v][i]++, edge[i][v]++;}
        }
    }
}
bool is_Connected(){
    UnionFindSet u (NSize + 1);
    for (int i = 1; i <= NSize; ++i)
        for (int j = 1; j <= NSize; ++j)
            if (edge[i][j]) u.merge(i, j);
    bool is_cp = false; int component = 0;
    for (int i = 1; i <= NSize; ++i){
        if (u.setid(i) != i){
            if (is_cp == false){
                component = u.setid(i);
                is_cp = true;
            }
            else{
                if (component != u.setid(i)) return false;
            }
        }
    }
    return true;
}