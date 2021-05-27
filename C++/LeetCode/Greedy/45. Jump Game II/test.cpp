#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int jump(vector<int>& nums) {
        int reach = 0, tmp = nums[0], tmpp = tmp, ans = 0;
        if (nums.size() == 1) return 0;
        while (tmp){
            ++ans;
            if (reach + tmp >= nums.size() - 1) return ans;
            tmpp = nums[reach + tmp];
            for (int i = 1; i < tmp; ++i)
                tmpp = max(tmpp, nums[reach + i] - (tmp - i));
            reach += tmp;
            tmp = tmpp;
        }
        return ans;
    }
};