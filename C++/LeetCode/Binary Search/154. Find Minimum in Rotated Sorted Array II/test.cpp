#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1, med;
        while (l < r){
            if (nums[l] < nums[r]) return nums[l];
            med = (l + r) / 2;
            if (nums[l] == nums[med]) ++l;
            else if (nums[med] > nums[l]) l = med + 1;
            else r = med;
        }
        return nums[l];
    }
};