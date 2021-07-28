// This is an interesting problem!!! I cannot solve it by myself.
// 1.Pick out tallest group of people and sort them in a subarray (S). Since there's no other groups of people taller than them, therefore each guy's index will be just as same as his k value.
// 2.For 2nd tallest group (and the rest), insert each one of them into (S) by k value. So on and so forth.
// Time O(n^2) not the best !!!
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](vector<int>& p1, vector<int>& p2){
            return p1[0] > p2[0] || (p1[0] == p2[0] && p1[1] < p2[1]);
        });
        vector<vector<int>> ans;
        for (auto person : people)
            ans.insert(ans.begin() + person[1], person);
        return ans;
    }
};