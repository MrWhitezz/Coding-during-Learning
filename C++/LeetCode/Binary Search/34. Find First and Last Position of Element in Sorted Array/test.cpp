#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return {-1, -1};
        int l = 0, ll = nums.size() - 1, rr = 0, r = nums.size() - 1, med;
        while(l < ll){
            med = (l + ll) / 2;
            if (nums[med] < target) l = med + 1;
            else ll = med;
        }// get l == ll as the fir elem >= target
        if (nums[l] != target) return {-1, -1};
        rr = l;
        while (rr < r){
            med = (rr + r) / 2;
            if (nums[med] <= target) rr = med + 1;
            else r = med;
        }// get r == rr as the fir elem > target, cannot be 0 because it must exist
        if (nums[r] == target) return {l, r};
        else return {l , r - 1};

    }
};