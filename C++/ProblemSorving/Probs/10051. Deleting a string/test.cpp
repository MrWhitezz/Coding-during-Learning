#include<bits/stdc++.h>
using namespace std;
string s;
int n;
int main()
{
    cin >> n >> s;
    int dp[n][n];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            dp[i][j] = 1;

    for (int len = 1; len < n; ++len)
        for (int i = 0; i + len < n; ++i){
            int tmpMin = dp[i][i] + dp[i + 1][i + len];
            for (int j = 1; j < len; ++j)
                tmpMin = min(tmpMin, dp[i][i + j] + dp[i + j + 1][i + len]);
            dp[i][i + len] = tmpMin;
            if (s[i] == s[i + len])
                dp[i][i + len] = min(tmpMin, dp[i + 1][i + len - 1]);
        }
    cout << dp[0][n - 1];
    return 0;
}