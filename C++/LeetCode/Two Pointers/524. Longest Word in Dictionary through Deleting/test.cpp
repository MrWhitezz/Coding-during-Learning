// I think it has nothing to do with 2 Pointers
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isSubstring(string &s, string &subCandidate){
        int i = 0, j = 0;
        for (; j < subCandidate.size(); ++j){
            while (i != s.size() && s[i] != subCandidate[j]){
                ++i;
            }
            if (i++ == s.size()) return false;
        }
        return true;       
    }
    string findLongestWord(string s, vector<string>& dictionary) {
        int max_len = 0;
        string ans = "";
        for (auto word : dictionary){
            if (word.size() >= max_len && isSubstring(s, word)){
                if (word.size() > max_len){
                    max_len = word.size();
                    ans = word;
                }
                else ans = ans < word ? ans : word;
            }
        }
        return ans;
    }
};