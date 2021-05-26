// It is a hard dp
#include<bits/stdc++.h>
using ll = long long;
const ll mod = 998244353;
using namespace std;
int n, m;
ll Tot, illegal;
int main()
{
    cin >> n >> m;
    ll cook[n][m];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> cook[i][j];
    ll sum[n];
    for (int i = 0; i < n; ++i){
        sum[i] = 0;
        for (int j = 0; j < m; ++j)
            sum[i] = (sum[i] + cook[i][j]) % mod;
    }
    ll total[n + 1][n + 1];// using first i rows, choose j 
    for (int i = 1; i <= n; ++i)
        total[0][i] = 0;
    for (int i = 0; i <= n; ++i)
        total[i][0] = 1;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            total[i][j] = (total[i - 1][j] + total[i - 1][j - 1] * sum[i - 1] % mod) % mod;
    for (int j = 1; j <= n; ++j)
        Tot = (Tot + total[n][j]) % mod;

    int nn = 2 * n + 1;
    ll dp[n + 1][2 * n + 1]; //dp[i][j + n] using first i rows, choose col more than others of j, -n <= j <= n
    for(int k = 0; k < m; ++k){
        for (int j = 0; j < nn; ++j)
            dp[0][j] = 0;

        for (int i = 1; i <= n; ++i){
            for (int j = 0; j < nn; ++j){
                // dp[i][j] = (dp[i - 1][j] + (j == 0) ? 0 : dp[i - 1][j - 1] * cook[i - 1][k] % mod
                // + (j == (nn - 1)) ? 0 : dp[i - 1][j + 1] * (sum[i - 1] - cook[i - 1][k]) % mod) % mod;
                dp[i][j] = dp[i - 1][j];
                if (j != 0) dp[i][j] = (dp[i][j] + dp[i - 1][j - 1] * cook[i - 1][k] % mod) % mod;
                if (j != nn - 1) dp[i][j] = (dp[i][j] + dp[i - 1][j + 1] * (sum[i - 1] - cook[i - 1][k] + mod) % mod) % mod;
            }
            dp[i][n + 1] = (dp[i][n + 1] + cook[i - 1][k]) % mod;
            dp[i][n - 1] = (dp[i][n - 1] + sum[i - 1] - cook[i - 1][k] + mod) % mod;
        }
            
        for (int j = n + 1; j < nn; ++j)
            illegal = (illegal + dp[n][j]) % mod;       
    }
    cout << (Tot - illegal + mod) % mod << endl;
    return 0;
}