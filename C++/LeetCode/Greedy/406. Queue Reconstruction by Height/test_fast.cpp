// fast as O(nlgn)
//https://leetcode.com/problems/queue-reconstruction-by-height/discuss/427157/Three-different-C%2B%2B-solutions.-from-O(n2)-to-O(nlogn).-faster-than-99.
// I have an idea with BST(set), failed
// This mergeSort idea deserve observation
// https://leetcode.com/problems/queue-reconstruction-by-height/discuss/143403/O(nlogn)-modified-merge-sort-solution-with-detailed-explanation
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](vector<int> &p1, vector<int> &p2){
            return p1[0] < p2[0] || (p1[0] == p2[0] && p1[1] > p2[1]);
        });
        vector<int> ans(people.size());
        set<int> BST;
        for (int i = 0; i < people.size(); ++i)
            BST.insert(i);
        
        }
    }
};