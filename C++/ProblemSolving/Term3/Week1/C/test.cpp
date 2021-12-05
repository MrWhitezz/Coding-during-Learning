#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 100003;
vector<vector<pair<int, ll>>> edge;
vector<ll> dist;
vector<bool> is_in_S;
vector<ll> paths;
priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll,int>>> Q;
void addedge(int x, int y, ll z){
    edge[x].push_back(pair<int, ll>(y, z));
}
void relax(int x){
    if (dist[x] != LLONG_MAX){
        for (auto it = edge[x].begin(); it != edge[x].end(); ++it){
            int y = it->first; ll w = it->second;
            if (dist[y] > dist[x] + w) {
                dist[y] = dist[x] + w;
                Q.push({dist[y], y});
            }
        }
    }
}
void count_paths(int x){
    for (auto it = edge[x].begin(); it != edge[x].end(); ++it){
        if (is_in_S[it->first] && dist[x] == dist[it->first] + it->second)
            paths[x] = (paths[x] + paths[it->first]) % MOD;
    }
}

int main(){
    int n, m, u, v;
    ll w;
    cin >> n >> m;
    pair<ll, int> pr;
    edge.resize(n + 5);
    dist = vector<ll>(n + 5, LLONG_MAX);
    is_in_S = vector<bool> (n + 5, false);
    paths = vector<ll> (n + 5, 0);
    paths[1] = 1;
    for (int i = 0; i < m; ++i){
        cin >> u >> v >> w;
        addedge(u, v, w);
        addedge(v, u, w);
    }
    dist[1] = 0;
    Q.push({0, 1});
        
    while (!Q.empty()){
        pr = Q.top();
        Q.pop();
        //relax(pr.second);
        if (is_in_S[pr.second] == false) {
            relax(pr.second);
            count_paths(pr.second);
            is_in_S[pr.second] = true;
        }
    }

    for (int i = 1; i <= n; ++i){
        cout << paths[i] << endl;
    }
    return 0;
}