//using sliding window
//as well as the idea of prefix
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int prefix = 0, i = 0, cnt = 0, res = 0;
        vector<int> Map(nums.size() + 1);// show how many times elem appears
        for (int j = 0; j < nums.size(); ++j){
            if (Map[nums[j]]++ == 0) cnt++;
            if (cnt > k)  {Map[nums[i++]] = prefix = 0; --cnt;}
            while (Map[nums[i]] > 1){--Map[nums[i++]]; ++prefix;}
            if (cnt == k) res += 1 + prefix;
        }
        return res;
    }
};
// int main()
// {
//     Solution sol;
//     vector<int> tmp{1, 2, 1, 2, 3};
//     cout << sol.subarraysWithKDistinct(tmp, 2);
//     return 0;
// }