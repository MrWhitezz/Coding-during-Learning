#include<iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int pos;
        for (auto num : nums){
            pos = abs(num) - 1;
            if (nums[pos] > 0) nums[pos] = -nums[pos];
        }
        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i)
            if (nums[i] > 0) ans.push_back(i + 1);
        return ans;
    }
};

int main(){
    return 0;
}

