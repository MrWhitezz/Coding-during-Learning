#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size() - 1, med;
        if (l == r) return nums[0];
        if (nums[0] != nums[1]) return nums[0];
        if (nums[r] != nums[r - 1]) return nums[r];
        while (r >= l + 2){
            med = (l + r) / 2;
            if (nums[med] == nums[med - 1]){
                if ((med - l) & 1) l = med - 1;
                else r = med;
            }
            else if (nums[med] == nums[med + 1]){
                if ((med - l + 1) & 1) l = med;
                else r = med + 1;
            }
            else return nums[med];
        }
        return 0;
    }
};