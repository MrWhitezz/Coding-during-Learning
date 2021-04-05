#include <bits/stdc++.h>
using namespace std;
class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        multimap<int, int> num1;
        for (int i = 0; i < nums.size(); i++)
        {
            num1.insert(pair<int, int>(nums[i], i));// fisrt denotes value, second pos
        }
        multimap<int,int> :: iterator it1 = num1.begin(), it2 = num1.end(); it2--;
        vector<int> temp;
        while (it1 != it2)
        {
            if (it1 -> first + it2 -> first > target){
                it2--;
                continue;
            }
            else if(it1 -> first + it2 -> first < target){
                it1++;
                continue;
            }
            else{
                temp.push_back(it1 -> second);
                temp.push_back(it2 -> second);
                break;
            }
        }
        return temp;
    }
};
int main()
{
    return 0;
}