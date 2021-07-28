//Easy problem
//By sorting is interesting
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string fir = *min_element(strs.begin(), strs.end());
        string tail = *max_element(strs.begin(), strs.end());
        int i = 0, len = min(fir.size(), tail.size());
        while (i < len && fir[i] == tail[i]) ++i;
        return string(fir.begin(), fir.begin() + i);
    }
};