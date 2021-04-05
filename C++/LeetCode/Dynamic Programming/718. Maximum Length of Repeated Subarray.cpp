#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
   int findLength(vector<int>& A, vector<int>& B) {
      unsigned m = A.size(), n = B.size();
      int dp[m][n];
      for (int i = n - 1; i >= 0; --i){
          dp[m - 1][i] = A[m - 1] == B[i] ? 1 : 0;
      }
      for (int i = m - 1; i >= 0; --i){
         dp[i][n - 1] = A[i] == B[n - 1] ? 1 : 0;
      }
      for (int i = m - 2; i >= 0; --i)
      {
         for (int j = n - 2; j >= 0; --j)
         {
            dp[i][j] = A[i] == B[j] ? dp[i + 1][j + 1] + 1 : 0;
         }
      }
      int res = 0;
      for (int i = 0; i < m; ++i)
         for (int j = 0; j < n; ++j)
            res = res > dp[i][j] ? res : dp[i][j];
      return res;
   }
};