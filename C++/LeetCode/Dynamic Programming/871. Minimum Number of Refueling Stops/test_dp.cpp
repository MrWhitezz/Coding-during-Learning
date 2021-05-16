//using dp to tackle, time is O(n^2)
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        long long dp[n + 1];// for the first i stations
                      // dp[t] means using t times of refuel, the farthest distance
        for (int i = 0; i < n + 1; ++i)
            dp[i] = startFuel;
        for (int i = 0; i < n; ++i){
            for (int t = i + 1; t >= 1 && dp[t - 1] >= stations[i][0]; --t)
                dp[t] = max(dp[t], dp[t - 1] + stations[i][1]);
        }
        for (int i = 0; i <= n; ++i)
            if (dp[i] >= target) return i;
        return -1;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> tmp = {{10, 100}};
    cout << sol.minRefuelStops(100, 1, tmp);
    return 0;
}