// simple searching linearly
// with some greedy idea
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int MAX = -1, ans = 0;
        for (int i = 0; i < arr.size(); ++i){
            MAX = max(MAX, arr[i]);
            if (MAX == i) ++ans;
        }
        return ans;
    }
};