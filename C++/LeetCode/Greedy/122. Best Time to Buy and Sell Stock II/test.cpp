//Easy if there's a limit of atmost one transaction
//If so, we only need to find the maxSum of consecutive subarray, which is trivial O(n) using dp
// And this question is even easier, we only need to greedly choose all the positive val!!!
// because our task is just to choose several non-overlapping consecutive subarray, thus got maxSum
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 1) return 0;
        vector<int> profit(prices.size() - 1);
        for (int i = 1; i < prices.size(); ++i)
            profit[i - 1] = prices[i] - prices[i - 1];
        int ans = 0;
        for (auto it = profit.begin(); it != profit.end(); ++it)
            if (*it > 0) ans += *it;
        return ans;
    }
};