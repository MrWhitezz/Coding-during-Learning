// very easy; Greedy idea like arranging shows/programs 
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& A, vector<int>& B){return A[1] < B[1];});
        int longest = 0, pos = 0, RightVal = INT_MIN;
        while (pos != intervals.size()){
            if (RightVal <= intervals[pos][0]){
                RightVal = intervals[pos][1];
                ++longest;
            }
            ++pos;
        }
        return intervals.size() - longest;
    }
};