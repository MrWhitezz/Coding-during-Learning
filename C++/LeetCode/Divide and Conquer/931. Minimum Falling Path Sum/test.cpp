#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 1) return matrix[0][0];
        vector<vector<int>> ans(n, matrix[0]);
        for (int i = 1; i < n; ++i){
            ans[i][0] = matrix[i][0] + min(ans[i - 1][0], ans[i - 1][1]);
            ans[i][n - 1] = matrix[i][n - 1] + min(ans[i - 1][n - 2], ans[i - 1][n - 1]);
            for (int j = 1; j < n - 1; ++j)
                ans[i][j] = matrix[i][j] + min(ans[i - 1][j - 1], min(ans[i - 1][j], ans[i - 1][j + 1]));
        }
        int res = ans[n - 1][0];
        for (int i = 1; i < n; ++i)
            res = min(res, ans[n - 1][i]);
        return res;
    }
};
// by answer
int minFallingPathSum(vector<vector<int>>& A) {
  for (auto i = 1; i < A.size(); ++i)
    for (auto j = 0; j < A.size(); ++j)
      A[i][j] += min({ A[i-1][j], A[i-1][max(0,j-1)], A[i-1][min((int)A.size()-1,j+1)] });
      // reduce the case of j = 0 and j = n - 1!!!
  return *min_element(begin(A[A.size() - 1]), end(A[A.size() - 1]));
}