#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int dest = nums.size() - 1;
        int maxJump = nums[0];
        for (int i = 0; i <= maxJump; ++i){
            maxJump = max(maxJump, i + nums[i]);
            if (maxJump >= dest) return true;
        }
        return false;
    }
};