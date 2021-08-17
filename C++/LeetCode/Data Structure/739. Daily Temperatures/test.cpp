// It is useful to use a descending list
// Deserve rethinking
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> downlist;
        vector<int> ans(temperatures.size());
        for (int i = 0; i < temperatures.size(); ++i){
            while (!downlist.empty()){
                if (temperatures[i] <= temperatures[downlist.top()]){
                        break;
                }
                else{
                    ans[downlist.top()] = i - downlist.top();
                    downlist.pop();
                }   
            }
            downlist.push(i);
        }
        return ans;
    }
};