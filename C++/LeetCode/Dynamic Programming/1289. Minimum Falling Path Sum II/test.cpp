#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        int n = arr.size();
        if (n == 1) return arr[0][0];
        for (int i = 1; i < n; ++i){
            auto p = min_element(arr[i - 1].begin(), arr[i - 1].end());
            int pos = p - arr[i - 1].begin();
            for (int j = 0; j < n; ++j)
                if (j != pos) arr[i][j] = arr[i][j] + *p; 
            if (pos == 0) arr[i][pos] += *min_element(p + 1, arr[i - 1].end());
            else if (pos == n - 1) arr[i][pos] += *min_element(arr[i - 1].begin(), p);
            else arr[i][pos] += min(*min_element(arr[i - 1].begin(), p), 
            *min_element(p + 1, arr[i - 1].end()));
        }
        return *min_element(arr[n - 1].begin(), arr[n - 1].end());
    }
};