#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return findKthSmallestinAnyArray(nums, 0, nums.size() - 1, nums.size() - k + 1);
    }
    int findKthSmallestinAnyArray(vector<int>& nums, int l, int r, int k){
        if (r - l <= 60){
            sort(nums.begin() + l, nums.begin() + r + 1);
            return nums[l + k - 1];
        }
        srand((unsigned)time(NULL));
        int p = rand() % (r - l + 1) + l;
        swap(nums[p], nums[r]);
        p = partition(nums, l, r);
        if (k == p - l + 1) return nums[p];
        else if (k < (p - l + 1)) return findKthSmallestinAnyArray(nums, l, p - 1, k);
        else return findKthSmallestinAnyArray(nums, p + 1, r, k - (p - l + 1));
    }
    int partition(vector<int>& nums, int l, int r){
        int i = l - 1, j = l;
        while (j != r){
            if (nums[j] < nums[r]){
                swap(nums[j], nums[++i]);
            }
            ++j;
        }
        swap(nums[++i], nums[r]);
        return i;
    }
};