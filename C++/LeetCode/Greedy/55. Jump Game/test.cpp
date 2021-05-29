#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reach = 0, tmp = nums[0], tmpp = tmp;
        if (nums.size() == 1) return true;
        while (tmp){
            if (reach + tmp >= nums.size() - 1) return true;
            tmpp = nums[reach + tmp];
            for (int i = 1; i < tmp; ++i)
                tmpp = max(tmpp, nums[reach + i] - (tmp - i));
            reach += tmp;
            tmp = tmpp;
        }
        return false;
    }
};