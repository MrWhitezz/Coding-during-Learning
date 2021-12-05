#include<iostream>
using namespace std;
int main()
{
    int N, C;
    cin >> N >> C;
    int Q[N], W[N], P[N];
    for (int i = 0; i < N; i++)
        cin >> Q[i];
    for (int i = 0; i < N; i++)
        cin >> W[i];
    for (int i = 0; i < N; i++)
        cin >> P[i];
    int dp[N + 1][C + 1];
    int dpF[N + 1][C + 1];
    for (int i = 0; i <= N; i++)
        dp[i][0] = dpF[i][0] = 0;
    for (int i = 0; i <= C; i++)
        dp[0][i] = dpF[0][i] = 0;


    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            int tempMax = dp[i - 1][j];
            int mMax = 0;
            for (int M = 0; M <= Q[i - 1] && j - M * W[i - 1] >= 0; M++)
            {
                if(tempMax < dp[i - 1][j - M * W[i - 1]] + M * P[i - 1])
                {
                    tempMax = dp[i - 1][j - M * W[i - 1]] + M * P[i - 1];
                    mMax = M;
                }
            }
            dpF[i][j] = mMax;
            dp[i][j] = tempMax;
        }
    }

    int pack = C;
    int F[N];
    F[N - 1] = dpF[N][C];
    for (int i = N - 1; i >= 1; i--)
    {
        F[i - 1] = dpF[i][pack - dpF[i + 1][pack] * W[i]];
        pack = pack - dpF[i + 1][pack] * W[i];
    }

    for (int i = 0; i < N; i++)
        cout << F[i] << " ";
    cout << endl << dp[N][C];




    return 0;
}
