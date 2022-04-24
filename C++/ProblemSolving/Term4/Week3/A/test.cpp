#include<bits/stdc++.h>
using namespace std;
#define maxn 1550
// 树的最小点覆盖：先求一遍dfs序，倒序遍历。若此节点及其父节点均未被标记，则将其父节点加入覆盖集，并标记此节点及其父节点。
// 证明不太会
vector<vector<int>> edge;
vector<int> label; // <order, id>
vector<bool> visited, cover;
vector<int> parent;

int n, ans = 0;
int x, y, k;
int od = 0;

void dfs(int n);

int main(){
    cin >> n;
    label.clear();
    edge.resize(n + 5);
    parent.resize(n + 5);
    visited = vector<bool>(n + 5, false);
    cover = vector<bool>(n + 5, 0);
    for (int i = 0; i < n; ++i){
        cin >> x >> k;
        for (int j = 0; j < k; ++ j){
            cin >> y;
            edge[x].push_back(y);
            if (find(edge[y].begin(), edge[y].end(), x) == edge[y].end()){
                edge[y].push_back(x);
            }
        }
    }
    
    parent[0] = -1; // non-exist
    dfs(0);
    for (auto it = label.rbegin(); it != label.rend(); ++it){
        int v = *it;
        if (cover[v] == false){
            if (parent[v] != -1 && cover[parent[v]] == false){
                ans++;
                cover[v] = true;
                cover[parent[v]] = true;
            }
        }
    }
    cout << ans << endl;

}

void dfs(int n){
    if(visited[n] == false){
        visited[n] = true;
        label.push_back(od);
        od++;
        for (auto v : edge[n]){
            if (visited[v] == false){
                parent[v] = n;
                dfs(v);
            }
        }
    }
}
