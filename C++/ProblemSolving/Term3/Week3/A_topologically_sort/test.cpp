// FAIL
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> edge;
// vector<int> vertex_time;
vector<bool> is_visit;
deque<int> vertex_topo;
int n, m, time_dfs, x, y;
void dfs(int v);
// bool cmp(int u, int v){
//     return vertex_time[u] > vertex_time[v];
// }
int main(){
    time_dfs = 0;
    cin >> n >> m;
    edge.resize(n + 1);
    //vertex_time.resize(n + 5);
    vertex_topo.clear();
    is_visit = vector<bool> (n + 5, 0);
    for (int i = 0; i < m; ++i){
        cin >> x >> y;
        edge[x].push_back(y);
    }
    // vector<int> vertices(n);
    // for (int i = 0; i < n; ++i)
    //     vertices[i] = i;
    for (int i = 1; i <= n; ++i)
        sort(edge[i].begin(), edge[i].end(), greater<int>());
    for (int i = n; i >= 1; --i)
        dfs(i);
    // sort(vertices.begin(), vertices.end(), cmp);
    // for (auto it = vertices.begin(); it != vertices.end(); ++it)
    //     cout << *it << " ";
    for (auto it = vertex_topo.begin(); it != vertex_topo.end(); ++it)
        printf("%d ", *it);
    return 0;
}
void dfs(int v){
    if (is_visit[v])
        return; 
    is_visit[v] = true;
    //time_dfs++;
    for(auto it = edge[v].begin(); it != edge[v].end(); ++it)
        if(!is_visit[*it]){
            dfs(*it);
        }
    //time_dfs++;
    //vertex_time[v] = time_dfs;
    vertex_topo.push_front(v);
}