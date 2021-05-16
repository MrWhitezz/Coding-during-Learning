//It is a hard problem
//So First learn the idea in the discussion
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        int dp[n][n];
        for (int i = 0; i < n; ++i)
            dp[i][i] = dp[i][max(0, i - 1)] = 0;
        for (int l = 2; l <= n; ++l){
            for (int i = 0; i <= n - l; ++i){
                int j = i + l - 1;
                dp[i][j] = s[i] == s[j] ? dp[i + 1][j - 1] : 1 + min(dp[i][j - 1], dp[i + 1][j]);
            }
        }
        return dp[0][n - 1];
    }
};
// The space can be better, but I still cannot make it 