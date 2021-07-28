// Very easy, but need to be careful
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int DecreasePos = -1;
        for (int i = 0; i < nums.size() - 1; ++i)
            if (nums[i + 1] < nums[i]){
                if (DecreasePos != -1) return false;
                else DecreasePos = i;
            }
        if (DecreasePos == 0 || DecreasePos == -1 || DecreasePos == nums.size() - 2) return true;
        else return nums[DecreasePos] <= nums[DecreasePos + 2] || nums[DecreasePos - 1] <= nums[DecreasePos + 1];
    }
};