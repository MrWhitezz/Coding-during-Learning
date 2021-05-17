#include<bits/stdc++.h>
using namespace std;
int n, m;
int main()
{
    cin >> n >> m;
    vector<pair<int, int>> Panz(n), Gaz(n);//first cost, second value
    for (int i = 0; i < 4 * n; ++i)
        if (i / n == 0) cin >> Panz[i].first;
        else if (i / n == 1) cin >> Panz[i - n].second;
        else if (i / n == 2) cin >> Gaz[i - 2 * n].first;
        else cin >> Gaz[i - 3 * n].second;
    int dp[n + 1][m + 1];//dp[i][j] gives using j cost, buy from first i items
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= m; ++j)
            dp[i][j] = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j){
            if (j >= Panz[i - 1].first) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - Panz[i - 1].first] + Panz[i - 1].second);
            if (j >= Gaz[i - 1].first) dp[i][j] = max(max(dp[i][j], dp[i - 1][j]), dp[i - 1][j - Gaz[i - 1].first] + Gaz[i - 1].second);
            else dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        }
    cout << dp[n][m];
    return 0;
}