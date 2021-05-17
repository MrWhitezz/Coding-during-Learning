//This answer is by a genius
//First using sliding window to calculate subarrays with at most K diff integers
//Then f(K) - f(K - 1) finish!
#include<bits/stdc++.h>
using namespace std;
int atMostK(vector<int>& nums, int k){
    if (k == 0) return 0;
    unordered_map<int, int> check;
    int i = 0, res = 0;
    for (int j = 0; j < nums.size(); ++j){
        if (!check[nums[j]]++) k--;
        while (k < 0){
            if (!--check[nums[i]]) ++k;
            ++i;
        }
        res += j - i + 1;
    }
    return res;
}
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
};