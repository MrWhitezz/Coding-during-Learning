//This is not easy
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
ll n, m, k;
int main()
{
    cin >> n >> m >> k;
    ll dp[n + 1][m + 1];
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= m; ++j)
            dp[i][j] = 0;
    ll x, y;
    for (int i = 0; i < k; ++i){
        cin >> x >> y;
        dp[x][y] = -1;
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i)
        if (dp[i][0] != -1)
            dp[i][0] = dp[i - 1][0] == -1 ? 0 : dp[i - 1][0];
    for (int j = 1; j <= m; ++j)
        if(dp[0][j] != -1)
            dp[0][j] = dp[0][j - 1] == -1 ? 0 : dp[0][j - 1];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (dp[i][j] != -1)
                dp[i][j] = ((dp[i - 1][j] == -1 ? 0 : dp[i - 1][j])
                + (dp[i][j - 1] == -1 ? 0 : dp[i][j - 1]))% MOD;
    cout << dp[n][m];
    return 0;
}
