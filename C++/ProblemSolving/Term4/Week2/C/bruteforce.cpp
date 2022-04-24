#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 20
int n, m, u, v;
int edge[maxn][maxn];
vector<int> vt_set;
ll vertices;
bool is_clique(ll vt);
bool is_max_clique(ll vt);
ll ans = 0;

int main(){
    cin >> n >> m;
    for (int i = 0; i < m; ++ i){
        cin >> u >> v;
        edge[u][v] = edge[v][u] = 1;
    }
    for (vertices = 0; vertices < 1 << (n + 1); vertices += 2){
        if (is_max_clique(vertices)){
            ans++;
        }
    }
    cout << ans << endl;

}
bool is_clique(ll vt){
    assert((vt & 1) == 0);
    vt_set.clear();
    int i = 0;
    while (vt > 0){
        vt >>= 1;
        i++;
        if (vt & 1) vt_set.push_back(i);
    }
    for (int s = 0; s < vt_set.size(); ++s){
        for (int t = s + 1; t < vt_set.size(); ++t){
            int v1 = vt_set[s], v2 = vt_set[t];
            if (edge[v1][v2] == 0) return false;
        }
    }
    return true;
}

bool is_max_clique(ll vt){
    if (!is_clique(vt)) return false;

    for (int i = 1; i <= n; ++i){
        ll vt_p = vt | (1 << i);
        if (vt_p != vt){
            // assert((vt & 1) == 0);
            // assert((vt_p & 1) == 0);
            if (is_clique(vt_p)){
                return false;
            }
        }
    }
    return true;
}