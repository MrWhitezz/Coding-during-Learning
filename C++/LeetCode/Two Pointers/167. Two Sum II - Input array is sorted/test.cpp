//Easy
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int fir = 0, sec = numbers.size() - 1;
        while (1){
            if (numbers[fir] + numbers[sec] == target)
                return {fir + 1, sec + 1};
            else if (numbers[fir] + numbers[sec] < target)
                ++fir;
            else --sec;
        }
    }
};