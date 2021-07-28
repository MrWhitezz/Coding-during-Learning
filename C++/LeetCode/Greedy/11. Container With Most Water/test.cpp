// Something like greedy
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size(), i = 0, j = len - 1, area = (j - i) * min(height[i], height[j]);
        while (j - i > 1){
            if (height[i] < height[j]) ++i;
            else --j;
            area = max(area, (j - i) * min(height[i], height[j]));
        }
        return area;
    }
};