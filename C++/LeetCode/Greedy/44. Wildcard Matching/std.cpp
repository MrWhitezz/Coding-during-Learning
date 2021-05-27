// This is an elegant solution
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0, j = 0, ss = 0, star = -1;
        p += "E"; // Avoid j getting an overflow
        //ganrantee before i j, all OK
        while (i != s.size()){
            // before i j, OK
            // if match, go bravely
            if (s[i] == p[j] || p[j] == '?'){
                ++i;
                ++j;
            }
            // if * found, suppose we just skip it(not use *), but note it in case we use it later
            // we need only the most recent * as star
            // because if p = xxxx*xxxx*xxx, if before the last * is a match, there is no need to go back 
            // the first *; (check it carefully, it is somewhat greeedy)
            // before ss is OK
            else if (p[j] == '*'){
                star = j++;
                ss = i;
            }
            // if no match, go back to the recent *
            else if (star != -1){
                j = star + 1;
                i = ++ss;
            }
            else return false;
        }
        while (p[j] == '*') ++j;
        return p[j] == 'E';
    }
};