#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> H;
        for (auto i : stones)
            H.push(i);
        int x, y;
        while (H.size() > 1){
            x = H.top();
            H.pop();
            y = H.top();
            H.pop();
            if (x != y)
                H.push(x - y);
        }
        if (H.empty()) return 0;
        else return H.top();
    }
};