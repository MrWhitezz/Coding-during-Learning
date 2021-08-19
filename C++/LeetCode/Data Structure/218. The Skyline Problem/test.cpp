// Learning from https://briangordon.github.io/2014/08/the-skyline-problem.html
// Well, really slow code by myself
// fortunately bug-free
#include<bits/stdc++.h>
using namespace std;
struct cmp
{
    bool operator()(vector<int>& build1, vector<int> build2){
        return build1[2] < build2[2];
    }
};

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> critical_points(2 * buildings.size());// {x_pos, height}

        for (int i = 0; i < buildings.size(); ++i){
            critical_points[2 * i] = {buildings[i][0], buildings[i][2]};
            critical_points[2 * i + 1] = {buildings[i][1], 0};
        }
        sort(critical_points.begin(), critical_points.end());

        priority_queue<vector<int>, vector<vector<int>>, cmp> active_buildings;
        int cur_build = 0;
        for (int i = 0; i < critical_points.size(); ++i){
            while (cur_build < buildings.size() && critical_points[i].first == buildings[cur_build][0]){
                active_buildings.push(buildings[cur_build]);
                cur_build++;
            }

            while(!active_buildings.empty()){
                if (critical_points[i].first >= active_buildings.top()[1]) // encounter right side
                    active_buildings.pop();
                else
                    break;
            }
            if (!active_buildings.empty())
                critical_points[i].second = max(critical_points[i].second, active_buildings.top()[2]);
        }
        vector<vector<int>> ans;
        ans.push_back({critical_points[0].first, critical_points[0].second});
        for (int i = 1; i < critical_points.size(); ++i){
            if (critical_points[i].second == critical_points[i - 1].second)
                continue;
            else
                ans.push_back({critical_points[i].first, critical_points[i].second});
        }
        return ans;
    }
};