#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minRefuelStops(int target, int cur, vector<vector<int>>& stations) {
        priority_queue<int> reach;
        int i = 0, res = 0;
        //get into the loop if we cannot reach target using res refuels
        for (; cur < target; ++res){
            //including possible stations
            while (i < stations.size() && cur >= stations[i][0])
                reach.push(stations[i++][1]);
            //if not reach, no stations, we lose
            if (reach.empty()) return -1;
            //get the best fuel and go on
            cur += reach.top(), reach.pop();
        }
        return res;
    }
};