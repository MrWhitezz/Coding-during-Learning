// std SPFA
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
vector<vector<pair<int, ll>>> edge;
vector<ll> dist;
queue<int> Q;
int main(){
    int n, m, x, y, u, v;
    ll w;
    cin >> n >> m;
    dist = vector<ll>(n + 1, 0);
    edge.resize(n + 1);
    // for (int i = 1; i <= n; ++i){
    //     edge[0].push_back(i, 0);
    // }
    for (int i = 0; i < m; ++i){
        cin >> x >> y >> w;
        edge[x].push_back(pair<int, ll>{y, -w});
    }
    for (int i = 1; i <= n; ++i)
        Q.push(i);
    while (!Q.empty()){
        u = Q.front();
        Q.pop();
        for (auto it = edge[u].begin(); it != edge[u].end(); ++it){
            v = it->first; w = it->second;
            if (dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                Q.push(v);
            }
        }
    }
    ll ans = -*min_element(dist.begin() + 1, dist.end() + 1);
    cout << ans;

}