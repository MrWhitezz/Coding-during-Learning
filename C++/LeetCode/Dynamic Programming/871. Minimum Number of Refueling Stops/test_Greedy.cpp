//using Greedy Plan !!!
//to get the farthest by t times of refuels
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> reach;
        auto it = stations.begin();
        int distance = startFuel, res = 0;
        if (distance >= target) return res;
        while (it != stations.end() && (*it)[0] <= distance){
            reach.push((*it)[1]);
            ++it;
        }
        while(!reach.empty()){
            distance += reach.top();
            reach.pop();
            while (it != stations.end() && (*it)[0] <= distance){
                reach.push((*it)[1]);
                ++it;
            }
            ++res;
            if (distance >= target) return res;
        }
        return -1;
    }
};