#include<bits/stdc++.h>
using namespace std;
const int ArSize = 3000;
long long dp[ArSize][ArSize];
const long long MOD = 1e9 + 7;
int main()
{
   long long n, m;
   cin >> n >> m;
   for (int i = 1; i < ArSize; i++){
         dp[i][0] = 1;
         dp[i][i] = 1;
   }
      
   for (int i = 2; i < ArSize; i++)
      for (int j = 1; j <= i; j++)
         dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;

   cout << dp[n][m];

   return 0;
}