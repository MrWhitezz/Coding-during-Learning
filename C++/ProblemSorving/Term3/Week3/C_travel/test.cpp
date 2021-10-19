#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n, m, u, v, w;
const int N = 2.1e6 + 10, mod = 1e9 + 7;
vector<int> edge[N][10], e, Q[N]; //edge[i][5] says the vertex i , with edge weight 5, his neighbours
                                //Q is the queue, Q[i] is a level of queue
bool vis[N];
vector<int> ans(N);
int main(){
    cin >> n >> m;
    int tot = n;
    for (int i = 0; i < m; ++i){
        cin >> u >> v >> w;
        e.clear();
        while(w) {e.push_back(w % 10); w /= 10;}
        reverse(e.begin(), e.end());
        int pre = u;
        for (int j = 0; j < e.size(); ++j){
            int next = (j == e.size() - 1) ? v : ++tot;
            edge[pre][e[j]].push_back(next);
            pre = next;
        }
        pre = v;
        for (int j = 0; j < e.size(); ++j){
            int next = (j == e.size() - 1) ? u : ++tot;
            edge[pre][e[j]].push_back(next);
            pre = next;
        }
        
    }
    int T = 0; Q[0].push_back(1); vis[1] = true; // using T to ensure Q is a queue
    for (int i = 0; i <= T; ++i){
        for (int j = 0; j <= 9; ++j){
            bool new_vis = false;
            for (auto x : Q[i]){
                for (auto y : edge[x][j]){
                    if (vis[y]) continue;
                    vis[y] = true; Q[T + 1].push_back(y); new_vis = true;
                    ans[y] = (ans[x] * 10ll + j) % mod;
                }
            }
            if (new_vis) ++T;
        }
        Q[i].clear();
    }

    for (int i = 2; i <= n; ++i)
        if (ans[i]) printf("%d\n", ans[i]);
        else printf("-1\n");

    return 0;
}