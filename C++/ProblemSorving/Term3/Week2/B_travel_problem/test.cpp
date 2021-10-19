#include<bits/stdc++.h>
using namespace std;
using ll = long long;
vector<vector<ll>> dp;
int main(){
    int n;   
    cin >> n;
    ll A[n + 1][n + 1];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> A[i][j];
   
    dp = vector<vector<ll>>(1 << n, vector<ll>(n, LLONG_MAX / 2));
    dp[0] = vector<ll> (n, 0);
    for (int i = 0; i < n; ++i)
        dp[1 << i][i] = 0;
    for (int s = 1; s < (1 << n); ++s){
        bool is_circle = true;
        for(int v = 0; v < n; v++)
            for (int u = 0; u < n; ++u)
                if (s >> v & 1)
                    dp[s][v] = min(dp[s][v], dp[s - (1 << v)][u] + A[u][v]);
        while (is_circle){
            is_circle = false;
            for (int v = 0; v < n; ++v)
                for (int u = 0; u < n; ++u)
                    if (s >> v & 1)
                        if (dp[s][u] + A[u][v] < dp[s][v]){
                            dp[s][v] = dp[s][u] + A[u][v];
                            is_circle = true;
                        }
                    
        } 
    }
    ll ans = *min_element(dp[(1 << n) - 1].begin(), dp[(1 << n) - 1].end());
    cout << ans;
}