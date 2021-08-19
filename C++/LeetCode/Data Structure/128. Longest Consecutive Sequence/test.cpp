// an excellent solution using hash table
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> table;
        int len = 0;
        for (auto i : nums){
            if (table[i]) continue; // if i has been seen, jump it
            // to be seen means, containing the len of consecutive slots which have been seen
            len = max(len, table[i] = table[i - table[i - 1]] = table[i + table[i + 1]] = table[i - 1] + table[i + 1] + 1);
            //notice we only need to keep the beg & end of a consecutive list right!


        }
        return len;

    }
};