#include<bits/stdc++.h>
using namespace std;
unordered_map<int, int> dp;
class Solution {
public:
    int minDays(int n) {
        if (n <= 1)
            return n;
        if(dp.find(n) == dp.end())
            dp[n] = min(n % 2 + minDays(n / 2), n % 3 + minDays(n / 3)) + 1;
            //This Greedy is brilliant!!! (not by myself)
            // When 6(mod 6) not eat 1
            // When 4(mod 6) not eat 2 or 4
            // When 3(mod 6) not eat 3
            // When 2(mod 6) not eat 2 
        return dp[n];
    }
};