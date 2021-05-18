#include<bits/stdc++.h>
using namespace std;
int N, K, P;
int main()
{
    cin >> N >> K >> P;
    int dp[N + 1][P + 1], plate[N + 1][K + 1];
    for (int i = 0; i <= N; ++i)
        for (int j = 0; j <= K; ++j)
            plate[i][j] = 0;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= K; ++j){
            cin >> plate[i][j];
            plate[i][j] += plate[i][j - 1];
        }
            
    for (int i = 0; i <= N; ++i)
        for (int j = 0; j <= P; ++j)
            dp[i][j] = 0;

    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= P; ++j){
            for (int k = 0; k <= j && k <= K; ++k)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - k] + plate[i][k]);
        }
    cout << dp[N][P];
    return 0;
}