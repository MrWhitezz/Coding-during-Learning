#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> slide;
        for (int i = 0; i < k; ++i){
            while (!slide.empty()){
                if (slide.back() < nums[i])
                    slide.pop_back();
                else break;
            }
            slide.push_back(nums[i]);
        }
        vector<int> ans;
        ans.push_back(slide.front());
        for (int i = k; i < nums.size(); ++i){
            if (slide.front() == nums[i - k]) 
                slide.pop_front();
            while (!slide.empty()){
                if (slide.back() < nums[i])
                    slide.pop_back();
                else break;
            }
            slide.push_back(nums[i]);
            ans.push_back(slide.front());
        }
        return ans;
    }
};