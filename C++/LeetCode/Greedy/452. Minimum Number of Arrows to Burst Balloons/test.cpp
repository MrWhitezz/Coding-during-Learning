// very easy greedy idea
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](vector<int> & A, vector<int> & B){return A[1] < B[1];});
        int shots = 0, RightVal = INT_MIN, pos = 0;
        while (pos != points.size()){
            if (RightVal < points[pos][0] || points[pos][0] == INT_MIN){
                RightVal = points[pos][1];
                ++shots;
            }
            ++pos;
        }
        return shots;
    }
};