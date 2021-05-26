#include<bits/stdc++.h>
using namespace std;
int T, n, m;
bool checkWater();
int main()
{
    cin >> T;
    for (int i = 0; i < T; ++i)
        cout << checkWater() << endl;

    return 0;
}
bool checkWater(){
    cin >> n >> m;
    bool dp[n + 1][m + 1];
    int wt[n];
    for (int i = 0; i < n; ++i)
        cin >> wt[i];
    for (int i = 0; i <= n; ++i)
        dp[i][0] = 1;
    for (int i = 1; i <= m; ++i)
        dp[0][i] = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            dp[i][j] = wt[i - 1] > j ? dp[i - 1][j] : dp[i - 1][j] + dp[i - 1][j - wt[i - 1]];
    return dp[n][m];
}