#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
      int cont = 0;
      int candidate = 0;
      for (int i = 0; i < nums.size(); i++){
        if (cont == 0)
          candidate = nums[i];
          cont += candidate == nums[i] ? 1 : -1;
      }
      return candidate;
    }
};//by Discussion


class Solution1 {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        else{
          int len1 = nums.size() / 2;
          vector<int> nums1(nums.begin(), nums.begin() + len1);
          vector<int> nums2(nums.begin() + len1, nums.end());
          int temp1 = majorityElement(nums1);
          int temp2 = majorityElement(nums2);
          int cont = 0;
          for (int i = 0; i < nums.size(); i++)
            if (nums[i] == temp1) cont++;
          return cont > len1 ? temp1 : temp2;
        }
    }
};//by myself

int main()
{
  vector<int> v1 = {3, 3, 4};
  Solution s1;
  cout << s1.majorityElement(v1);
}