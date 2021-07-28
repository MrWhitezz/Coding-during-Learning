#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, med;
        while (l < r){
            med = (l + r) / 2;
            // normal increasing
            if (nums[l] == target || nums[med] == target) return true;
            if (nums[l] < nums[r]){
                if (nums[med] < target) l = med + 1;
                else r = med; 
            }
            // avoid trivial but annongying case
            else if (nums[l] == nums[med]) ++l;
            // else 2 parts
            else if (target > nums[l]){
                if (nums[med] >= nums[l]){
                    if (nums[med] < target) l = med + 1;
                    else r = med;
                }
                else r = med;
            }
            else{
                if (nums[med] <= nums[l] && nums[med] >= target) r = med;
                else l = med + 1;
            }
        }
        return nums[l] == target;
    }
};