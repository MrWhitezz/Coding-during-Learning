//simply using two pointers
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int pos1 = m - 1, pos2 = n - 1, pos = m + n - 1;
        while (pos1 != -1 && pos2 != -1){
            if (nums1[pos1] <= nums2[pos2])
                nums1[pos--] = nums2[pos2--];
            else nums1[pos--] = nums1[pos1--];
        }
        while (pos2 != -1)
            nums1[pos--] = nums2[pos2--];
        return;
    }
};