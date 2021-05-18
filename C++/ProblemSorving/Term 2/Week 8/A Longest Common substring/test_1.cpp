//This is right
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string A, B;
    cin >> A >> B;
    int dp[A.size() + 1][B.size() + 1];//dp[i][j] gives longest len which tail A[i], B[j]
    for (int i = 0; i <= A.size(); ++i)
        dp[i][0] = 0;
    for (int j = 0; j <= B.size(); ++j)
        dp[0][j] = 0;
    for (int i = 1; i <= A.size(); ++i)
        for (int j = 1; j <= B.size(); ++j)
            dp[i][j] = A[i - 1] == B[j - 1] ? dp[i - 1][j - 1] + 1 : 0;

    for (int i = 1; i <= A.size(); ++i)
        dp[i][B.size()] = max(*max_element(&dp[i][0], &dp[i][0] + B.size() + 1), dp[i - 1][B.size()]);
    for (int i = 1; i <= A.size(); ++i)
        cout << dp[i][B.size()] << " ";
    return 0;
}