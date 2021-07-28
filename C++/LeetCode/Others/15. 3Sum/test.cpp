//The Standard is similar to my idea?
// Bad code
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        auto beg = nums.begin();
        if (nums.size() < 3 || nums[nums.size() - 1] < 0 || nums[0] > 0) return res;
        if (*nums.begin() == 0) {
            if (*(beg + 1) == 0 && *(beg + 2) == 0) res.push_back({0, 0, 0});
            return res;
        }
        //find i, j, k in order, namely,a[i] <= a[j] <= a[k]
        for (int i = 0; i < nums.size(); ++i){
            if (nums[i] > 0) break;
            int j = i + 1, k = nums.size() - 1;
            while (k - j > 0){
                if (nums[j] + nums[k] == -nums[i]) {
                    res.push_back({nums[i], nums[j], nums[k]});
                    ++j;
                }
                else if (nums[j] + nums[k] > -nums[i]) --k;
                else ++j;
            }
        }
        sort(res.begin(), res.end());
        auto it = unique(res.begin(), res.end());
        res.resize(distance(res.begin(), it));
        return res;
    }
};