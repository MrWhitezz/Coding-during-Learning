#include<bits/stdc++.h>
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int dp[nums.size()];
        int Max = dp[0] = nums[0];
        for (int i = 0; i < nums.size() - 1; i++){
            dp[i + 1] = nums[i + 1] + (dp[i] > 0 ? dp[i] : 0);
            Max = max(Max, dp[i + 1]);
        }
        return Max;
    }
};