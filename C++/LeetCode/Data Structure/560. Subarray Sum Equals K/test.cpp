// clever use of hashmap
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int psum = 0, ans = 0;
        unordered_map<int, int> pnumber;
        pnumber[0] = 1;
        for (auto num : nums){
            psum += num;
            ans += pnumber[psum - k];
            ++pnumber[psum];
        }
        return ans;
    }
};