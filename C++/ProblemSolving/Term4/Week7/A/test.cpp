#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define nmax 1005
const ll P = 998244353L;
ll dp[nmax][nmax];
ll a[nmax];
int T, n, k;
int main(){
    cin >> T;
    while (T--)
    {
        cin >> n >> k;
        memset(dp, 0, sizeof(dp));
        memset(a, 0, sizeof(a));
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i){
            for (int j = 0; j <= k; ++j){
                dp[i][j] = dp[i - 1][j];
                if (j >= a[i])
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - a[i]]) % P;
            }
        }
        printf("%lld\n", dp[n][k]);
    }
}