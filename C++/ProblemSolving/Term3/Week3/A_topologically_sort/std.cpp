// not my idea, something like greedy
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> edge;
vector<int> ind;
int n, m, x, y, cur;
int main(){
    cin >> n >> m;
    edge.resize(n + 1);
    ind = vector<int> (n + 1, 0);
    for (int i = 0; i < m; ++i){
        cin >> x >> y;
        edge[x].push_back(y);
        ind[y]++;
    }
    vector<int> ans;
    priority_queue<int, vector<int>, greater<int>> Q;
    for (int i = 1; i <= n; ++i)
        if (ind[i] == 0) Q.push(i);
    while (!Q.empty()){
        cur = Q.top();
        Q.pop();
        ans.push_back(cur);
        for (auto it = edge[cur].begin(); it != edge[cur].end(); ++it){
            ind[*it]--;
            if (ind[*it] == 0) Q.push(*it);
        }
    }
    for (auto v : ans)
        printf("%d ", v);
    return 0;
}