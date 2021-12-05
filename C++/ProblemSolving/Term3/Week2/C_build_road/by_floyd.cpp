#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll m;
    int x, y, n;
    cin >> n >> m;
    ll f[n][n];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            f[i][j] = i == j ? 0 : LLONG_MAX;
    for (ll i = 1; i <= m; ++i){
        cin >> x >> y;
        f[x - 1][y - 1] = i;
    }
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                f[i][j] = min(f[i][j], max(f[i][k], f[k][j]));
    
    vector<ll> ans(m + 1);
    for(int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (i != j) ans[f[i][j]]++;

    for (ll i = 0; i < m; ++i){
        ans[i + 1] += ans[i];
        cout << ans[i + 1] << " ";
    }
        
    


        
}