//算法是discussion里学的，模拟得比较丑（也有借鉴的部分
#include <bits/stdc++.h>
using namespace std;
int total, m, n;
double Median(vector<int> &nums1, vector<int> &nums2, int imin, int imax);
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        m = nums1.size();
        n = nums2.size();
        total = m + n;
        if (m > n)
            return Median(nums2, nums1, 0, n);
        else
            return Median(nums1, nums2, 0, m);
    }
};
double Median(vector<int> &nums1, vector<int> &nums2, int imin, int imax)
{
    int i = (imin + imax) / 2;
    int j = (total + 1) / 2 - i;
    if (i < min(m, n) && nums2[j - 1] > nums1[i])
        return Median(nums1, nums2, i + 1, imax);
    else if (i > 0 && nums1[i - 1] > nums2[j])
        return Median(nums1, nums2, imin, i - 1);
    else 
    {
        int max_left, max_right;
        if (i == 0)
            max_left = nums2[j - 1];
        else if (j == 0)
            max_left = nums1[i - 1];
        else
            max_left = max(nums1[i - 1], nums2[j - 1]);
        if (total % 2)
            return max_left;
        else
        {
            if (i == min(m, n))
                max_right = nums2[j];
            else if (j == max(m, n))
                max_right = nums1[i];
            else
                max_right = min(nums1[i], nums2[j]);
            return (max_left + max_right) / 2.0;//保留一位小数
        }
    }
}
int main()
{
    Solution s1;
    vector<int> nums1, nums2;
    nums1 = {1, 3};
    nums2 = {2, 7};
    cout << s1.findMedianSortedArrays(nums1, nums2);
}