//very nice idea
//can be improved, that is to jump rather than scan;
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, bool> flag;
        unordered_map<char, int> appearTimes;
        for (auto ch : t){
            flag[ch] = true;
            ++appearTimes[ch];
        }
        int l = 0, min_l = 0, min_size = s.size() + 1, cnt = 0;
        //cnt denote how many chars between l and r matches
        //cnt <= t.size()!!!
        for (int r = 0; r < s.size(); ++r){
            if (flag[s[r]]){
                if (appearTimes[s[r]]-- > 0) ++cnt;
                while (cnt == t.size()){
                    if (r - l + 1 < min_size){
                        min_size = r - l + 1;
                        min_l = l;
                    }
                    if (flag[s[l]] && appearTimes[s[l]]++ == 0) --cnt;
                    ++l;
                }
            }
        }
        return min_size > s.size() ? "" : s.substr(min_l, min_size); 
    }
};