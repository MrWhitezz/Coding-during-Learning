// Easy Greedy Idea, to scan smooth the vector
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> LastPos;
        for (int i = 0; i < s.size(); ++i)
            LastPos[s[i]] = i;
        int IntervalBeg = 0, IntervalEnd = 0;
        vector<int> ans;
        while (IntervalEnd != s.size() - 1){
            IntervalEnd = LastPos[s[IntervalBeg]];
            int tmpPos = IntervalBeg;
            while (tmpPos != IntervalEnd){
                IntervalEnd = max(IntervalEnd, LastPos[s[tmpPos]]);
                ++tmpPos; 
            }
            ans.push_back(IntervalEnd - IntervalBeg + 1);
            IntervalBeg = IntervalEnd + 1;
        }
        if (s.size() == 1) ans.push_back(1);
        return ans;
    }
};