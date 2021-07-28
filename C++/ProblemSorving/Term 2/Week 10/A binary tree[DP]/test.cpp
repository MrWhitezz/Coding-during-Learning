#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n, k;
int main()
{
    cin >> n >> k;
    vector<int> a(n), sum(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a.begin(), a.end());
    int dp[n][n][k + 1];
    sum[0] = a[0];
    for (int i = 1; i < n; ++i)
        sum[i] = sum[i - 1] + a[i];

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            dp[i][j][0] = (i == j) ? 0 : INT_MAX;
    for (int h = 1; h <= k; ++h)
        for (int i = 0; i < n; ++i)
            for (int j = i; j < n; ++j){
                dp[i][j][h] = dp[i][j][h - 1];
                for (int p = i; p <= j - 1; ++p)
                    if (dp[i][p][h - 1] != INT_MAX && dp[p + 1][j][h - 1] != INT_MAX)
                        dp[i][j][h] = min(dp[i][j][h], dp[i][p][h - 1] + dp[p + 1][j][h - 1] + sum[j] - ((i != 0) ? sum[i - 1] : 0));
                //cout << "dp[" << i << "][" << j << "][" << h << "] = " << dp[i][j][h] << "\n";
            }
    cout << dp[0][n - 1][k];
}