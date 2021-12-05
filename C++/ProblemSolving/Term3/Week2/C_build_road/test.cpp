#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    int n, m, x, y;
    ll ans = 0;
    cin >> n >> m;
    bool reach[n + 1][n + 1];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            reach[i][j] = i == j ? 1 : 0;
    for (int i = 0; i < m; ++i){
        cin >> x >> y;
        // for (int u = 1; u <= n; ++u)
        //     for (int v = 1; v <= n; ++v)
        //         if (!reach[u][v] && (reach[u][x] && reach[y][v])){
        //             reach[u][v] = 1;
        //             ++ans;
        //         }
        if (!reach[x][y]){
            for (int u = 1; u <= n; ++u)
                if (reach[u][x])
                    for (int v = 1; v <= n; ++v)
                        if (reach[y][v] && !reach[u][v]){
                            reach[u][v] = 1;
                            ++ans;
                    }
        }      
        
       cout << ans << " ";
    }


}