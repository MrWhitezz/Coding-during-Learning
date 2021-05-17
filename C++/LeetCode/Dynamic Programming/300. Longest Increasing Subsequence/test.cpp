#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), size = 0;
        int tails[n];
        memset(tails, 0, n);
        for (auto num : nums){//len size, the prefix num; tails[0...size - 1] is the current smallest tail for len 1...size
            int i = 0, j = size;
            while (i != j){
                int m = (i + j) / 2;    // m < j, m + 1 <= j, So tails[size] can never be compared
                if (num > tails[m]) i = m + 1;
                else j = m;
            }// now i = j is the lowest val >= num, tails[i - 1] < num <= num[i]; tails[-1] = -inf, tails[size] = +inf
            tails[i] = num;
            if (i == size) ++size;
        }
        return size;
    }
};