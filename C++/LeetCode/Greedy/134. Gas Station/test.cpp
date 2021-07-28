#include<bits/stdc++.h>
using namespace std;
unordered_map<int,pair<int,int>> prefix; // for prefix[i] = j, from i to j - 1, the sum is val (>0)
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        for (int i = 0; i < n; ++i)
            gas[i] -= cost[i];
        for (int i = 0; i < n; ++i){
            int sum = 0, drive = 0;
            for (int j = i;;){
                if (drive >= n) return i;
                if (prefix.find(j) != prefix.end()){
                    sum += prefix[j].second;
                    drive += prefix[j].first - j + 1;
                    j = prefix[j].first + 1;
                    j = j == n ? 0 : j;
                }
                else {
                    sum += gas[j];
                    if (sum >= 0) {drive++; j = j == n - 1 ? 0 : j + 1; continue;}
                    else{
                        if (drive) prefix[i] = {j, sum - gas[j]};
                        break;
                    }
                }

            }
        }
        return -1;
    }
};