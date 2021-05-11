#include<bits/stdc++.h>
using namespace std;
void exchange_pair (vector<int> &v1, vector<int> &v2){
    vector<int> tmp = v1;
    v1 = v2;
    v2 = tmp;
}
int dist (const vector<int> &v){
    return v[0] * v[0] + v[1] * v[1];
}
vector<vector<int>> union_vec(vector<vector<int>> &v1, vector<vector<int>> &v2){
    for (auto it : v2)
        v1.push_back(it);
    return v1;
}
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        srand((unsigned)time(NULL));
        unsigned p = rand() % points.size();
        int pivot = dist(points[p]);
        vector<vector<int>> left, right;
        for (auto it : points){
            if (dist(it) <= pivot)
                left.push_back(it);
            else
                right.push_back(it);
        }
        
        if (k < left.size())
            return kClosest(left, k);
        else if (k == left.size())
            return left;
        else  {
            vector<vector<int>> right_half = kClosest(right, k - left.size());
            return union_vec(left, right_half);
        }
    }
};
void print_ans(vector<vector<int>> &ans){
    for (auto it : ans){
        cout << it[0] << " " << it[1] << endl;
    }
}
int main()
{
    Solution sol;
    vector<vector<int>> Points, ans;
    int m, x, y, k;
    cout << "Enter the numbers of points: ";
    cin >> m;
    for (int i = 0; i < m; ++i){
        cin >> x >> y;
        Points.push_back({x, y});
    }
    cout << "Enter k: ";
    cin >> k;
    ans = sol.kClosest(Points, k);
    print_ans(ans);
    
    return 0;
}